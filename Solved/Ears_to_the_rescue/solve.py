import wave
import struct
import math
import re
# https://stackoverflow.com/a/5281240

audible = wave.open('audible.wav', 'r')
length = audible.getnframes()
frequency = audible.getframerate()

waveData = []
for i in range(0, length):
    waveData.append(audible.readframes(1))


position = int(frequency * 0.05)  # start from 0.05 sec
step = int(frequency * 0.1)  # read every 0.1 sec
count = 0

translation = {
    32000: '7',
    24000: '6',
    16200: '5',
    8100: '4',
    0: 0,
    -8100: '3',
    -16200: '2',
    -24000: '1',
    -32000: '0'
}

# extract the value at every 0.1 sec interval
octal = ''
while position < length:
    data = struct.unpack("<h", waveData[position])
    value = int(data[0])

    try:
        octal += translation[value]
    except KeyError:
        print()
        break
    count += 1
    position += step

print(octal)

# convert to ascii string
flag = ''
while len(octal) > 0:

    front = octal[:3]
    leftover = octal[3:]
    value = int(front, 8)

    # if not fitting in ASCII 7 bits,
    # then take 2 chars instead
    if value > 0x7F:
        front = octal[:2]
        leftover = octal[2:]
        value = int(front, 8)

    flag += chr(value)
    octal = leftover

print(flag)
