# Assemble your way to the flag
reverse - 50 points

## Challenge 
> My friend was trying out assembly for the first time, he has no clue what he's doing, help him out and procure your reward in the form of a flag :)

> [question](question)

## Solution

Decompile in Hopper

	int main() {
	    rdi = "Look for something else....\n";
	    rax = 0x0;
	    stack[2046] = 0x50 ^ 0x2d;
	    stack[2045] = 0xc1 ^ 0xb8;
	    stack[2044] = 0x51 ^ 0x60;
	    stack[2043] = 0x33 ^ 0x51;
	    stack[2042] = 0x45 ^ 0x28;
	    stack[2041] = 0x9b ^ 0xa8;
	    stack[2040] = 0x71 ^ 0x2;
	    stack[2039] = 0x8b ^ 0xd8;
	    stack[2038] = 0x98 ^ 0xac;
	    stack[2037] = 0x8e ^ 0xd1;
	    stack[2036] = 0x66 ^ 0x8;
	    stack[2035] = 0xa9 ^ 0x98;
	    stack[2034] = 0x65 ^ 0x3a;
	    stack[2033] = 0x7e ^ 0x4d;
	    stack[2032] = 0x10 ^ 0x74;
	    stack[2031] = 0x6b ^ 0x5b;
	    stack[2030] = 0x98 ^ 0xfb;
	    stack[2029] = 0xc5 ^ 0x9a;
	    stack[2028] = 0x37 ^ 0x44;
	    stack[2027] = 0x92 ^ 0xf6;
	    stack[2026] = 0x44 ^ 0xa;
	    stack[2025] = 0x80 ^ 0xe5;
	    stack[2024] = 0xc8 ^ 0xaf;
	    stack[2023] = 0x26 ^ 0x15;
	    stack[2022] = 0x3e ^ 0x52;
	    stack[2021] = 0x9a ^ 0xe1;
	    stack[2020] = 0x13 ^ 0x75;
	    stack[2019] = 0xa2 ^ 0xd6;
	    stack[2018] = 0xbe ^ 0xdd;
	    stack[2017] = 0xac ^ 0xdc;
	    rax = sub_560();
	    rax = 0x0;
	    rsp = (rsp - 0xf0) + 0xf8;
	    rbp = stack[2047];
	    return 0x0;
	}

Sublime Text and Regex

- Find: `stack\[....\] = (.+);`
- Replace: `flag += chr($1)`

> python3 flag.py

## Flag
	
	pctf{l3geNds_c0d3_1n_4Ss3mb1y}