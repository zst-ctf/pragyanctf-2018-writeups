import Crypto
from Crypto.PublicKey import RSA
from Crypto import Random

# Define initial variables

c = 0xa0b75ef5dfd9ab0de9aa8c36a9c5aa28a924128a62826740ac3986efac69e2b85fc0df803e80da04c5f803726689e5f3134178de3cb203f6aebca22b376f7205d93a7224aca82cbbdc382200a1749fee095dfebe2aaabf99b622e4343bf5423cf6527433e26273e67d576157bf65a9258f613be9ad88d7b50350a89e676ae462
e = 65537
N = 0x00b961cd4db6cca2c5ec44d1e669e52b850574a5575c093aa740d223a7b42a48ed3d478ac3e910c793d29fda13f23cecd00bd0acbdcdb70ab1f6d5e9821b85153f3981f207cf5fa20fcdf5e4e432b1d3fbb3b012d7d270400d5c67c99abaeb2ff3c08e5b29c807b1243a297387ff06443c0977dbf2f284a948d45c1696eba459bf
#publickey.n = N
#publickey.e = e

key = RSA.construct((N, e))
publickey = key.publickey()


encrypted = publickey.encrypt(int('0x' + "1" + '0'*255, 16), 32)
c = encrypted[0]
print(hex(c))
