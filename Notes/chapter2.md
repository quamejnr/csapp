# Chapter 2

## Objectives

- [x] Understand the properties of unsigned and two's-complement number representations
- [x] Understand how numbers are represented and the range of values that can be encoded for a given word size
- [x] Effect of casting between signed and unsigned numbers
- [ ] Understand the mathematical properties of arithmetic operations

## 2.1 Information Storage

In dealing with bit patterns, hexadecimal notation is preferred.
It's compact, not too verbose as binary, not too tedious to convert to binary as decimal.
It represents 4 binary digits which makes it perfect for representing 8 bits which will be 2 hex numbers.

### 2.1.1 Hexadecimal Notation

Why Hex?
The machine runs on binary which is not very intuitive for us but decimal is also not compact enough.
Hexadecimal is great as two bytes also make up 16. It is also readable as it's not too long.
Easy to convert to binary and decimal when needed.

#### Practice Problem 2.1

A. 0x25B9D2 to binary = `10-0101-1011-1001-1101-0010` ✅
B. 1010111001001001 to hexadecimal = `0xAE49` ✅
C. 0xA8B3D to binary = `1010-1000-1011-0011-1101` ✅
D. 1100100010110110010110 to hexadecimal = `0x322D96` ✅

#### Practice Problem 2.2

| n   | $2^n$ (decimal) | $2^n$ (hexadecimal) |
| --- | --------------- | ------------------- |
| 5   | 32              | 0x20                |
| 23  | 8388608         | 0x800000            |
| 15  | 32768           | 0x8000              |
| 13  | 8192            | 0x2000              |
| 12  | 4096            | 0x1000              |
| 6   | 64              | 0x40                |
| 8   | 256             | 0x100               |

#### Practice Problem 2.3

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

#### Practice Problem 2.4

A. 0x605c + 0x5 = 0x6061
B. 0x605c - 0x20 = 0x603c
C. 0x605c + 32 = 0x607c
D. 0x60fa - 0x605c = 0x9E

### 2.1.2 Data sizes

Word size is the number of bits of CPU can process at a time.
It determines the maximum size of the virtual address space.

### 2.1.3 Addressing and Byte Ordering

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

#### Practice Problem 2.5

| Little Endian | Big Endian |
| ------------- | ---------- |
| 78            | 12         |
| 78 56         | 12 34      |
| 78 56 34      | 12 34 56   |

#### Practice Problem 2.6

A. 0x0027C8F8 = 0000 0000 0010 0111 1100 1000 1111 1000
0x4A1F23E0 = 0100 1010 0001 1111 0010 0011 1110 0000

B. 21 matching bits
i. 0x0027C8F8 = 00000000001 `001111100100011111000`
ii. 0x4A1F23E0 = 010010100 `001111100100011111000` 00

NB: Letters `a` through `z` have ASCII codes 0x61 through 0x7A.

### Representing Strings

A string in C is an array of characters that terminates with a null character.

#### Practice Problem 2.7

`6d 6e 6f 70 71 72`

### Representing Code

Machine/Binary code are not portable. They are different based on OS and architecture.

### Boolean Algebra

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

#### Practice Problem 2.8

| Operation | Result     |
| --------- | ---------- |
| a         | [01001110] |
| b         | [11100001] |
| ~a        | [10110001] |
| ~b        | [00011110] |
| a&b       | [01000000] |
| aORb      | [11101111] |
| a^b       | [10101111] |

#### Practice Problem 2.9

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

### Bit level operations in C

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

#### Practice Problem 2.12

A. AND Operation with 0xFF
B. XOR with bitmask 0xFFFFFF00
C. OR operation with bitmask 0xFF

### Logical Operations in C

#### Practice Problem 2.14

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

### Shift operations in C

Shift operations allow you to shift the bits of binaries.
x << 4 means left shift the bits, which means count 4 bits from the right and pick the remaining bits and pad the rest with 0s.
For example, if I apply x << 4 to 10010111 then it will be 0111**_0000_**.
When it comes to right shifting, there are two different ways; logical and arithmetic.
With logical the last shift bits are removed shifting the remaining values to the right and the leftmost part padded with 0s.
While, with arithmetic they are padded with the most significant bit.
For example, x >> 4 to 10010111 will be **_0000_**1001 in logical shift and **_1111_**1001 in an arithmetic shift.
Mostly arithmetic is done with signed bits.

#### Practice problem 2.16

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

#### Practice problem 2.17

| Hexadecimal | Binary | B2U | B2T |
| :---------: | :----: | :-: | :-: |
|     0xA     |  1010  | 10  | -6  |
|     0x1     |  0001  |  1  |  1  |
|     0xB     |  1011  | 11  | -5  |
|     0x2     |  0010  |  2  |  2  |
|     0x7     |  0111  |  7  |  7  |
|     0xC     |  1100  | 12  | -4  |

The min of hex in 8 bits in 0x80 and the max 0x7F

#### Practice Problem 2.18

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

### Conversion between Signed and Unsigned

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
-x = 2^16 + x
x = x
```

In the other hand, you can also look at the U2T$_16$ this way;

```
x >= 2$^w-1$ ==> x - 2^w
x < 2$^w-1$ ==> x
```

> Converting U2T(x) x = x if x ≤ Tmax and $x - 2^w$ if x > Tmax
> Converting from 2s complement to unsigned is x if x is positive and $2^w + x$ if x is negative.

#### Practice Problem 2.19

|  x  | T2U4(x) |
| :-: | :-----: |
| -1  |   15    |
| -5  |   11    |
| -6  |   10    |
| -4  |   12    |
|  1  |    1    |
|  8  |    8    |

### Signed vs unsigned in C

In C, when arithmetic or comparison operations are done between an unsigned and signed value, the signed value is casted to unsigned.
Umax has the same bit representation in unsigned form as does -1 in two's complement form.

#### Practice Problem 2.21

|          Expression          |   Type   | Evaluation |
| :--------------------------: | :------: | :--------: |
| -2147483647-1 == 2147483648U | Unsigned |     1      |
|  -2147483645-1 < 2147483647  | Unsigned |     0      |
| -2147483647-1U < 2147483647  | Unsigned |     0      |
| -2147483647-1 < -2147483647  |  Signed  |     1      |
| -2147483648-1U < -2147483647 | Unsigned |     1      |

### Expanding bit representation of a number

To convert an unsigned number to a larger data type, we simple add leading zeros to the representation.
This is known as **zero extension**.
Thus, 1111U(4 bits) -> 00001111U(8 bits) also, 0xcfc7U -> 0xcfc7ffffU and 0xcfc7(signed) -> 0x0000cfc7.
The representation above is big endian.

To convert a two's complement to a larger data type, we add the most significant bits to the beginning.

#### Practice Problem 2.22

A. [1100] -> -8+4 = -4
B. [11100] -> -16+8+4 = -4
C. [111100] -> -32+16+8+4 = -4

#### Practive Problem 2.23

| w          | fun1(w)    | fun2(w)    |
| ---------- | ---------- | ---------- |
| Ox00000076 | 0x00000076 | 0x00000076 |
| 0x87654321 | 0x00000021 | 0x00000021 |
| 0x000000C9 | 0x000000C9 | 0xFFFFFFC9 |
| 0xEDCBA987 | 0x00000087 | 0xFFFFFF87 |

### Truncating numbers

When converting the numbers from some bits to lesser bits.
Like from 8bits to 4 bits, you only count from the 4 bits.
Thus you can have x mod 2^k

#### Practice Problem 2.24

Truncate 4 bit value to 3bit

##### Unsigned

| Original | Truncated |
| -------- | --------- |
| 1        | 1         |
| 3        | 3         |
| 5        | 5         |
| 12       | 4         |
| 14       | 6         |

##### Two's complement

| Original | Truncated |
| -------- | --------- |
| 1        | 1         |
| 3        | 3         |
| 5        | 5         |
| -4       | -4        |
| -2       | -2        |

#### Practice Problem 2.25

The error with the code is because when the unsigned length becomes `-1` it's interpreted in it's unsigned form.
In it's unsigned form, it will always be greater than i, leading it to access indices that are beyond the length of a.
The fix is to change it to signed integer

#### Practice Problem 2.26

The function produces an error when the difference between s and t is negative.
`strlen` returns an unsigned integer thus when it becomes negative, it produces weird result which leads to s always being bigger than t.
The solution is to typecast the difference between the `strlen` of both s and t to int before comparing with 0.

## Integer Arithmetic

### Unsigned Addition

Adding two non negative integers $0 ≤ x, y < 2^w$ result in $0 ≤ x+y ≤ 2^(w+1) - 2$.
This means addition of two positive integers will always lead to an increase in bit number.
If we maintain the sum and add another number it will lead to w+2 bits which leads unbounded word size.

Programming languages these days support fixed sized arithmetic, they do so by truncating the most significant bit.
Thus, the sum of two non negative integers $0 ≤ x, y < 2^w$ will lead to the $2^w mod x+y$ if x+y > 2^w.
Thus, 8 + 12 in 4bits even will be 20 mod 2^4 = 4

Derivation:
x + y ≥ x
sum s ≥ x if no overflow
if s overflows s = x + y - 2^w
Given that y < 2^w
s = x + (y - 2^w) < x

#### Practice Problem 2.27

```C
int uadd_ok(unsigned x, unsigned y) {
  // Not 0 will flip all the bits to 1 since they are all 0.
  unsigned overflow = ~0U;
  int sum = x + y;

  return sum >= x || sum >= y;
}
```

#### Practice Problem 2.28

| Hex | Decimal | -Decimal | -Hex |
| --- | ------- | -------- | ---- |
| 1   | 1       | 15       | F    |
| 4   | 4       | 12       | C    |
| 7   | 7       | 9        | 9    |
| A   | 10      | 6        | 6    |
| E   | 14      | 2        | 2    |

### Two's complement addition

Given a range of $2^w-1 ≥ x, y ≤ 2^w-1 - 1$, then the sum will be in the range $2^w ≤ x+y ≤ 2^w - 2$
if x + y is represented as z then the value z will be a negative overflow if it is in the range $-2^w < z < 2^w-1$ and thus z will be $x+y+2^w$
z will be a positive overflow if it is in the range $2^w-1 - 1 < z < 2^w - 2$ and thus z will be $x+y-2^w$
Given $TMin ≤ x, y ≤ TMax$ it's a positive overflow if the sum s is $s ≤ 0$ if $x, y > 0$ and negative overflow if $s ≥ 0$ given $x,y < 0$

#### Practice Problem 2.29

In 5 bits

|      x      |      y      |     x+y      |   x+y(TC)   |  Case  |
| :---------: | :---------: | :----------: | :---------: | :----: |
| -12 [10100] | -15 [10001] | -27 [100101] |  5 [00101]  | Case 1 |
| -8 [11000]  | -8 [11000]  | -16 [110000] | -16 [10000] | Case 2 |
| -9 [10111]  |  8 [01000]  | -1 [111111]  | -1 [11111]  | Case 2 |
|  2 [00010]  |  5 [00101]  |  7 [000111]  |  7 [00111]  | Case 3 |
| 12 [01100]  |  4 [00100]  | 16 [010000]  | -16 [10000] | Case 4 |

#### Practice Problem 2.30

```C
int tadd_ok(int x, int y) {
  // An overflow can occur in two situations
  // 1. If x and y are both greater than 0 but their sum is less than 0
  // 2. If x and y are both less than 0 but their sum is greater than 0
  int pos_overflow = (x > 0 && y > 0) && x + y <= 0;
  int neg_overflow = (x < 0 && y < 0) && x + y >= 0;
  return !(pos_overflow || neg_overflow);
}
```

#### Practice Problem 2.31

```C
/* Determine whether arguments can be added without overflow
*/ /* WARNING: This code is buggy. */
int tadd_ok(int x, int y) {
    int sum = x+y;
    return (sum-x == y) && (sum-y == x);
}
```

The above code is buggy because `sum - x` will always evaluate to y whether there is an overflow or not.

#### Practice Problem 2.32

Code is buggy when y is TMin.

### Two's complement negation

Tmin ≤ x ≤ Tmax; x = Tmin if x is Tmin and -x if x > Tmin

#### Practice Problem 2.33

| x(Hex) | x(Decimal) | -x(Decimal) | -x(Hex) |
| ------ | ---------- | ----------- | ------- |
| 2      | 2          | -2          | -2      |
| 3      | 3          | -3          | -3      |
| 9      | -7         | 7           | 7       |
| B      | -5         | 5           | 5       |
| C      | -4         | 4           | 4       |

### Two's complement Multiplication

Integers x, y in range $-2^w-1 ≤ x, y ≤ 2^w-1 - 1$ can have their product ranging between $-2^w-1 x 2^w-1 - 1 = -2^2w-2$
Which could require as many as 1w bits to represent.
After multiplication, you truncate the product to w bits. With unsigned, that's it but with Two's complement, need to change to 2s complement.
Truncating is same as mod 2^w

#### Practice Problem 2.34

3 bit numbers

| Mode             | x       | y       | x·y        | Truncated x·y |
| ---------------- | ------- | ------- | ---------- | ------------- |
| Unsigned         | 4[100]  | 5[101]  | 20[010100] | 4[100]        |
| Two's complement | -4[100] | -3[101] | 12[001000] | -4[100]       |
| Unsigned         | 2[010]  | 7[111]  | 14[001110] | 6[110]        |
| Two's complement | 2[010]  | -1[111] | -2[111110] | -2[110]       |
| Unsigned         | 6[110]  | 6[110]  | 36[100100] | 4[100]        |
| Two's complement | -2[110] | -2[110] | 4[000100]  | -4[100]       |

### Multiplying by Constants

Multiplying by constants can be done using left shifts. x << 2 means the product of x and 2^2.
Generalizing from our example, consider the task of generating code for the expression x \* K, for some constant K. The compiler can express the binary representation of K as an alternating sequence of zeros and ones:
(0 . . . 0) (1 . . . 1) (0 . . . 0) . . . (1 . . . 1)] For example, 14 can be written as [(0 . . . 0)(111)(0)]. Consider a run of ones from bit position n down to bit position m (n ≥ m). (For the case of 14, we have n = 3 and m = 1.) We can compute the effect of these bits on the product using either of two different forms:

- Form A: (x<<n) + (x<<(n − 1)) + . . . + (x<<m)
- Form B: (x<<(n + 1)) - (x<<m)

#### Practice Problem 2.42

```c
#include <stdio.h>

int div16(int val) { return (val < 0 ? val + 15 : val) >> 4; }
```

#### Practice Problem 2.43

M = 31
N = 8

### Floating Point

Floating points in binary just as decimals are represented by multiplying 2 by decreasing values from 0 after the binary point.
Ex: 1.01 = 1*2^0 + 0*2^-1 + 1\*2^-2 = 1+0+(1/4) = 5/4

#### Practice Problem 2.45

| Fractional value | Binary  | Decimal |
| :--------------: | :-----: | :-----: |
|       1/8        |  0.001  |  0.125  |
|       3/4        |  0.11   |  0.75   |
|       5/16       | 0.0101  | 0.3125  |
|      43/16       | 10.1011 | 2.6875  |
|       9/8        |  1.001  |  1.125  |
|       47/8       | 110.111 |  5.875  |
|      51/16       | 11.0011 | 3.1875  |

Layout of floating points in C
For 32 bits: E = 8, Fraction = 23 and the sign = 1
For 64 bits: E = 11, Fraction = 52 and the sign = 1

For normalized values we're looking at the exponent not being 0 nor 255 (using single precision).
Denormalized values: The exponent is all 0s
While for special cases where the exponent is represented by all `1s` thus being 255 and the fractional bits represented by all `0s`, you have an infinity on your hands.
When the exponent is all `1s` and and the fractional bits are not `0s` then you have NaN(Not a Number).

#### Floating point to binary
- formula for conversion. 
    1. convert integer before radix point
    2. while fractional part != 0
        - multiply by 2 and keep integer before radix point.
    3. Read integers top down
    - Ex: 2.125 -> convert decimal 2 = (10)~2~
    - 0.125 x 2 = 0.25 -> keep 0
    - 0.25 x 2 = 0.5 -> keep 0
    - 0.5 x 2 = 1.0 -> keep 1
    - 2.125 in binary = (10.001)~2~ 
#### Normalisation
- Need for normalisation
    - different representations. Ex 101.101 = 1.01101 x 2^2^ = 10110.1 x 2^-2^ ...
- Normalized values
    - Implicit Normalisation 
        - RHS of significant 1. Ex 101.101 = 1.01101 x 2^2^
    - Explicit Normalisation
        - LHS of significant 1. Ex 101.101 = 0.101101 x 2^3^
- Denormalized values
    - exponent is all 0s. Thus e=1-bias and M has no implied 1. 
    - represent 0s and numbers very close to 0, _gradual underflow_.
- Special values
    - exponent = all 1s, mantissa = all 0s, value = infinity. Can be -ve/+ve depending on sign. 
    - exponent = all 1s, mantissa ≠ 0s. value = NaN.
#### IEEE standard
- Different precisions
    - Single point precision
        - 32 bits -> sign=1, exponent=8, mantissa=23
    - Double point precision
        - 64 bits -> sign=1, exponent=11, mantissa=52
- representation 
    - |sign|exponent|mantissa|
- formula for conversion to decimal
    - v = (-1)^s^ x 1.M x 2^e^, where e = exponent - bias. For values between 1 < M < 2^k-1^.
    - bias = 2^k-1^ - 1 where k is the number of bits for exponent.

