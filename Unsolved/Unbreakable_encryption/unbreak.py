#!/usr/bin/env python3
from Crypto import Random
from Crypto.Random import random
from Crypto.Cipher import AES
from binascii import *


IV = open('iv.aes').read().strip()
key = open('key.aes').read().strip()

IV = 'A'*16
# Pad m using PKCS#7 
BLOCK_SIZE = 16
def pad(m):
    p = BLOCK_SIZE - len(m) % BLOCK_SIZE
    return m + p * bytes([p])

def encrypt(key, IV, message, mode=AES.MODE_CBC):
    print(hexlify(message.encode()))
    aes = AES.new(key, mode, IV)
    return aes.encrypt(message)

def decrypt(key, IV, message, mode=AES.MODE_CBC):
    aes = AES.new(key, mode, IV)
    return aes.decrypt(message)

#dec = '71 45 13 cc 22 6f 4d a3 49 2a 8f 22 8b 08 59 b2'.replace(' ', '')
#dec = bytes.fromhex(dec)

#print(decrypt(key, IV, dec))
#quit()
def padZero(i):
    while len(i) % 16 != 0:
        i += '\x00'
    return i

msg = b'a'
msg = IV[0:15].encode()
enc = encrypt(key, IV, pad(msg).decode())

print( hexlify(enc) )

