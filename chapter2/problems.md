## 2.1 Practice Problem

1. Ox39A7F8 > binary   
0011 1001 1010 0111 1111 1000
2. binary 1100 1001 0111 1011 > hex  
0xC97B
3. OxD5E4C > binary  
1101 0101 1110 0100 1100  
4. binary 0010 0110 1110 0111 1011 0101 > hex  
Ox26D7B5

## 2.2 Practice Problem

| n  | 2<sup>n</sup> (decimal) |  2<sup>n</sup> (hexadecimal) |
|:--:|:-----------------------:|:----------------------------:|
| 9  |   512                   |   0x200                      |
| 19 |   524,288               |   0x80000                    |
| 14 |   16,384                |   0x4000                     |
| 16 |   65,536                |   0x10000                    |
| 17 |   131,072               |   0x20000                    |        
| 5  |   32                    |   0x20                       |  
| 7  |   128                   |   0x80                       |        


## 2.3 Practice Problem

| Decimal  | Binary            |  Hexadecimal                 |
|:--------:|:-----------------:|:----------------------------:|
|    0     |   0000 0000       |        0x00                  |
|  167     |   1010 0111       |        0xA7                  |
|   62     |   0011 1110       |        0x3E                  |
|  188     |   1011 1100       |        0xBC                  |
|   55     |   0011 0111       |        0x37                  |        
|  136     |   1000 1000       |        0x88                  | 
|  243     |   1111 0011       |        0xF3                  |        
|   82     |   0101 0010       |        0x52                  | 
|  172     |   1010 1100       |        0xAC                  | 
|  231     |   1110 0111       |        0xE7                  | 


## 2.4 Practice Problem

1. 0x503c + 0x8 = 0x4FFC
2. 0x503c - 0x40 = 0x4F9C
3. 0x503c + 64 = 0x507c
4. 0x50ea - 0x503c = 0xAE


## 2.5 Practice Problem

```c
int val = 0x87 65 43 21;
byte_pointer valp = (byte_pointer) &val; /* casts this as a pointer */
show_bytes(valp, 1); /* 1 */
show_bytes(valp, 2); /* 2 */
show_bytes(valp, 3); /* 3 */
```

1. Little endian: 21 Big endian: 87  
2. Little endian: 21 43 Big endian: 87 65   
3. Little endian: 21 43 65 Big endian: 87 65 43 

## 2.6 Practice Problem

int 3510593 = 0x00359141  
float 3510593.0 = 0x4a564504

1. Answer 1  
| Hexidecimal | Decimal          | Binary                           |
|:-----------:|:----------------:|:-------------------------------------------:|
| 0x00359141  |      3,510,593   |             11 0101 1001 0001 0100 0001     |
| 0x4a564504  |  1,247,167,748   |  100 1010 0101 0110 0100 0101 0000 0100     |

|   0  |   0  |   3  |   5  |   9  |   1  |   4  |   1  |
|------|------|------|------|------|------|------|------|
| 0000 | 0000 | 0011 | 0101 | 1001 | 0001 | 0100 | 0001 |


|   4  |   A  |   5  |   6  |   4  |   5  |   0  |   4  |
|------|------|------|------|------|------|------|------|
| 0100 | 1010 | 0101 | 0110 | 0100 | 0101 | 0000 | 0100 |

2. Answer 2
1**101011001000101000001**   
10010100**101011001000101000001**00  

3. The MSB of the first number does not match, the 2 LSBs of the second number do not match

## 2.7 Pratice problem
1. What would print?
```c
const char *s = "abcdef";
show_bytes((byte_pointer), s, strlen(s));
```
Printed:  
`61 62 63 64 65 66`  
strlen does not count the terminating null character `00`, so it is not printed

### Web Aside DATA:BOOL
>**Boolean ring** used in boolean arithmetic for ^(XOR) and ~(NOT)
>- Interesting property is the additive inverse, where _x + -x = 0_.
>- with ^, ^ is the addition operation, but each element is its own additive inverse
>For example:
>_a ^ a = 0_ for any value a
>_0 ^ 0 = 1 ^ 1 = 0_
>This works when we rearrange/combine terms: _(a ^ b) ^ a = b_

## 2.8 Practice Problem

| Operation | Result     |
|:---------:|:----------:|
| a         | [01101001] |
| b         | [01010101] |
| ~a        | [10010110] |
| ~b        | [10101010] |
| a&b       | [01000001] |
| a\|b      | [01111101] |
| a^b       | [00111100] |


## 2.9 Practice Problem

1. Black
2. Yellow
3. Magenta
4. Red
5. Cyan
6. Green
7. Blue
8. Black

```c
Blue | Green

   001
OR 010
   ---
   011

Yellow & Cyan

  110
& 011
  ---
  010

Red ~ Magenta

  100
^ 101
  ---
  001
```

## 2.10 Practice Problem

```c
void inplace_swap(int *x, int *y) {
   *y = *x ^ *y;   /* Step 1 */
   *x = *x ^ *y;   /* Step 2 */
   *y = *x ^ *y;   /* Step 3 */
}
```
| Step       | *x                                      | *y                                     |
|:-----------|:---------------------------------------:|:--------------------------------------:|
| Initially  | a                                       | b                                      |
| Step 1     | a                                       | a ^ b                                  |
| Step 2     | a ^ (a ^ b) = (a ^ a) ^ b = 0 ^ b = b   | a ^ b                                  |
| Step 3     | b                                       | b ^ (a ^ b) = (b ^ b) ^ a = 0 ^ a = a  | 


## 2.11 Practice Problem

```c
void reverse_array(int a[], int cnt) {
   int first, last;
   for (first = 0, last = cnt -1; first <= last; first++, last--)
      inplace_swap(&a[first], &a[last]);
}
```
1. *x = 3, *y = 0
2. Because the first and last value are equal in the last iteration
3. Put an if(first == last) {a[last | first]} clause? NOPE - change **first < last** to reverse_array:  
```c
void reverse_array(int a[], int cnt) {
   int first, last;
   for (first = 0, last = cnt -1; **first < last**; first++, last--)
      inplace_swap(&a[first], &a[last]);
}
```

## 2.12 Practice Problem
```c
A. Return the LSB of x with all other bits set to 0.

x & 0xFF;

0x87654321
```
| 8 byte index  | 7 | 6 | 5 | 4| 3 | 2 | 1 | 0 |   
|:--------------|
| Hex 0x        | 8         | 7         | 6         | 5         | 4         | 3         | 2         | 1         |
| Original      | 0000 1000 | 0000 0111 | 0000 0110 | 0000 0101 | 0000 0100 | 0000 0011 | 0000 0010 | 0000 0001 | 
| Mask (& 0xFF) | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 1111 1111 | 1111 1111 | 
| Returns       | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0010 | 0000 0001 |


```c
B. All but the LSB of x complemented, with the LSB changed.
x ^ ~0xFF;

0x87654321
```

| 8 byte index  | 7 | 6 | 5 | 4| 3 | 2 | 1 | 0 |   
|:--------------|
| Hex 0x        | 8         | 7         | 6         | 5         | 4         | 3         | 2         | 1         |
| Original      | 0000 1000 | 0000 0111 | 0000 0110 | 0000 0101 | 0000 0100 | 0000 0011 | 0000 0010 | 0000 0001 |  
| Mask (^ ~0xFF)| 1111 1111 | 1111 1111 | 1111 1111 | 1111 1111 | 1111 1111 | 1111 1111 | 0000 0000 | 0000 0000 |
| Returns       | 1111 0111 | 1111 1010 | 1111 1001 | 1111 1010 | 1111 1011 | 1111 1100 | 0000 0010 | 0000 0001 |  

This returns 0x789ABC21

```c
C. x | 0xFF;

0x87654321
```
| 8 byte index  | 7 | 6 | 5 | 4| 3 | 2 | 1 | 0 |   
|:--------------|
| Hex 0x        | 8         | 7         | 6         | 5         | 4         | 3         | 2         | 1         |
| Original      | 0000 1000 | 0000 0111 | 0000 0110 | 0000 0101 | 0000 0100 | 0000 0011 | 0000 0010 | 0000 0001 | 
| Mask (\| 0xFF)| 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 0000 0000 | 1111 1111 | 1111 1111 |
| Returns       | 0000 1111 | 0000 0111 | 0000 0110 | 0000 0101 | 0000 0100 | 0000 0000 | 1111 1111 | 1111 1111 |


## 2.13 Practice Problem

```c
/* Declarations of functions implementing operations bis (bit set) and bic (bit clear) */
int bis(int x, int m);
int bic(int x, int m);

/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {  
   int result = bis(x, y);
   return result;
}

/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
   int result = bis(bic(x,y), bic(x,y));
   return result;
}
``` 

## 2.14 Practice Problem

```c
x = 0x66    0110 0110
y = 0x39    0011 1001
```
Perform the bitwise per bit, and the other per byte. See the last row for bitwise example.
| Expression | Value | Expression   | Value |
|:----------:|:-----:|:------------:|:-----:|
| x & y      |  0x20 |   x && y     | 0x01  |
| x \| y     |  0x7f |   x \|\| y   | 0x01  |
| ~x \| ~y   |  0xdf |  !x \|\| !y  | 0x00  |
|  x & !y    |  0x00 |   x && ~y    | 0x01  |

## 2.15 Practice Problem
Using only bit level and logical operations, write a C expression that is equivalent to `x == y` (returns 1 when x and y are equal and 0 otherwise).  
`!(x ^ y)`

## 2.16 Practice Problem

| x     |    x       | x << 3     |   x << 3 | Logical x >> 2   |  Logical x >> 2 | Arithmetic x >> 2 | Arithmetic x >> 2 |
|:------|:-----------|:-----------|----------|:-----------------|:----------------|:------------------|:------------------|
|**Hex**| **Binary** | **Binary** | **Hex**  | **Binary**       | **Hex**         | **Binary**        |   **Hex**         |
| 0xC3  | 1100 0011  | 0001 1000  | 0x18     | 0011 0000        | 0x30            | 1111 0000         |  0xF0             |
| 0x75  | 0111 0101  | 1010 1000  | 0xA8     | 0001 1101        | 0x1D            | 0001 1101         |  0x1D             |
| 0x87  | 1000 0111  | 0011 1000  | 0x38     | 0010 0001        | 0x21            | 1110 0001         |  0xE1             |
| 0x66  | 0110 0110  | 0011 0000  | 0x30     | 0001 1001        | 0x19            | 0001 1001         |  0x19             |

## 2.17 Practice Problem

| x-> | | | |
|:----------------|:-----------|:-----------------------------------------------|:------------------------------------------------|
| **Hexidecimal** | **Binary** | **_B2U<sub>4</sub>(x)_**                       | **_B2T<sub>4</sub>(x)_**                        |
| 0xE             | [1110]     | 2<sup>3</sup>+2<sup>2</sup>+2<sup>1</sup> = 14 | -2<sup>3</sup>+2<sup>2</sup>+2<sup>1</sup> = -2 |
| 0x0             | [0000]     | 0                                              | 0                                               |
| 0x5             | [0101]     | 2<sup>2</sup>+2<sup>0</sup> = 5                | -2<sup>2</sup>+2<sup>0</sup> = 5                |
| 0x8             | [1000]     | 2<sup>3</sup> = 8                              | -2<sup>3</sup> = -8                             |
| 0xD             | [1101]     | 2<sup>3</sup>+2<sup>2</sup>+2<sup>0</sup> = 13 | -2<sup>3</sup>+2<sup>2</sup>+2<sup>0</sup> = -3 |
| 0xF             | [1111]     | 2<sup>3</sup>+2<sup>2</sup>+2<sup>1</sup>+2<sup>0</sup> = 15 | -2<sup>3</sup>+2<sup>2</sup>+2<sup>1</sup>+2<sup>0</sup> = -1 |

## 2.18 Practice Problem

| Hex value | Decimal |
|:----------|:-------:|
|  0x2e0    |  736    |
|  -0x58    |  -88    |
|  0x28     |  40     |
|  -0x30    |  -48    |
|  0x78     |  120    |
|  0x88     |  136    |
|  0x1f8    |  504    |
|  0x8      |  128    |
|  0xc0     |  192    |
|  -0x48    |  -72    |


## 2.19 Practice Problem

| x  | **_T2U<sub>4</sub>(x)_** |
|:--:|:------------------------:|
| -8 |   
| -3 |
| -2 |
| -1 |
|  0 |
|  5 |