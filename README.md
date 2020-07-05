# Chapter 1: A Tour of Computer Systems

## 1.1 Information is Bits + Context

Programmers create source programs/files 
- **EVERYTHING IN A COMPUTER IS REPRESENTED BY BITS** source file is a sequence of bits, organized into 8 bit chunks called bytes 
   - context controls whether they represent an integer, char, or machine instruction
- text is represented using ASCII - represents each character with a byte-size value
   - ex: h e l l o = 104 101 108 108 111
   - files w/only ASCII characters are called text files, others are binary files

## Programs are Translated by Other Programs into Different Forms

To run a C program on a computer, the source file must be translated into low-level machine language. Machine language instructions are packaged in an _executable object program_, also known as an _executable object file_.

**Compile driver**
1. **Preprocessing phase** - translates .c file into modified source .i text file (another C program file). Modifies original .c program with directives of the language?
2. **Compilation phase** - translates .i file into assembly program .s text file. Assembly language. Creates common output language for different compilers for different high-level languages.
3. **Assembly phase** - translates .s file into machine language instructions. Stores a _relocatable object program_ in the hello.o object file (a binary file). 
4. **Linking phase** - merges any calls from precompiled object .o file to another precompiled object .o file. Creates the executable object file that is loaded into memory and executed by computer system.

### GNU project
