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

