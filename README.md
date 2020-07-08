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

### 1.5 Caches Matter

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

**Memory heirarchy**  
The smaller the component, the faster and more expensive.  
0. CPU Registers - hold words from retrieved from cache memory
1. L1 cache (SRAM) - holds cache lines retrieved from L2 cache
2. L2 cache (SRAM) - holds cache lines retrieved from L3 cache
3. L3 cache (SRAM) - holds cache lines retrieved from memory
4. Main memory (DRAM) - holds disk blocks retrieved from local disk
5. Local secondary storage - hold files retrieved from disks on remote network servers 

### 1.6 Storage Devices Form a Heirarchy
