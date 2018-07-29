#!/usr/bin/env python3

from Crypto import Random
from Crypto.Random import random
from Crypto.Cipher import AES
from base64 import b64decode
import hashlib

# ciphertext
with open('superheroes_group_info_crypt.txt', 'r') as f:
    message = f.read()
message = b64decode(message.strip())

# The key for the second decryption is the MD5 hash of the first result.
with open('./output/key.txt', 'rb') as f1:
    key = f1.read().strip()
key = hashlib.md5(key).hexdigest()

# (IV:12345)
IV = '12345'
aes = AES.new(key, AES.MODE_ECB, IV)
print(aes.decrypt(message))
