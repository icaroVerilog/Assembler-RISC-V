<h1 align=center>
<img height="100em" src="https://github.com/IcaroM-CdC/Assembler-RISC-V/blob/stable/imgs/riscv.png" />
</h1>


### RISC-V is a open source instruction set architecture (ISA), developed by the university of California. This project consists in the development of an assembler for the RISC-V 64 bits ISA, made in c++, allows the conversion of the assembly language into machine language

<br>
<br>

## :man_technologist: Project roadmap

This project aims create a fully funcional assembler, who assemble to RISCV, MIPS and ARM. Actually the project focuses 
on riscv isa, but is not the only objective, we planning start the implementation of another ISA's mentioned above in the near future. Also, we plan implement several optmizations like branchless, multithreading and others kinds of pratices to improve the assembler performance

<h1 align=center>
<img height="650vh" width="100%" src="https://github.com/IcaroM-CdC/Assembler-RISC-V/blob/development/imgs/roadmap.png"/>
</h1>

## General registers

The RV32I base integer ISA includes 32 registers, named `x0` to `x31`. The
program counter `PC` is separate from these registers, in contrast to other
processors such as the ARM-32. The first register, `x0`, has a special function:
Reading it always returns 0 and writes to it are ignored. As we will see later,
this allows various tricks and simplifications.

In practice, the programmer doesn't use this notation for the registers. Though
`x1` to `x31` are all equally general-use registers as far as the processor is
concerned, by convention certain registers are used for special tasks. In
assembler, they are given standardized names as part of the RISC-V **application
binary interface** (ABI). This is what you will usually see in code listings. If
you really want to see the numeric register names, the `-M` argument to objdump
will provide them.
<br>

<table>
<thead>
  <tr>
    <th align=center>Register</th>
    <th align=center>ABI</th>
    <th align=center>Use by convention</th>
    <th align=center>Preserved</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td align=center>x0</td>
    <td align=center>zero</td>
    <td>hardwired to 0, ignores writes</td>
    <td align=center>N/A</td>
  </tr>
  <tr>
    <td align=center>x1</td>
    <td align=center>ra</td>
    <td>return address for jumps</td>
    <td align=center>NO<br></td>
  </tr>
  <tr>
    <td align=center>x2</td>
    <td align=center>sp</td>
    <td>stack pointer</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x3</td>
    <td align=center>gp</td>
    <td>global pointer</td>
    <td align=center>N/A<br></td>
  </tr>
  <tr>
    <td align=center>x4</td>
    <td align=center>tp</td>
    <td>thread pointer</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x5</td>
    <td align=center>t0</td>
    <td>temporary register 0</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x6</td>
    <td align=center>t1</td>
    <td >temporary register 1</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x7</td>
    <td align=center>t2</td>
    <td>temporary register 2</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x8</td>
    <td align=center>s0 or fp</td>
    <td>saved register 0 or frame pointer</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x9</td>
    <td align=center>s1</td>
    <td>saved register 1</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x10</td>
    <td align=center>a0</td>
    <td>return value or function argument 0</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x11</td>
    <td align=center>a1</td>
    <td>return value or function argument 1</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x12</td>
    <td align=center>a2</td>
    <td>function argument 2</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x13</td>
    <td align=center>a3</td>
    <td>function argument 3</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x14</td>
    <td align=center>a4</td>
    <td>function argument 4</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x15</td>
    <td align=center>a5</td>
    <td>function argument 5</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x16</td>
    <td align=center>a6</td>
    <td>function argument 6</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x17</td>
    <td align=center>a7</td>
    <td>function argument 7</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x18</td>
    <td align=center>s2</td>
    <td>saved register 2</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x19</td>
    <td align=center>s3</td>
    <td>saved register 3</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x20</td>
    <td align=center>s4</td>
    <td>saved register 4</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x21</td>
    <td align=center>s5</td>
    <td>saved register 5</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x22</td>
    <td align=center>s6</td>
    <td>saved register 6</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x23</td>
    <td align=center>s7</td>
    <td>saved register 7</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x24</td>
    <td align=center>s8</td>
    <td>saved register 8</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x25</td>
    <td align=center>s9</td>
    <td>saved register 9</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x26</td>
    <td align=center>s10</td>
    <td>saved register 10</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x27</td>
    <td align=center>s11</td>
    <td>saved register 11</td>
    <td align=center>YES</td>
  </tr>
  <tr>
    <td align=center>x28</td>
    <td align=center>t3</td>
    <td>temporary register 3</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x29</td>
    <td align=center>t4</td>
    <td>temporary register 4</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x30</td>
    <td align=center>t5</td>
    <td>temporary register 5</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>x31</td>
    <td align=center>t6</td>
    <td>temporary register 6</td>
    <td align=center>NO</td>
  </tr>
  <tr>
    <td align=center>PC</td>
    <td align=center>(none)</td>
    <td> program counter</td>
    <td align=center>N/A</td>
  </tr>
</tbody>
</table>


_Registers of the RV32I. Based on RISC-V documentation and Patterson and
Waterman "The RISC-V Reader" (2017)_

As a general rule, the **saved registers** `s0` to `s11` are preserved across
function calls, while the **argument registers** `a0` to `a7` and the
**temporary registers** `t0` to `t6` are not.  The use of the various
specialized registers such as `sp` by convention will be discussed later in more
detail.


<br>
<br>

## 🛠 The assembler
The assembler are developed in c++ 14, using boost library. The assembler supports some of RISC-V RV32LI instructions

<br>
<br>

<table>
<thead>
  <tr>
    <th>Version</th>
    <th colspan="7">Suported instructions</th>
  </tr>
</thead>
<tbody>
  <tr>
    <td></td>
    <td align=center>R</td>
    <td align=center>I</td>
    <td align=center>S</td>
    <td align=center>B</td>
    <td align=center>U</td>
    <td align=center>J</td>
    <td align=center>P</td>
  </tr>
  <tr>
    <td align=center>1.1</td>
    <td align=center>ADD, SUB, AND<br>OR, XOR, SLL, SRL<br></td>
    <td align=center>ADDI, ANDI, ORI</td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
  </tr>
  <tr>
    <td align=center>1.1</td>
    <td align=center>ADD, SUB, AND<br>OR, XOR, SLL, SRL<br></td>
    <td align=center>ADDI, ANDI, ORI<br>XORI, SLLI, SRLI<br>LB, LH, LW<br></td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
  </tr>
  <tr>
    <td align=center>DEV</td>
    <td align=center>ADD, SUB, AND<br>OR, XOR, SLL, SRL<br></td>
    <td align=center>ADDI, ANDI, ORI<br>XORI, SLLI, SRLI<br>LB, LH, LW, LD<br></td>
    <td align=center>SB, SH, SW, SD</td>
    <td align=center>BEQ, BNE, BLT, BGE, BLTU, BGEU</td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
    <td align=center>N/A</td>
  </tr>
</tbody>
</table>

<br>

## :man_technologist: Getting started

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
