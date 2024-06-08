# Chapter 2

## Objectives

- [x] Understand the properties of unsigned and two's-complement number representations
- [x] Understand how numbers are represented and the range of values that can be encoded for a given word size
- [ ] Effect of casting between signed and unsigned numbers
- [ ] Understand the mathematical properties of arithmetic operations

## 2.1 Information Storage

In dealing with bit patterns, hexadecimal notation is preferred.
It's compact, not too verbose as binary, not too tedious to convert to binary as decimal.
It represents 4 binary digits which makes it perfect for representing 8 bits which will be 2 hex numbers.

## 2.1.1 Hexadecimal Notation

Why Hex?
The machine runs on binary which is not very intuitive for us but decimal is also not compact enough.
Hexadecimal is great as two bytes also make up 16. It is also readable as it's not too long.
Easy to convert to binary and decimal when needed.

### Practice Problem 2.1

A. 0x25B9D2 to binary = `10-0101-1011-1001-1101-0010` ✅
B. 1010111001001001 to hexadecimal = `0xAE49` ✅
C. 0xA8B3D to binary = `1010-1000-1011-0011-1101` ✅
D. 1100100010110110010110 to hexadecimal = `0x322D96` ✅

### Practice Problem 2.2

| n   | $2^n$ (decimal) | $2^n$ (hexadecimal) |
| --- | --------------- | ------------------- |
| 5   | 32              | 0x20                |
| 23  | 8388608         | 0x800000            |
| 15  | 32768           | 0x8000              |
| 13  | 8192            | 0x2000              |
| 12  | 4096            | 0x1000              |
| 6   | 64              | 0x40                |
| 8   | 256             | 0x100               |

### Practice Problem 2.3

| Decimal | Binary    | Hexadecimal |
| ------- | --------- | ----------- |
| 0       | 0000 0000 | 0x00        |
| 158     | 1001 1110 | 0x9E        |
| 76      | 0100 1100 | 0x4C        |
| 174     | 1010 1110 | 0xAE        |
| 60      | 0011 1100 | 0x3C        |
| 241     | 1111 0001 | 0xF1        |
| 117     | 0111 0101 | 0x75        |
| 189     | 1011 1101 | 0xBD        |
| 245     | 1111 0101 | 0xF5        |

### Practice Problem 2.4

A. 0x605c + 0x5 = 0x6061
B. 0x605c - 0x20 = 0x603c
C. 0x605c + 32 = 0x607c
D. 0x60fa - 0x605c = 0x9E

## 2.1.2 Data sizes

Word size is the number of bits of CPU can process at a time.
It determines the maximum size of the virtual address space.

## 2.1.3 Addressing and Byte Ordering

Dealing with program objects that span multiple bytes, two conventions needs to be established.

1. The address of the object
2. The order in which it is stored in memory

The address of object points to the first address of an object.
Mostly the order in which bytes are stored in memory is irrelevant except in few situations.

1. Binary data communicating through network need to convert as the transport layer is big endian.
   Also, the receiving computer may be big endian and your data being sent from a little endian machine.
   That can also lead to problems.
2. Another is when representing integer data. For little endian machines integer data represented at byte level needs to have the least significant byte at utmost left with the most significant at your far right.
3. It also becomes a problem when when types are casted into different types.

### Practice Problem 2.5

| Little Endian | Big Endian |
| ------------- | ---------- |
| 78            | 12         |
| 78 56         | 12 34      |
| 78 56 34      | 12 34 56   |

### Practice Problem 2.6

A. 0x0027C8F8 = 0000 0000 0010 0111 1100 1000 1111 1000
0x4A1F23E0 = 0100 1010 0001 1111 0010 0011 1110 0000

B. 21 matching bits
i. 0x0027C8F8 = 00000000001 `001111100100011111000`
ii. 0x4A1F23E0 = 010010100 `001111100100011111000` 00

NB: Letters `a` through `z` have ASCII codes 0x61 through 0x7A.

## Representing Strings

A string in C is an array of characters that terminates with a null character.

### Practice Problem 2.7

`6d 6e 6f 70 71 72`

## Representing Code

Machine/Binary code are not portable. They are different based on OS and architecture.

## Boolean Algebra

Boolean operations distribute over `&` and `|`.
Thus $a&(b|c) = a&b | a&c$. Also, $a|(b&c) = a|b & a"c$.
| R | G | B | Color |
|---------------- | --------------- | --------------- | --------------- |
| 0 | 0 | 0 | Black |
| 0 | 0 | 1 | Blue |
| 0 | 1 | 0 | Green |
| 0 | 1 | 1 | Cyan |
| 1 | 0 | 0 | Red |
| 1 | 0 | 1 | Magenta |
| 1 | 1 | 0 | Yellow |
| 1 | 1 | 1 | White |

### Practice Problem 2.8

| Operation | Result     |
| --------- | ---------- |
| a         | [01001110] |
| b         | [11100001] |
| ~a        | [10110001] |
| ~b        | [00011110] |
| a&b       | [01000000] |
| aORb      | [11101111] |
| a^b       | [10101111] |

### Practice Problem 2.9

A.
| Color | Complement |
|--------------- | --------------- |
| Black | White |
| Blue | Yellow |
| Green | Magenta |
| Cyan | Red |
| Red | Cyan |
| Magenta | Green |
| Yellow | Blue |
| White | Black |

B.
Blue | Green = `011` = Cyan
Yellow & Cyan = `010` = Green
Red ^ Magenta = `001` = Blue

## Bit level operations in C

Given two numbers `x=5` and `y=10`, we can switch these two numbers in place by using a temporary variable as the C code below;

```C
#include <stdio.h>

int main(void) {
    int x = 5;
    int y = 10;
    printf("Before reassignment\n");
    printf("x: %d\n", x);
    printf("y: %d\n", y);

    printf("-----------------------\n");

    // Assign y to a temporay variable
    int temp = y;
    y = x;
    x = temp;

    printf("After reassignment\n");
    printf("x: %d\n", x);
    printf("y: %d\n", y);

}
```

There is also another way to do this by using Exclusive OR (XOR). This does not need a temporary variable and will switch the values in place.
It involves 3 XOR operations.

```C
#include <stdio.h>

int main(void) {
    int x = 5;
    int y = 10;

    printf("Before reassignment\n");
    printf("x: %d\n", x);
    printf("y: %d\n", y);

    printf("-----------------------\n");

    // XOR is represented by ^
    // The 3 XOR operations
    y = x ^ y;
    x = x ^ y;
    y = x ^ y;

    printf("After reassignment\n");
    printf("x: %d\n", x);
    printf("y: %d\n", y);
}
```

The above code changes the two variables without using a temporary variable. When you do those 3 XOR operations, the variables will switch places but why?
To understand that, let's first understand what Exclusive OR (XOR) is.

### Practice Problem 2.12

A. AND Operation with 0xFF
B. XOR with bitmask 0xFFFFFF00
C. OR operation with bitmask 0xFF

## Logical Operations in C

### Practice Problem 2.14

a = 0x55, b = 0x46
LOR = Logical OR operator
OR = bit OR operator
| Expression | Value |
|--------------- | --------------- |
| a & b | 0x44 |
| a OR b | 0x57 |
| ~a OR ~b | 0xBB |
| a & !b | 0x00 |
| a && b | 0x01 |
| a LOR b | 0x01 |
| !a LOR !b | 0x00 |
| a && ~b | 0x00 |

## Shift operations in C

Shift operations allow you to shift the bits of binaries.
x << 4 means left shift the bits, which means count 4 bits from the left and pick the remaining bits and padd the rest with 0s.
For example, if I apply x << 4 to 10010111 then it will be 0111**_0000_**.
When it comes to right shifting, there are two different ways; logical and arithmetic.
With logical the last shift bits are removed shifting the remaining values to the right and the leftmost part padded with 0s.
While, with arithmetic they are padded with the most significant bit.
For example, x >> 4 to 10010111 will be **_0000_**1001 in logical shift and **_1111_**1001 in an arithmetic shift.
Mostly arithmetic is done with signed bits.

### Practice problem 2.16

| a(Hex) | a(Binary) | a<<2(Binary) | a<<2(Hex) | a>>3 logical(Binary) | a>>3 logical(Hex) | a>>3 arithmetic(Binary) | a>>3 arithmetic(Hex) |
| :----: | :-------: | :----------: | :-------: | :------------------: | :---------------: | :---------------------: | :------------------: |
|  0xD4  | 11010100  |   01010000   |   0x50    |       00011010       |       0x1A        |        11111010         |         0xFA         |
|  0x64  | 01100100  |   10010000   |   0x90    |       00001100       |       0x0C        |        00001100         |         0x0C         |
|  0x72  | 01110010  |   11001000   |   0xC8    |       00001110       |       0x0E        |        00001110         |         0x0E         |
|  0x44  | 01000100  |   00010000   |   0x10    |       00001000       |       0x08        |        00001000         |         0x08         |

## Integer Representations

| Data type | Bytes |
| --------- | ----- |
| char      | 1     |
| int       | 4     |
| long      | 8     |

### Binary to unsigned integers

We can convert binary to unsigned integers by comparing the values of their $x~i~*2^i$.
For example, binary number 1011 to integer is $1x2^3 + 0x2^2 + 1x2^1 + 1x2^0 = 11$

### Binary to two's complement

Same vibe as above, except with this the first value is a signed bit and thus can be negative or positive.
eg. 1011 = $-1x2^3 + 0x2^2 + 1x2^1 + 1x2^0 = -8 x 0 x 2 x 1 = -5$

### Practice problem 2.17

| Hexadecimal | Binary | B2U | B2T |
| :---------: | :----: | :-: | :-: |
|     0xA     |  1010  | 10  | -6  |
|     0x1     |  0001  |  1  |  1  |
|     0xB     |  1011  | 11  | -5  |
|     0x2     |  0010  |  2  |  2  |
|     0x7     |  0111  |  7  |  7  |
|     0xC     |  1100  | 12  | -4  |

The min of hex in 8 bits in 0x80 and the max 0x7F

### Practice Problem 2.18

| Hex(2s complement) | Decimal |
| :----------------: | :-----: |
|       0x2e0        |   736   |
|       -0x58        |   -88   |
|        0x28        |   40    |
|       -0x30        |   -48   |
|        0x78        |   120   |
|        0x88        |   136   |
|       0x1f8        |   504   |
|        0x8         |    8    |
|        0xc0        |   192   |
|       -0x48        |   -72   |

## Conversion between Signed and Unsigned

The idea of bits being nothing without context is very evident these past few chapters. Basically the underlying bit patterns don't change during conversion, what changes is context. Thus, the same pattern will represent a positive value in unsigned form and negative value in signed form.

|  x  | T2U$_4$(x) |
| :-: | :--------: |
| -1  |     15     |
| -5  |     11     |
| -6  |     10     |
| -4  |     12     |
|  1  |     1      |
|  8  |     8      |


Conversion of twos complement to unsigned is;
if negative then add to 2$^w$;
if positive then keep it thus x in 16bits will be;
```
T2U$_16$
-x = 2^16 - x
x = x
```
In the other hand, you can also look at the U2T$_16$ this way;
```
x >= 2$^w-1$ ==> x - 2^w
x < 2$^w-1$ ==> x
```

### Signed vs unsigned in C
In C, when arithmetic or comparison operations are done between an unsigned and signed value, the signed value is casted to unsigned.
