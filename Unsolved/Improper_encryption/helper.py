import string

crypt = '040d2c181f04023e2507172c11210b1e283b0e1b3e17020e3a0c2e092e25200f2a212e012f00240802061701213025111f0f271c20321f1a0314201a2b1c001e26142a2b2b28121e33140d3e000b20182f57073a002c6267092c7f1925131923053e0e17'
crypt = crypt.decode('hex')

offset = 70
orig_key = 'sAldnJfpUGlciN'

for l in string.letters:
	key = 'x' * 70 + orig_key + '_' +l
	decoded = ''
	for i in range(len(crypt)):
	    decoded += chr(ord(key[i % len(key)]) ^ ord(crypt[i]))
	print l, decoded

'''
for l in range(14, 100):
	key = orig_key
	key +=  ' ' * (l - len(key))
	decoded = ''
	for i in range(len(crypt)):
	    decoded += chr(ord(key[i % len(key)]) ^ ord(crypt[i]))
	print l, decoded
'''