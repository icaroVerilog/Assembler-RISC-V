<h1 align=center>
<img height="100em" src="https://github.com/IcaroM-CdC/Assembler-RISC-V/blob/stable/imgs/riscv.png" />
</h1>


### RISC-V is a open source instruction set architecture (ISA), developed by the university of California. This project consists in the development of an assembler for the RISC-V 32 bits ISA, made in c++, allows the conversion of the assembly language into machine language

<br>
<br>
<br>
<br>

## The assembler
The assembler are developed in c++ 14, using boost library. The assembler supports some of RISC-V instructions

<br>
<br>

## Supported instructions

actually, the assembler supports a small number of instructions: ADD(R), SUB(R), AND(R), OR(R), XOR(R), ADDI(I), ANDI(I), ORI(I), SLL(R), SRL(R)

<br>
<br>

## ::man_technologist:: Getting started

First, we need to install boost lib for c++. the Installation depends of the operating system in use.

``` bash

# cloning the repository
git clone https://github.com/IcaroM-CdC/Assembler-RISC-V.git

```

``` bash

# compiling the binaries
make compile

# executing
./assembler input_file.asm -o output_file.txt

```
if you want to print the assembled instructions, in terminal run the command

``` bash

./assembler input_file.asm

```


