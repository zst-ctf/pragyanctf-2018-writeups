# Rivest, Shamir and Aldeman’s quest
crypto - 200 points

## Challenge 
> Rivest comes up with an encryption, and Shamir creates a service for decrypting any cipher text encrypted using Rivests’s encryption. Aldeman is asked to decrypt a specific ciphertext, but he is not able to do so directly through Shamir’s service. Help him out.

> The service is running at 128.199.224.175:34000

> The encrypted text is :-

> a0b75ef5dfd9ab0de9aa8c36a9c5aa28a924128a62826740ac3986efac69e2b85fc0df803e80da04c5f803726689e5f3134178de3cb203f6aebca22b376f7205d93a7224aca82cbbdc382200a1749fee095dfebe2aaabf99b622e4343bf5423cf6527433e26273e67d576157bf65a9258f613be9ad88d7b50350a89e676ae462

>Parameters :-

>

> N : 00:b9:61:cd:4d:b6:cc:a2:c5:ec:44:d1:e6:69:e5:
2b:85:05:74:a5:57:5c:09:3a:a7:40:d2:23:a7:b4:
2a:48:ed:3d:47:8a:c3:e9:10:c7:93:d2:9f:da:13:
f2:3c:ec:d0:0b:d0:ac:bd:cd:b7:0a:b1:f6:d5:e9:
82:1b:85:15:3f:39:81:f2:07:cf:5f:a2:0f:cd:f5:
e4:e4:32:b1:d3:fb:b3:b0:12:d7:d2:70:40:0d:5c:
67:c9:9a:ba:eb:2f:f3:c0:8e:5b:29:c8:07:b1:24:
3a:29:73:87:ff:06:44:3c:09:77:db:f2:f2:84:a9:
48:d4:5c:16:96:eb:a4:59:bf

> 

>e : 65537


## Hint
> Hint! Here is an example encryption :-


>For m = 17 (integer), the encryption c = Enc(m) would be as follows :-

>Integer :-

> 1135313888561729073213055678884572816699034138956362159587056821428036375159777212072
5436988986341387306079511224607415371455357387825108282422079151911468807886017426869
6096857915990814056511351498985054746953628660269153604131959421016678177032253587129
039122137054829046267874924979660429722673243620432019


>Hex (Little Endian) :- 

> 93d8c080cecba3b42e615118cb4598b39a76f74053ae23cb1e286eb397c6ba9c2b60e7217b9c30a9c8a83ab
ecf545df0647d17e9a5653e1b87b25efb49b7c6d2acce872aa8693673fb887a4d0d4505081946dfe32d320a2f
03e71f8d6c767ea9ab9efc9bc6e74aba5c4916043f6e697da12282762bb1f7b4b20c884e7a8faca1

>You can use Python 3's from_bytes and to_bytes functions for integers to perform the encodings.

## Solution

RSA stands for (Rivest–Shamir–Adleman) which is the name of the challenge. Hence, this is an RSA challenge

	c = m^e (mod n)
	m = c^d (mod n)

Since we can input the ciphertext, this is a Chosen Ciphertext Attack (CCA).

References:
- http://seclist.us/attacks-against-plain-rsa-when-rsa-does-not-padding-and-it-is-able-to-send-arbitrary-cipher-for-server-to-decrypt.html
- https://crypto.stackexchange.com/questions/2323/how-does-a-chosen-plaintext-attack-on-rsa-work
- https://security.stackexchange.com/questions/49047/is-the-standard-scheme-of-rsa-cca-and-cpa-secure

#### Theory

[Source:](https://security.stackexchange.com/questions/49047/is-the-standard-scheme-of-rsa-cca-and-cpa-secure)

	(mm')^e = (m^e)(m'^e) mod n

	In other words, the encryption of a product is the product of the encryptions. In the CCA setup:

		1) There is a message m and its ciphertext c = m^e mod n. Attacker knows c and wants to find m.
		2) Attacker is allowed to obtain the decryption of ciphertexts that he chooses, as long as none of them is equal to c.
		3) Attacker generates a random m' (modulo n) and computes c' = m'^e mod n.
		4) Attacker asks for the decryption of cc' mod n: this is an integer modulo n, distinct from c, so the attacker gets a response.
		5) The response is necessarily equals to mm' mod n. Attacker knows m' (he chose it himself) so he computed m easily.


#### Step 1
	
From the hint (which was released after a day), it says the byte order is little endian. We need to take that into account.

	>>> numb = 0x93d8c080cecba3b42e615118cb4598b39a76f74053ae23cb1e286eb397c6ba9c2b60e7217b9c30a9c8a83abecf545df0647d17e9a5653e1b87b25efb49b7c6d2acce872aa8693673fb887a4d0d4505081946dfe32d320a2f03e71f8d6c767ea9ab9efc9bc6e74aba5c4916043f6e697da12282762bb1f7b4b20c884e7a8faca1
	>>> int.from_bytes(numb.to_bytes(128, byteorder='big'), byteorder='little')
	113531388856172907321305567888457281669903413895636215958705682142803637515977721207254369889863413873060795112246074153714553573878251082824220791519114688078860174268696096857915990814056511351498985054746953628660269153604131959421016678177032253587129039122137054829046267874924979660429722673243620432019


We need to find `m`. We have the following:

	c = 0x62e46a679ea85003b5d788ade93b618f25a965bf5761577de67362e2337452f63c42f53b34e422b699bfaa2abefe5d09ee9f74a1002238dcbb2ca8ac24723ad905726f372ba2bcaef603b23cde784113f3e589667203f8c504da803e80dfc05fb8e269acef8639ac406782628a1224a928aac5a9368caae90dabd9dff55eb7a0
	(after little endian conversion)

	e = 65537

	N = 0x00b961cd4db6cca2c5ec44d1e669e52b850574a5575c093aa740d223a7b42a48ed3d478ac3e910c793d29fda13f23cecd00bd0acbdcdb70ab1f6d5e9821b85153f3981f207cf5fa20fcdf5e4e432b1d3fbb3b012d7d270400d5c67c99abaeb2ff3c08e5b29c807b1243a297387ff06443c0977dbf2f284a948d45c1696eba459bf

#### Step 2 & 3

Generate a random `m'` and compute `c'`.

I'll choose 2 for simplicity

	m' = 2
	c' = 2^e mod n
	c' = 0xae69d414693a5f7d819184454827f280e005916474db644cf21610ded847ea935ed8d24cdef473c84c2ea454399ed3af074bd92352d0d0b70f14808e6565fbe3634e451eabeed53b2d7822a105e935a3652b51e7b448531e3128a5c00af1e4bd0399386556850d02ad544a41a625ac3013381fddc17d8fa8955e3da035e9fe4b

	In little endian:
	4bfee935a03d5e95a88f7dc1dd1f381330ac25a6414a54ad020d855665389903bde4f10ac0a528311e5348b4e7512b65a335e905a122782d3bd5eeab1e454e63e3fb65658e80140fb7d0d05223d94b07afd39e3954a42e4cc873f4de4cd2d85e93ea47d8de1016f24c64db74649105e080f22748458491817d5f3a6914d469ae

Testing in the server

	~ $ nc 128.199.224.175 34000
	Enter encrypted message (in HEX) :- 4bfee935a03d5e95a88f7dc1dd1f381330ac25a6414a54ad020d855665389903bde4f10ac0a528311e5348b4e7512b65a335e905a122782d3bd5eeab1e454e63e3fb65658e80140fb7d0d05223d94b07afd39e3954a42e4cc873f4de4cd2d85e93ea47d8de1016f24c64db74649105e080f22748458491817d5f3a6914d469ae

	Decrypted message :- 
	In HEX :- 
	0200000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000


#### Step 4

Calculate cc' mod n

	cprime = 0xae69d414693a5f7d819184454827f280e005916474db644cf21610ded847ea935ed8d24cdef473c84c2ea454399ed3af074bd92352d0d0b70f14808e6565fbe3634e451eabeed53b2d7822a105e935a3652b51e7b448531e3128a5c00af1e4bd0399386556850d02ad544a41a625ac3013381fddc17d8fa8955e3da035e9fe4b
	c = 0x62e46a679ea85003b5d788ade93b618f25a965bf5761577de67362e2337452f63c42f53b34e422b699bfaa2abefe5d09ee9f74a1002238dcbb2ca8ac24723ad905726f372ba2bcaef603b23cde784113f3e589667203f8c504da803e80dfc05fb8e269acef8639ac406782628a1224a928aac5a9368caae90dabd9dff55eb7a0

	>>> import gmpy2
	>>> c = gmpy2.mpz(c)

	>>> (c*cprime) % N
	mpz(59446459779891067464482545942454623181807180672447338630957568497634623454788305568032447390655093657848812997525352193594343607228864558554569018620021776276902751491108621329150825088903507309537266968666420621569262157264234650579426980210499607664422422712209488131593866677924482084127098641410171042193)

	# Alternatively,
	>>> payload = ( c * (2**65537) ) % n
	>>> hex(payload)
	'0x54a791d0ee77984f1d41c1816ecab2c2792f1f0b4594b4e098e3c89673d5e8f9b24187362877002f9d36d03e5ca8db7849ea2ade33cd8396dd4a9f3bd1a5d1e06ffc7ac07fa9603e7f3a146587be6b419d318b3d2cf50e17eaeeb6f848f23d72bbe6c4e8432f157b16d31f87289724b826128b7d1c619ae81b9fe901de7f7991'

Take into account little endian input
	
	0x91797fde01e99f1be89a611c7d8b1226b8249728871fd3167b152f43e8c4e6bb723df248f8b6eeea170ef52c3d8b319d416bbe8765143a7f3e60a97fc07afc6fe0d1a5d13b9f4add9683cd33de2aea4978dba85c3ed0369d2f007728368741b2f9e8d57396c8e398e0b494450b1f2f79c2b2ca6e81c1411d4f9877eed091a754

Input to server

	$ nc 128.199.224.175 34000
	Enter encrypted message (in HEX) :- 91797fde01e99f1be89a611c7d8b1226b8249728871fd3167b152f43e8c4e6bb723df248f8b6eeea170ef52c3d8b319d416bbe8765143a7f3e60a97fc07afc6fe0d1a5d13b9f4add9683cd33de2aea4978dba85c3ed0369d2f007728368741b2f9e8d57396c8e398e0b494450b1f2f79c2b2ca6e81c1411d4f9877eed091a754

	Decrypted message :- 
	In HEX :- 
	e0c6e8ccf66266f0e8c4609ed6bca4e66856d2e6c0ecaad8dc66e468c462ca58e06888fcd262fa0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

#### Step 5

response is mm' mod n:

	response = 0xfa62d2fc8868e058ca62c468e466dcd8aaecc0e6d25668e6a4bcd69e60c4e8f06662f6cce8c6e0

Thus, m mod n is simply divide by `m' = 2`

	>>> mprime = 2
	>>> (response//mprime).to_bytes(128, byteorder='little')
	b'pctf{13xtb0Ok^Rs4+is`vUln3r4b1e,p4D~i1}\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'

## Flag

	pctf{13xtb0Ok^Rs4+is`vUln3r4b1e,p4D~i1}