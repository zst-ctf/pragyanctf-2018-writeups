# Unbreakable encryption
binary - 350 points

## Challenge 

Your friend, Liara, has encrypted all her life secrets, using the one of the best encryptions available in the world, the AES. She has challenged you that no matter what, you can never read her life secrets.

The encryption service is running at :- 128.199.224.175:33000

Her encrypted life secrets are as follows :-

	0000 - 40 87 68 1a b0 23 73 c4 61 44 b4 c0 21 f1 63 0b @.h..#s.aD..!.c.
	0010 - 73 e9 0d 38 e4 bd d8 33 41 64 2c 43 85 d4 54 0e s..8...3Ad,C..T.
	0020 - f5 bc 8c 02 db ee 0d e8 d6 29 81 3a 5f cb 63 bd .........).:_.c.


 aes_enc  8c7abd94d06bb416b5ad807e1609ab99
 key.aes  05bef2d3b8cf320bccd862f248a29b12
 iv.aes  876d08404919ee5bd4e57bf726f41bb4

## Hint
> 

## Solution

Decompile

	if (EVP_EncryptInit_ex(var_154, EVP_aes_256_cbc(), 0x0, &var_134, &var_148) != 0x1) {
		handleErrors();
	}

https://wiki.openssl.org/index.php/EVP_Symmetric_Encryption_and_Decryption
https://robertheaton.com/2013/07/29/padding-oracle-attack/

	# ./aes_enc 
	Enter message :- a

	Your message is :- 
	a


	 The encrypted message for the given plaintext is :- 
	0000 - e3 ba 82 e1 a4 e7 71 94-39 16 fa 81 38 e9 d4 6e   ......q.9...8..n

	Decrypted text is:
	a


## Flag

	??