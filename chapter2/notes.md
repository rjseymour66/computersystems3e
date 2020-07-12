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

