# Part I: Program Structure and Execution

# Representing and Manipulating Information
- Modern computers store and process information as two-valued signals called bits (binary digits)
- Fibanacci brought them to the West from Arabs/India in the 13th century  

Three important representations of numbers with binary  
1. _Unsigned_ - based on traditional binary, represent numbers greater than or equal to 0.
2. _Two's-complement_ - most common way to represent signed integers (numbers that are positive or negative)
3. _Floating-point_ - base-2 version of scientific notation for representing real numbers.

- _overflow_ is when results of a computation are too large to be represented by the limited number of bits used to encode a number.
- integers can encode a comparatively small range of values precisely
- floating point arithmetic can encode a wide range of values, but only approximately

Computers use several different binary representations to encode numeric values. Need to understand:
- basic definitions of the encodings
- range of representable numbers
- their bit-level representations
- the properties of the arithmetic operations  

C and C++ are similar in their number representations. Java is different.

How to read the following notes**
1. A property as a principle is stated
2. Illustrate the principle with examples and discussion
3. For complex properties, there is a derivation (like a mathematical proof). You can skip these on the first reading if you don't understand.

## 2.1 Information Storage
- Computers use blocks of 8 bits (bytes) as the smmallest addressable unit of memory
- machine-level program views memory as a large array of bytes called _virtual memory_.
- Every byte of memory is ID'd by a unique number - the address
- The set of all possible addresses is the _virtual space_
   - virtual address space is just a conceptual image presented to the machine level program
   - Actual implementation is a combination of dynamic random access memory (DRAM), flash memory, disk storage, special hardware, and operating system software
   - These combine to provide the program with what it thinks is a monolithic byte array
- compiler and run-time system partition this virtual memory space into more mmanageable units to store program objects (program data, instructions, and control information)
   - Example: pointer in C is the virtual address of the first byte of some block of storage
   - **Pointers in C** - mechanism for referencing elemments of data structures, including arrays. Has a value (location of the object) and a type (what kind of object).

## 2.2 Hexadecimal Notation
- A byte has 8 bits, ranging from 00000000<sub>2</sub> to 11111111<sub>2</sub>. That is 0<sub>10</sub> to 255<sub>10</sub>.
- Bit patterns are written in Hexidecimal because binary is too much and decimal is too difficult to convert
- Hex is 0 - 9 and A - F for 16 possible values
- A single byte can range fromm 00<sub>16</sub> to FF<sub>16</sub>
- Hex numbers start with **0x** or **0X**. A - F could be upper or lowercase
   - FA1D37B<sub>16</sub> = 0xFA1D37B = 0xfa1d37b
- Good trick is to memorize decimal equivalents of A (10), C (12), and F (15)

| Hexidecimal | 1   | 7    | 3    | A    | 4    | C    |
|:------------|:---:|:----:|:----:|:----:|:----:|:----:|
| Binary      | 001 | 0111 | 0011 | 1010 | 0100 | 1100 |


| Binary      | 11  | 1100 | 1010 | 1101 | 1011 | 0011 |
|:------------|:---:|:----:|:----:|:----:|:----:|:----:|
| Hexidecimal | 3   | C    | A    | D    | B    | 3    |

### Converting a nonnegative integer when value x is a power of 2, meaning x = 2<sup>n</sup>:
- write x in hexidecimal form by remembering that binary of x is 1 followed by n zeros.
   - For example, 2<sup>3</sup> = 8 = 1000 in binary (1 followed by three 0s)
   - 2<sup>5</sup> = 32 = 100000 in binary (1 followed by five 0s)

### Converting to hexidecimal
- write _n_ in the form _i_ + (4 * _j_), where 0 <= _i_ <= 3
   1. find the first number in the hex 
      - 1 if _i_ = 0
      - 2 if _i_ = 1
      - 4 if _i_ = 2
      - 8 if _i_ = 3
   2. Add _j_ hexidecimal 0s after the first digit
      - For example, x = 2,048 = 2<sup>11</sup>.
      - n = 11, and 11 = 3 + (4 * 2). This gives us 0x800

### Converting from decimal to hexadecimal
To convert x decimal to hex, divide by 16.  

_x_ = _q_ * 16 + _r_  

r becomes the least significant digit. Generate the remmaining digifits by repeating the process on q:

314,156 = 19,634 * 16 + 12  C  
 19,634 = 1,227 * 16 + 12   2  
  1,227 = 76 * 16 + 11      B  
     76 = 4 * 16 + 12       C  
      4 = 0 * 16 + 4        4  

This is equal to **0x4CB2C**.

### Converting from hexidecimal to decimal
Multiply each of the hexadecimal digits by the appropriate power of 16, according to its place using 0 index.

For example, 0x7AF is:  
7 * 16<sup>2</sup> + 10 * 16 + 15 =  
7 * 256 + 10 * 16 + 15 =  
1,792 + 160 + 15 = 1,967

## Data Sizes
- _word size_ - nominal size of pointer data. Every computer has a word size
- determines max size of thevirtual address space because it is encoded words
   - for _w_-bit word size, virtual addresses can range from 0 to 2<sup>_w_</sup> - 1
- 32 bit word size used to be normal, now its 64 bit
- 32 bit gives the virtual address space 4 GB of size, and 64 gives virtual address space of 16 exabytes of size
- 64 bit machines are backwards compatible, but 32 bit can't run 64 bit
   - it matters how the program is compiled, not the machine.
- computers and compilers support multiple data formats for encoding data (think integers and floating point numbers)
- different languages allocate different number of bytes per data type. Depends on how they are compiled. There are signed and unsigned (nonnegative)
- ISO C99 introduced a class of data types where data sizes were fixed regardless of compiler or machine settings. Allows better control
   - examples: int32_t (4 bytes) and int64_t (8 bytes)
- Most data types encode signed values.
   - char is different. To guarantee a 1-byte signed value, use 'signed char' in the declaration
- you can order the keywords in a variety of ways in C
   - unsigned long
   - unsigned long int
   - long unsigned
   - long unsigned int

## 2.1.3 Addressing and Byte Ordering

- Program objects that span multiple bytes, we must establish: 
   1. What the address of the object will be
   2. How we order the bytes in memory
- Multi-byte objects are stored connecting sequence of bytes. Address of the object is usually the smallest address used
   - int x has address 0x100, then, on a 32-bit machine, the 4 bytes that it takes up is Ox100, Ox101, Ox102, Ox103  
### Ordering bytes representing an object:  
- _w_-bit integer with bit representation [xw-1, xw-2,...x1, x0]
- xw-1 is the most significant bit and x0 is the least
- if w is a multiple of 8, you can group these bits as bytes with the MSB having bits [xw-1, xw-2,...,xw-8] and the LSB having bits [x7, x6, ..., x0]. Any other bytes use the bits in the middle.
- machines store them differently:  
**Little endian** - when the machine stores the bits starting with the LSB  
   - Intel compatible machines use little-endian mode  
**Big endian** - when the machine stores the bits starting with the MSB
   - IBM and Oracle often use big-endian  

Some machines can run in _bi-endian_ mode, which means both of them, but it is usually fixed once a particular OS is chosen.

### Example
int x is at address 0x100 and has a hex value of 0x1234567 (this hex value is a word, and 0xMSB > LSB)

Little endian storage:  
| 0x100 | 0x101 | 0x102 | 0x103 | 
|:-----:|:-----:|:-----:|:-----:|
| 67    | 45    | 23    | 01    |

Big endian storage:  
| 0x100 | 0x101 | 0x102 | 0x103 | 
|:-----:|:-----:|:-----:|:-----:|
| 01    | 23    | 45    | 67    |

When to worry about byte ordering
1. When binary data is communicated over a network between different machines
   - may cause issues if sending from little-endian to big-endian, or vice versa
   - you must use certain established conventions to combat this
2. When looking at the byte sequences representing integer data when inspecting machine level programs  
   - Example: 4004d3: 01 05 43 0b 20 00     add    %eax, 0x200b43(%rip)  
   - this line states that the hex byte sequence (01 05 43 0b 20 00) is a bytee-level representation of an instruction that adds a word of data to the value stored at an address computed by adding 0x200b43 to the current value of the program countre, the address of the next instruction to be executed. 
   - The natuaral way to write a byte sequence is to have the lowest-numbered byte on the left and the highest on the right. This is contrary to how we commonly write numbers
3. When programs are written using casting to allow objecst to be referenced according to a different data type

```c
int:	 39 30 00 00
float:	 00 e4 40 46
ptr:	 38 28 53 ec fe 7f 00 00
```

In this example, when converted to binary, the int and float hex values have overlapping values. See section on floating point values when I write notes for it.

## 2.1.4 Representing Strings
Strings are encoded by an array of characters terminated by the null (0) character
- There is a standard encoding used, most often ASCII
- Example: "12345" in the show_bytes program returns the following because `00` terminates the string:  
```c
31 32 33 34 35 00
```
- As in the example above, any number _x_ in ASCII is 0x3_x_
- The terminating byte has the value 0x00, so text is more portable from machine to machine

This code generates the following machine code on a Linux 64-bit machine:
```c
int sum(int x, int y) {
   return x + y;
}

55 48 89 e5 89 7d fc 89 75 f8 03 45 fc c9 c3
```
- This is different per machine type and OS, even if they use the same processor
- Binary code is not portable across machines or OSs
### The machine does not know anything about the original source program. It knows only how to read the sequence of bytes that make up the program.

### Unicode
>ASCII doesn't work for all languages, such as Chinese or Greek. It uses 32-bit representations of characters, but it has alternate codings to accomodate characters that require 1 or 2 bytes.

## 2.1.6 Intro to Boolean Algebra

| Symbol | Meaning |
|:------:|:-------:|
| \|     | OR      |
|  &     | AND     |
|  ~     | NOT     |
|  ^     | XOR     |

OPPOSITE
| - |   |
|:-:|:-:|
| 1 | 0 |
| 0 | 1 |

AND
| & | 0 | 1 |
|:-:|:-:|:-:|
| 0 | 0 | 0 |
| 1 | 0 | 1 |

OR
|\| | 0 | 1 |
|:-:|:-:|:-:|
| 0 | 0 | 1 |
| 1 | 1 | 1 |

NOT
| ~ | 0 | 1 |
|:-:|:-:|:-:|
| 0 | 0 | 1 |
| 1 | 1 | 0 |

- Claude Shannon linked Boolean algebra with digital logic in 1937.
- can use boolean algebra to operate on _bit vectors_
   - _bit vectors_ - strings of zeros and ones of some fixed length _w_  

Examples: 

```c
  0110      0110       0110
& 1100    | 1100     ~ 1100     - 1100
  ----      ----       ----       ----
  0100      1110       1010       0011
  ```

- can use bit vectors to represent finite sets  
Example: set union and intersection:  
A = [01101001] = [0,3,5,6]  
B = [01010101] = [0,2,4,6]
```c
    01101001
AND 01010101
    --------
    01000001
```
A ∩ B = [01000001] = [0,6]

A and B represented in bit vectors:  

| index |7|6|5|4|3|2|1|0|
|:-|-|-|-|-|-|-|-|-|
| A Bit representation|0|1|1|0|1|0|0|1|

| index |7|6|5|4|3|2|1|0|
|:-|-|-|-|-|-|-|-|-|
| B Bit representation|0|1|0|1|0|1|0|1|

| index |7|6|5|4|3|2|1|0|
|:-|-|-|-|-|-|-|-|-|
| A ∩ B Bit representation|0|1|0|0|0|0|0|1|

## 2.1.7 Bit-Level Operations in C

The C language uses & | ^ ~ characters for operations. The best way to convert from a C expression to a hex result is to convert to binary, perform the operation, then convert back to hex.
| C expression | Binary expression         | Binary result | Hexadecimal result |
|:-------------|:--------------------------|:--------------|:-------------------|
| ~0x41        | ~[0100 0001]              | [1011 1110]   | 0xBE               |
| ~0x00        | ~[0000 0000]              | [1111 1111]   | 0xFF               |
| 0x69 & 0x55  | [0110 1001] & [0101 0101] | [0100 0001]   | 0x41               |
| 0x69 | 0x55  | [0110 1001] & [0101 0101] | [0111 1101]   | 0x7D               |

### Masking
A mask is a bit pattern that indicates a selected set of bits within a word. For example:  

mask: 0xFF means the low-order byte of a word (1111 1111)  
If you perform a bit-level operation on bit vector x using 0xFF as a mask, you get the least significant byte of x, and all the other bytes are set to 0:  
```c
x =       0x89ABCDEF
mask =    0xFF
          ----------
result =  0x000000EF
```

## 2.1.8 Logical Operations in C
This means `&&`, `||`, and `!`, and they treat any nonzero arg as `true`, and 0 as `false`.  
- If the result of the expression can be determined by evaluating the first argument, then the second argument is not evaluated.  
- Example: `a && 5/a` never allows division by 0 because it returns 0 if `a = 0`
- Example: `p && *p++` never allows the dereferencing of a null pointer because if `p` exists and there is a value for p (`*p`), you can't change it 

| Expression    | Result |
|:--------------|:------:|
| !0x41         | 0x00   |
| !0x00         | 0x01   |
| !!0x41        | 0x01   |
| 0x69 && 0x55  | 0x01   |
| 0x69 \|\| 0x55  | 0x01   |


## 2.1.9 Shift Operations in C
Shift bit patterns to the lef and to the right.  
### Left shift
- x << k turns [x<sub>w-1</sub>, x<sub>w-2</sub>,..., x<sub>0</sub>] into [x<sub>w-k-1</sub>, x<sub>w-k-2</sub>,..., x<sub>0</sub>, 0...,0].
   - x is shifted k bits to the left (removing k significant bits), and adding k number of 0s at the end. The shift amount must be a value between 0 and w-1.
### Right shift
2 kinds of right shift:  
**Logical** - shift to the right k spaces and fill the left end with k zeros. Ex: [0,...,0,x<sub>w-1</sub>, x<sub>w-2</sub>,..., x<sub>k</sub>]  
**Arithmetic** - Useful for operating on signed integers. Shift to the right k spaces and fill the left with k repetitions of the most significant bit. Ex: [x<sub>w-1</sub>,..., x<sub>w-1</sub>, x<sub>w-2</sub>,..., x<sub>k</sub>]   
- C standards do not explicitly say whether to use logical or arithmetic right shifts, and different uses may cause portability problems. 
   - It is almost de facto that you use arithmetic for signed integer right shifts. For unsigned, use logical.
   - Java uses x >> k for arithmetic, x >>> k for logical.
- If you are shifting by a value where k >= w, most machines compute it as k mod w.
   - So, if you try to shift a 32-bit value like 0xFEDCBA98 by << 32, >> 36, or >> 40, then it shifts 0, 4, and 8 respectively.
- Addition and subtraction have higher order of precedence than shifts. For example, 1 << 2 + 3 << 4 = 1 << (2 + 3) << 4

## 2.2 Integer Representations
There are 2 different ways that bits can encode integers:  
1. nonnegative  
2. negative, zero, and positive integers

| Symbol                | Meaning            |         Formula                             | Example                                                                                |
|:---------------------:|:------------------:|:-------------------------------------------:|:--------------------------------------------------------------------------------------:|
| _B2T<sub>w</sub>(x)_  | Binary to 2C       | x<sub>i</sub> * 2<sup>i</sup> for all bits  | [0101] = 0 * 2<sup>3</sup> + 1 * 2<sup>2</sup> + 0 * 2<sup>1</sup> + 1 * 2<sup>0</sup> | 
| _B2U<sub>w</sub>(x)_  | Binary to Unsigned | | |
| _U2B<sub>w</sub>(x)_  | Unsigned to Binary | | |
| _U2T<sub>w</sub>(x)_  | Unsigned to 2C     |     | | 
| _T2B<sub>w</sub>(x)_  | 2C to Binary       | | |
| _T2U<sub>w</sub>(x)_  | 2C to Unsigned     | | |



## 2.2.1 Integral Data Types
Integral data types are ones that represent finite ranges of integers. 
- Have typical range of values for 32 and 64 bit programs
   - For example, long is 4 bits on 32 bit machine, 8 bits on 64 bit
- declare as `char`, `short`, `long`, `unsigned`, or `negative` (the default)
   - There is a symmetry in the positive and negative. For example, `short` has a minimum of -32,767 and a max of 32,767

## 2.2.2 Unsigned Encodings
- B2U is a function that means binary to unsigned
- _B2U<sub>w</sub>_(x) - there should be an --> over the x. w = the number of bits in the number.  
### Examples
_B2U<sub>4</sub>_([0101]) = 0 * 2<sup>3</sup> + 1 * 2<sup>2</sup> + 0 * 2<sup>1</sup> + 1 * 2<sup>0</sup>  
_B2U<sub>4</sub>_([1111]) = 1 * 2<sup>3</sup> + 1 * 2<sup>2</sup> + 1 * 2<sup>1</sup> + 1 * 2<sup>0</sup>   

The range of values represented by w bits:
- The least amount is [00...0]
- The greatest amount is [11...1]
- _UMAX<sub>w</sub>_ = ∑ \sum_{i=0}^w-1 2_i
- if w= 4, _UMAX<sub>4</sub>_ = _B2U<sub>4</sub>_([1111]) = 2<sup>4</sup> - 1 = 15

### Formal Definition
_B2U<sub>w</sub>:{0, 1} --> {0,...,_UMAX<sub>w</sub>_}  

### PRINCIPLE: Uniqueness of unsigned encoding
Function _B2U<sub>w</sub>_ is a bijection.  
- **bijection** - a function _f_ that goes 2 ways:
   1. Maps a value _x_ to a value _y_ where y = f(x)
   2. Operates in reverse because for every y, there is a unique value x too. So, f(x) = y.
      - This is provided by the inverse function f<sup>-1</sup> where x = f<sup>-1</sup>(y)
### BIG IDEA
- function _B2U<sub>w</sub>_ maps each bit vector of length w to a unique number between 2<sup>w</sup> - 1
- it also has an inverse called _U2B<sub>w</sub>_ (unsigned to binary) that maps each number in range 2<sup>w</sup> - 1 to a unique pattern of w bits
Every number between 0 and 2<sup>w</sup> - 1 has a unique encoding as a w-bit value.
- There is only 1 representation of the number 11 in 4-bit unsigned encoding: `1011`

## 2.2.3 Two's Complement encodings
This is a way to represent negative values.
- The MSB is interpreted to have negative weight
- Expressed as a function _B2T<sub>w</sub>_
- The name comes fromm the fact that for nonnegative x, we compute a w-bit representation of -x as 2<sup>w</sup> - x (a single two)
- Any value of 8 hexidecimal digits beginning with 8 - f means that it is negative bc it starts with a 1

### PRINCIPLE
For vector x = [x<sub>w-1</sub>, x<sub>w-2</sub>, ..., x<sub>0</sub>]:
_B2T<sub>w</sub>_(x) = -x<sub>w-1</sub>2<sup>w-1</sup> + ∑ \sum_{i=0}^w-2 2_i

- The MSB is also called the 'sign bit', and its weight is -2<sup>w-1</sup>
   - when it is 0, it is nonnegative, when 1, it is negative

### Examples:
_B2T<sub>4</sub>_([0101]) = -0 * 2<sup>3</sup> + 1 * 2<sup>2</sup> + 0 * 2<sup>1</sup> + 1 * 2<sup>0</sup> = 0 + 0 + 0 + 1 = 1  
_B2T<sub>4</sub>_([1111]) = -1 * 2<sup>3</sup> + 1 * 2<sup>2</sup> + 1 * 2<sup>1</sup> + 1 * 2<sup>0</sup> = -8 + 4 + 2 + 1 = -1  

The range of values represented by w bits:
- the least amount is [10...0], where the first bit is 1 so it is negative, but the others are all 0s
   - This is _TMIN<sub>w</sub>_ = -2<sup>w-1</sup>
- the greatest value is [01...1], where the first is 0 and the rest are all 1s
   - This is _TMAX<sub>w</sub>_ = -2<sup>w-1</sup> -1
   - Example: _TMIN<sub>4</sub>_ = _B2T<sub>4</sub>_([1000]) = -2<sup>3</sup> = -8
   - _TMAX<sub>4</sub>_ = _B2T<sub>4</sub>_([0111]) = 2<sup>2</sup> + 2<sup>1</sup> + 2<sup>0</sup> = 4 + 2 + 1 = 7
- every number within the representable range has a unique encoding as a w-bit twos-complement number
### PRINCIPLE: Uniqueness of twos-complement encoding
Function _B2T<sub>w</sub>_ is a bijection. 
- _T2B<sub>w</sub>_ (twos complement to binary) is the inverse of _B2T<sub>w</sub>_
- Two's complement is assymetric: | _TMmin_ = | _TMax_ | + 1.
   - For example, a word with 8 bits _TMax_ is 0x7F (127), while its _TMmin_ is 0x80 (-128)
   - This occurs because the bit patterns using 1 represent negative numbers, while 0s represetn nonnegative, so 0s can represent one less positive number
   - When twos complement is converted to unsigned, all of the patterns that represent negative numbers become positive, so they are 1 value less than in TC

In some circumstances, you must have fixed-size integers (using internet protocols that have specs)
- In the C stdint.h package, you can use the intN_t and unintN_t to specify how many bits it uses **TO INCREASE PORTABILITY**
- For example, use `unit16_t` for an unsigned 16-bit 
- Formatted printing uses macros to expand into format strings to fix how it is compiled

```c
printf("x = %" PRId32 ", y = %" PRIu64 "\n", x, y);
 
 ...

 printf("x = %d, y = %1u\n", x, y);
 ```
- C file `<limits.h>` defines a set of constants that delimits the ranges of the different integer data types for the particular machine where the compiler is running
   - defines constants INT_MAX, INT_MIN, and UINT_MAX for the range of signed and unsigned ints

```c
short x = 12345;
short mx = -x;

show_bytes((byte_pointer) &x, sizeof(short));
show_bytes((byte_pointer) &mx, sizeof(short));
```

## 2.2.4 Conversions between Signed and Unsigned
Be careful when you are converting from signed to unsigned. The following example shows converting from twos complement -12345 to unsigned 53191:
```c
short int v = -12345;
unsigned short uv = (unsigned short) v;
printf("v = %d, uv = %u\n", v, uv);

RETURNS:

Convert signed to unsigned
v = -12345, uv = 53191
```
- The bit sign for -12345 twos complement is 1100 1111 1100 0111
- The bit sign for 53191  twos complement is 1100 1111 1100 0111, too.
- So, the bits aren't changing, only how they are interpreted is changing

### Converting from Twos-Complement to Unsigned (casting)
We currently have the following:
- _U2B<sub>w</sub>(x)_, when 0 <= x <= _UMax_, returns unique unsigned representation of x
- _TB2<sub>w</sub>(x)_, when _TMin<sub>w</sub>_ <= x <= _TMax<sub>w</sub>_, returns unique twos-complement representation of x  

Now we can define _T2U<sub>w</sub>_ as _T2U<sub>w</sub>(x) = _B2U<sub>w</sub>(T2B<sub>w</sub>(x))_
- Accepts number _TMin<sub>w</sub>_ <= x <= _TMax<sub>w</sub>_
- Argument is a twos-complement and the result is unsigned  
- The reverse of that is _U2T<sub>w</sub>(x) = _B2U<sub>w</sub>(U2B<sub>w</sub>(x))_
   - Previous code shows that _T2U_<sub>16</sub>(-12345) = 53,191 and _U2T_<sub>16</sub>(53191) = 12,345   
   - Also, 53,191 + 12,345 = 65,536 = 2<sup>16</sup>

### PRINCIPLE: Conversion from twos complement to unsigned
For x such that _TMin<sub>w</sub>_ <= x <= _TMax<sub>w</sub>_:  

_T2U<sub>w</sub>(x) = 
- x + 2<sup>w</sup>, x < 0
   - Example: _T2U<sub>16</sub>(-12,345) =  = -12,345 + 2<sup>16</sup> = 53,191
- x, x >= 0

### DERIVATION: Conversion from twos complement to unsigned
_B2U<sub>w</sub>(T2B<sub>w</sub>(x))_ = _T2U<sub>w</sub>(x)_ = x<sub>w-1</sub> + 2<sup>w</sup>

### PRINCIPLE: Unsigned to twos-complemment conversion
For _u_ such that 0<= u <= UMax<sub>w</sub>:

_U2T<sub>w</sub>(u) = 
- u, when u <= _TMax<sub>w</sub>_
- u - 2<sup>w</sup>, when u > _TMax<sub>w</sub>_

### DERIVATION: Unsigned to twos-complement conversion
_U2T<sub>w</sub>(u)_ = -u<sub>w-1</sub>2<sup>w</sup> + u  
- bit u<sub>w-1</sub> determines whether or not u is greater than _TMax<sub>w</sub>_ = 2<sup>w-1</sup> - 1

Summary
- For values greater than 0 and less than the _TMax_, the conversion number is x.
- For values outside this range, you either add or subtract 2<sup>w</sup>

## 2.2.5 Signed versus Unsigned in C
Most machines use twos-complement, and most machines use signed by default.
- constant 12345 = 0x1A2Bu = 0x1A2BU  

```c
int x = -1;
unsigned u = 2147483648; /* 2 to the 31st */

printf("x = %u = %d\n", x, x);
printf("u = %u = %d\n", u, u);

RETURNS

x = 4294967295 = -1
u = 2147483648 = -2147483648
```
_T2U<sub>32</sub>_(-1) = _UMax<sub>32</sub>_ = 2<sup>32</sup> = `printf("x = %u = %d\n", x, x);`  
_U2T<sub>32</sub>_(2<sup>31</sup>) = 2<sup>31</sup> - 2<sup>32</sup> = -2<sup>31</sup> = _TMin<sub>32</sub>_ = `printf("u = %u = %d\n", u, u);`

- when an operation is performed with a signed and unsigned, C casts the signed to unsigned automatically

## 2.2.6 Expanding the Bit Representation of a Number
Conversion is different when it involves different word sizes. Converting from smaller to larger should always be possible.
- To convert an unsigned to a larger data type, add leading 0s - called _zero extension_
- To convert a twos-complement number to a larger data type, use _sign extension_, which is adding leading copies of the MSB to the number
### Examples
Extending the word size from w=3 to w=4
```c
[101]  = -4 + 1 = -3
[1101] = -8 + 4 + 1 = -3

ALSO...
[111]  = -1 = -4 + 2 + 1
[1111] = -1 = -8 + 4 + 2 + 1
```

```c

short sx = -12345;         /* -12345 */
unsigned short usx = sx;   /* 53191 */
int x = sx;                /* -12345 */
unsigned ux = usx;         /* 53191 */

/* 16-bit word */
printf("sx  = %d:\t", sx);
show_bytes((byte_pointer) &sx, sizeof(short));

printf("usx = %u:\t", usx);
show_bytes((byte_pointer) &usx, sizeof(unsigned short));

/* 32-bit word */
printf("x   = %d\t", x);
show_bytes((byte_pointer) &x, sizeof(int));

printf("ux  = %u:\t", ux);
show_bytes((byte_pointer) &ux, sizeof(unsigned));

RETURNS

sx  = -12345:	 c7 cf
usx = 53191:	 c7 cf
x   = -12345	 c7 cf ff ff
ux  = 53191:	 c7 cf 00 00
```

### DERIVATION: Expansion of a twos-complement number by sign extension.  
Let w' = w + k

_B2T<sub>w+k</sub>_(**[x<sub>w-1</sub>, ..., x<sub>w-1</sub>**, x<sub>w-1</sub>, x<sub>w-2</sub>, ..., x<sub>0</sub>]) = _B2Tx<sub>w</sub>_([x<sub>w-1</sub>, x<sub>w-2</sub>, ..., x<sub>0</sup>])

## 2.2.7 Truncating Numbers
Reduce the number of bits  

The following code casts x to be a short truncates a 32-bit int into a 16-bit short.
```c
int x = 53191;
short sx = (short) x; /* -12345 */
int y = sx;           /* -12345 */
```
### PRINCIPLE: Truncation of an unsigned number
Let x = _B2U<sub>k</sub>(x)_ and let x' = _B2U<sub>k</sub>(x)_. x' = x mod 2<sup>k</sup>

### PRINCIPLE: Truncation of a twos-complement number
x = _U2T<sub>k</sub>(x mod 2<sup>k</sup>)

- One trick is to never use unsigned numbers 

## 2.3 Integer Arithmetic

### 2.3.1 Unsigned Addition
When 0 <= x, y < 2<sup>w</sup>, 0 <= x + y < 2<sup>w11</sup> - 2  
- So, with 4 bits, x or y can range from 0 - 15, but the sum can range from 0 - 30.
- 4-bit example: 0 <= x + y < 2<sup>w=1</sup> - 2    =    0 <= x + y < 2<sup>5</sup> - 2   =   0 <= x + y < 32 - 2   =   0 <= x + y < 32 - 2
- _word size inflation_ - If we retain this sum and add it to another value, it would require w + 2 bits  

#### Example
To truncate when the w-bit word is longer than 2<sup>w-1</sup>, you just discard any bits with a weight higher than 2<sup>w-1</sup> using modulo math.  
```
x = 9   [1001]
y = 12  [1100]

1. x + y = 21 = [10101]
2. Discard highest order bit to get [0101] = 5
3. (original sum) mod (bit weight of dropped bit) = unsigned number representation
21 mod 16 = 5
```
#### Overflow
Defining operation +<sup>u</sup><sub>w</sub> in theory and then with 4 bits where x = 9 and y = 9 to demonstrate overflow:  

| Normal                 | Overflow |
|:----------------------:|:--------:|
| x + y < 2<sup>w</sup>  | 2<sup>w</sup> <= x + y < 2<sup>w+1</sup> |
| 9 + 9 < 16             | 16 <= 9 + 9 < 32 |


x +<sup>u</sup><sub>w</sub> = x + y 