# Chapter 1: A Tour of Computer Systems

## 1.1 Information is Bits + Context

Programmers create source programs/files 
- **EVERYTHING IN A COMPUTER IS REPRESENTED BY BITS** source file is a sequence of bits, organized into 8 bit chunks called bytes 
   - context controls whether they represent an integer, char, or machine instruction
- text is represented using ASCII - represents each character with a byte-size value
   - ex: h e l l o = 104 101 108 108 111
   - files w/only ASCII characters are called text files, others are binary files

## 1.2 Programs are Translated by Other Programs into Different Forms

To run a C program on a computer, the source file must be translated into low-level machine language. Machine language instructions are packaged in an _executable object program_, also known as an _executable object file_.

**Compile driver**
1. **Preprocessing phase** - translates .c file into modified source .i text file (another C program file). Modifies original .c program with directives of the language?
2. **Compilation phase** - translates .i file into assembly program .s text file. Assembly language. Creates common output language for different compilers for different high-level languages.
3. **Assembly phase** - translates .s file into machine language instructions. Stores a _relocatable object program_ in the hello.o object file (a binary file). 
4. **Linking phase** - merges any calls from precompiled object .o file to another precompiled object .o file. Creates the executable object file that is loaded into memory and executed by computer system.

### GNU project
GNU - GNU is not Unix  
- Developed an environment with all major components of a Unix OS except the kernel (that is Linux)
- Includes the following:
   - EMACS
   - GCC compiler
   - GDB debugger
   - assembler
   - linker
   - utils for manipulating binaries

## 1.3 It Pays to Understand how Compilation Systems Work

- Optimizing program performance
   - Know when to use certain loops, structures, etc.
- Understanding link-time errors
   - Cannot resolve a reference
   - Difference in static variable and global variable
   - Difference in static library and dynamic library
   - Why don't some errors appear until runtime
- Avoiding security holes
   - _buffer overflow vulnerabilities_ are the cause of many security issues in network and Internet servers
   - Must understand the need to restrict quantity and forms of data accepted from untrusted sources
   - Linked to how data and control information are stored on the program stack

## 1.4 Processors Read and Interpret Instructions Stored in Memory

The shell is an application program/command-line interpreter that accepts commands. If the shell doesn't understand the first word of the command line, then it assumes it is an executable file that it should load and run.  

### Hardware Organization of a System
Buses - carry bytes of information back and forth between components of the computer. Transfer data in fixed-size chunks of bytes called _words_. Word size is a system parameter, most are either 4 or 8 bytes (32 or 64 bits).

### I/O Devices
Connect computer to the outside world (keyboard, monitor, disk storage, etc). Disk drive is for long-term storage of data and programs.  
I/O devices are connected to the I/O bus by a controller (chip sets in the device itself or in the system's motherborad) or adapter (card that plugs into a slot on the motherboard). Putpose is to transfer information back and forth between the I/O bus and I/O device.

### Main Memory
Temporary storage device that holds the program and the data that it manipulates while the processor is executing the program. Consists of DRAM (dynamic random access memory) chips.  
Organized as a linear array of bytes with its own address. Data types and the amount of bytes they require vary from machine to machine.

### Processor
Central Processing Unit (CPU). Engine that interprets or executes instructions stored in main memory. Uses a word-size storage device (register) called the program counter (PC). The PC points to machine-language instruction in main memory.  

When the system has power, the processor executes the instruction that the PC is pointing to and updates the program to point to the next instruction.  

Uses _instruction set architecture_ to execute instructions in a strict sequence. Ex:
1. Processor reads the instruction from memory pointed at by the PC
2. Then interprets the bits in the instruction
3. Then performs the operation
4. Then updates the PC to point to the next instruction.  

Uses the main memory, register file, and arithmetic/logic unit (ALU) to complete instructions similar to the following:
- Load - copy byte from main memory to a register. Overwrites existing data in register.
- Store - copy byte or word from register to main memory. Overwrites existing data in main memory location.
- Operate - copy contents of 2 registers to ALU, perform operation on the words, store results in a register. Overwrites existing data in register.
- Jump - extract a word from the instruction and copy into the PC. Overwrites the existing value in the PC.  

### Running the hello world program
High-level overview of what happens when you run hello-world.c: 
1. Shell program is running, waiting for a command
2. I type ./hello into the shell. As I type, the shell reads each character I type into a register and stores it in memory.
3. I hit enter, and that is the shell's cue that I have finished typing my instruction. 
4. The shell loads the executable hello file by executing a sequence of instructions that takes hello from the object file into main memory.
5. Uses DMA (Direct Access Memory) to put data directly from disk to main memory. 
6. After code and data in hello object file is loaded into main memory, the processor executes the machine-language in the program's main routing/method.
   - Copy the bytes in the 'hello world\n' string from memory to register file, then to display device

## 1.5 Caches Matter

Lots of copying happens
- The program is copied from disk to main memory, then copied to the processor, then copied to the display device.  
- Larger storage devices are expensive and slower
- _Processor-memory gap_ - the processor reads from the file registers faster than from the main memory

Cache memory
- Benefits of both large memory and easy access by exploiting locality so that you can perform memory operations quickly
- Temporary storage for information that the processor is likely to need again soon
- Created to lessen the _processor-memory gap_
- **L1 cache** - uses SRAM (standard access random memory) is on the processor chip, holds 10s of 1000s of bytes and can be accessed nearly as quickly as at register file
- **L2 cache** - uses SRAM (standard access random memory) 100s of 1000s - Mils of bytes, connected to the processor by a special bus. The L2 is not as fast as accessing the L1 cache, but it is much faster than accessing the main memory.
- Some newer systems even have an **L3 cache**

## 1.6 Storage Devices Form a Hierarchy
Since computers spend most of their time copying data between memory, I/O devices, and CPU registers, storage is arranged in a hierarchy. Storage at one level serves as a cache for storage at the next lower level. The smaller the component, the faster and more expensive.  

0. CPU Registers - hold words from retrieved from cache memory
1. L1 cache (SRAM) - holds cache lines retrieved from L2 cache
2. L2 cache (SRAM) - holds cache lines retrieved from L3 cache
3. L3 cache (SRAM) - holds cache lines retrieved from memory
4. Main memory (DRAM) - holds disk blocks retrieved from local disk
5. Local secondary storage - hold files retrieved from disks on remote network servers 

## 1.7 The Operating System Manages the Hardware
The OS is the layer of software between the application programm and the hardware. Anytime the application wants to manipulate the hardware, it must go through the OS.  

OS has 2 purposes:
1. Protect the hardware from misuse by runaway applications
2. Provide applications with simple and uniform mechanism for manipulating complicated and varying low-level hardware devices.

OS fulfills these purposes using (notice how they build on each other):
- Files - abstraction for I/O devices
- Virtual memory - abstraction for the main memory, and I/O devices
- Processes - abstraction for the processor, main memory, and I/O devices

**Processes**  
A _process_ is the OS's abstraction for running a program. Multiple processes run concurrently on the same system, meaning that the instructions of one process are interleaved with the instructions of another process becuase there are more processes to run that there are CPUs to run them. Processes provide the illusion that the program that is running is the only program in the system, and it has exclusive use of the processor, main memory, and I/O devices. The OS makes this happen using _context switching_. 

OS keeps track of the **context**, the state information that the process needs in order to run
- current values of the PC (program counter)
- the register file
- the contents of the main memory

OS executes code for a single process, transfers control to some new process, and performs a _context switch_
1. Saving the context of the current process
2. Restoring the context of the new process
3. Passing control to the new process

The kernel
- The kernel is a collection of code and data structures that the system uses to manage all processes
- Kernel is the portion of the OS code that is always resident in memory
- Manages transistion from one process to another
- When an app requires action by the OS, it makes a _system call_ instruction and passes control to the kernel
   - The kernel performs the operation and returns back to the application

### Unix, Posix, and the Standard Unix Specification  
- Unix was created at Bell labs in 1969
- Used heirarchical file system and user-level shell
- Called Unix as a joke against Multics, the complex OS it replaced
- Bell made source code available to universities
   - Berkeley created 4xBSD
- When vendors started adding incompatible features, the IEEE sponsored an effort to standardize Unix and created Posix
- Most recent update to that is the Standard Unix Specification

**Threads**  
A process that consists of multiple execution units that each run in the context of the process and share the same code and global data
- Easier to share data between multiple threads than between multiple processes
- Threads are typically more efficient than processes
- Way to make programs run faster when multiple processors are available

**Virtual Memory**  
Virtual memory is an abstraction that provides each process with the illusion that it has exclusive use of the main memory.
- _virtual address space_ - each process has this uniform view of memory  
- General idea is to store the contents of a process's virtual memory on disk and then use the main memory as a cache for the disk
   - To work, the hardware must translate every address generated by the processor

Parts of virtual memory (lowest address to highest)
- _Program code and data_ - Fixed in size once the process begins running. Code and data areas are initialized directly from the contents of an executable object file.
- _Heap_ - Run-time heap. Expands and contrasts dynamically at run time due to calls to the C standard library routines such as malloc and free. 
- _Shared libraries_ - Near the middle of the address space. Includes code and data for shared libraries such as the C standard library and math library. 
- _Stack_ or _user stack_ - At the top of the user's virtual address space. Used to implement function calls.
   - Expands and contracts dynamically during the execution of the program.
   - When you call a function, it expands
   - When you return a function, it contracts
- _Kernel virtual memory_ - Top region of address space. Application programs cannot access this. Apps must invoke the kernel to perform operations such as reads or writes.

**Files**  
A sequence of bytes.
- Every I/O device is modeled as a file.
   - Provides applications with a uniform view of all the varied I/O devices that might be contained in the system.
- All input and output is performed by reading and writing files using _Unix I/O_ system calls.

## 1.8 Systems Communicate with Other Systems Using Networks
Outside networks can be seen as another I/O device. The internet is based on copying information over a network.  

Remote hello.c example over telnet:
1. Log in to a remote machine
2. Run a shell
   - The shell is waiting for a command
3. We type 'hello'
4. Client sends string to server
5. Server receives string, passes along to remote shell program
6. Remote shell runs hello and passes output back to server
7. Server sends the output across network to telnet client
8. Client prints output string on local terminal

## 1.9 Important themes

**Amdahl's law**  
When we speed up one part of a system, the effect on the overall system performance depends on both how significant this part was and how much it sped up. To significantly speed up the entire system, we must improve the speed of a very large fraction of the overall system.

_T_<sub>old</sub> = total time required to execute a system  
x = part of execution time that a part of the system requires
k = improve performance of x by this amount

Previous execution time:  
x_T_<sub>old</sub>  

New execution time:  
_T_<sub>old</sub> / k  

_T_<sub>new</sub> = (1 -x)_T_<sub>old</sub> + (x_T_<sub>old</sub>) / k

So, the net speedup S = _T_<sub>old</sub> / T<sub>new</sub>:  
S = 1 / [(1 - x) + x / k]  

Example:

If a part of the system that initially consumed 60% of the time is sped up by 3.  
- x = 0.6
- k = 3  

S = 1 / [(1 - .6) + .6 / 3] = 1 / 0.4 + 0.2 = 1.67  

So, the part that consumed 60% is sped up by 3, but the entire system is only sped up by 1.67.

**Concurrency and Parallelism**    
_Concurrency_ - system with mutliple, simultaneous activities  
_Parallelism_ - the use of concurrency to make the system run faster  

Parallelism can be exploited at the following 3 levels of abstraction (highest-level to lowest):
1. Thread-level concurrency
- Originally, concurrency was simulated by a single computer rapidly switching processes
   - Called uniprocessor system
   - Allows multiple users to interact with the same system at once (i.e. web server), or have multiple windows open doing things
- Multiprocessor - a system consisting of multiple processors all under the control of a single operating system kernel
   - more common recently due to multi-core processors and hyperthreading
   - multi-core processors have several CPUs (called cores) integrated onto a single integrated-circuit chip. 
- **Common architecture** - 4 CPU cores, each with its own L1 and L2 caches. L1 cache split in 2 (1 part for data, 1 part for recently fetched instructions)
   - share higher level caches and the main memory interface
- _hyperthreading_ - also called simultaneous mutli-threading - allows a single CPU to execute multiple flows of control. 
   - it is having multiple parts of some parts of the CPU and single copies of others
   - decides which thread to execute on a cycle-by-cycle basis
   - CPU takes better advantage of its processor resources
- Improve system performance
   - Reduces the need to simulate concurrency when performing multiple tasks
   - Can run a single application program faster, but only if that program is expressed in terms of multiple threads that can effectively execute in parallel. 
2. Instruction-level parallelism
- Modern proessors can execute multiple instructions at one time 
- Multiple instructions per clock cycle (2 - 4 per cycle)
- An instruction may take 20 cycles or more to complete, but they can process as many as 100 instructions at a time using pipelining
- _Pipelining_ - actions required to execute an instruction are partitined into different steps and the processor hardware is organized as a series of stages, each performing one of these steps.
   - the stages can operate in parallel. So, they can work on different stages at different times
- _Superscalar processors_ - processors that sustain executino rates faster than 1 instruction per cycle
3. Single-Instruction, Multiple-Data (SIMD) Parallelism
- modern processors have special hardware that allows a single instruction to cause multiple operations to be performed in parallel
- mostly used to improve speed for applications that process image, sound, and video

**The Importance of Abstractions in Computer Systems**
- Ability to provide abstract represetnations at different levels to hide the complexity of the actual implementations
- Example: instruction set architecture
   - provides an abstraction of the actual processor hardware
   - the abstraction allows machine-code programs to behave as if it were executed on a processor that performs just one instruction at a time, while the actual hardware is executing multiple instructions in parallel
- OS abstractions
   - files - I/O devices
   - virtual memory - program memory
   - processes - running a program
   - virtual machine - abstraction of entire computer, including the operatin system, the processor, and the programs

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
- Hex numbers start with **Ox** or **OX**. A - F could be upper or lowercase
   - FA1D37B<sub>16</sub> = OxFA1D37B = Oxfa1d37b
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

## Converting from hexidecimal to decimal
Multiply each of the hexadecimal digits by the appropriate power of 16, according to its place using 0 index.

For example, Ox7AF is:  
7 * 16<sup>2</sup> + 10 * 16 + 15 = 
7 * 256 + 10 * 16 + 15 =
1,792 + 160 + 15 = 1,967