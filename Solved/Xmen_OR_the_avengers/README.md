# Xmen OR the avengers
crypto - 100 points

## Challenge 
> the legion of doom is expecting an impending attack from a group of superheroes. they are not sure if it is the Xmen OR the avengers. they have received some information from a spy, a zip file containing the following files:

> [info_crypt.txt](info_crypt.txt)

>[info_clear.txt](info_clear.txt)

>[superheroes_group_info_crypt.txt](superheroes_group_info_crypt.txt)

>help the legion of doom in decrypting the last file so they can prepare themselves and prevent their impending doom.


## Hint
> Hint! Note: The key for the second decryption is the MD5 hash of the first result.

## Solution

#### 1st decryption: XOR

From the name, the capital letters say XOR. 

- `info_clear.txt` must be the plain/clear text
- `info_crypt.txt` must be the ciphertext
- `info_clear.txt` and `info_crypt.txt` are exactly the same in length. 

Let's XOR them to get back the key

	$ wget https://raw.githubusercontent.com/ITAYC0HEN/XOR-Files/master/xor.py
	$ python xor.py ../info_crypt.txt ../info_clear.txt key.txt

We get this in `key.txt`:

	 i am a hydra agenT, coverly spying on the superHeroes. I am aware of the group that iS going to aTtack you...but Hydra has had its diffErences with you in the past, so i'm not going to maKe it vEry simple for You ....ecb...aes(I Vouch for this: 12345)...md5(this)...base64...

#### 2nd decryption: AES

Reading `key.txt`, we must do AES-ECB decrypt

Taking all the capital letters, and numbers and brackets...
	
	THISTHEKEY(IV:12345)5()64

Hence, after some trial and error... I found out that:

- AES decryption with
	- Key of `md5(this)` or `md5(key.txt)` [From the hint, key is the MD5 of the first result]
	- IV of `12345`
	- Ciphertext is base64 decode of `superheroes_group_info_crypt.txt`


	$ python3 solve.py 
	b"pctf{it's_the_justice_league_DC_for_life_hellya}"


## Flag

	pctf{it's_the_justice_league_DC_for_life_hellya}