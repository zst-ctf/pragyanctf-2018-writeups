# Improper encryption
crypto - 100 points

## Challenge 
> Two brothers, Shivam and Mit were fighting for the only computer they had in their house. Watching this their father got angry and locked the computer with a strong password of length 28 which consists of alphabets. To unite them he gave them a puzzle to solve.

>He used two random strings and added the half-half of password in each string at some random position. He wanted to apply one-time-pad on both strings . So he used a smaller key 'k' of length 14(contains only english alphabets), and used some pseudo random generator, to get a longer key(K) of suitable size. Then he XOR each string with the generated key(K),and get encrypted message M1, and M2. He gave Shivam M1 and Mit M2 and asked them to find the password.

>Also, to help them he also generated a string of suitable size by repeating k several times and then applied one time pad on it by larger key(K) to get M3.

>Shivam and Mit come to you with M1, M2, and M3. Help them find the password.

>M1=2d142303073d05392c3d3e273c2a1a211f082b280d2d0e332025380301352a122a151c3a342e362d2723171904011c0c0c292b3d0122063e2e1e2a08102a2d3d0b2e102123141c280f0c373d2b380d3d0301301f2d281935233239330f3a102b123b0d2a

>M2=29190f1b18390707093a290b2d0b113f37332533333a0c3d1a29160a2f100a1d0034323b1b2e1225252500182531391d13260c21211019242d0a0a123b362d232d3a3a0a083c0e363c183a032b332d252c5637252d047b522a1e462a2a2909081705033d

>M3=15350a23053f04272a2f12113a2137202a3022081616090c32162b0b32333413161725072508391f3c36192e1e1e37030b361a2a26163337130628020b34352d1a2e143d3f0a1b1d13012a19223c2b1f0c172b3406033808061d1a2306133011080e1839

>First 14 letter of password is: sAldnJfpUGlciN


## Solution

strong password of length 28 which consists of alphabets

same one-time-pad on both strings

crib dragging

M1 & M2

	python cribdrag.py 040d2c181f04023e2507172c11210b1e283b0e1b3e17020e3a0c2e092e25200f2a212e012f00240802061701213025111f0f271c20321f1a0314201a2b1c001e26142a2b2b28121e33140d3e000b20182f57073a002c6267092c7f1925131923053e0e17

	Enter the correct position, 'none' for no match, or 'end' to quit: 70
	Is this crib part of the message or key? Please enter 'message' or 'key': message
	Your message is currently:
	0	________________________________________
	40	______________________________sAldnJfpUG
	80	lciN________________
	Your key is currently:
	0	________________________________________
	40	______________________________a__pctf{u_
	80	C4nt________________
	Please enter your crib: 

M2 & M3

	python cribdrag.py 3c2c05381d06032023153b1a172a261f1d03073b252c0531283f3d011d233e0e1623173c3e262b3a191319363b2f0e1e1810160b07062a133e0c22103002180e37142e373736152b2f19101a090f063a20411c112b07435a2c035c092c3a39191f0b1b04
	
	Your message is currently:
	0	________________________________________
	40	______________________________ttpisnotse
	80	cure________________
	Your key is currently:
	0	________________________________________
	40	______________________________a__pctf{u_
	80	C4nt________________


M1 & M3

	python cribdrag.py 382129200202011e06122c36060b2d01353809201b3b073f1233130833061e013c02393d11260f321b150e371a1f2b0f071f3117273435093d18020a1b1e18101100041c1c1e07351c0d1d24090426220f161b2b2b2b213d252f23100929203a1a351513

	Is this crib part of the message or key? Please enter 'message' or 'key': key
	Your message is currently:
	0	________________________________________
	40	_____________________________vsAldnJfpUG
	80	lciN________________
	Your key is currently:
	0	________________________________________
	40	_____________________________httpisnotse
	80	cure________________
	Please enter your crib: 


## Flag

	??