CC = g++
FILES = src/main.cpp src/instructions/riscv/convert_methods/convert_methods.cpp src/instructions/riscv/instruction_parser/instruction_parser.cpp src/misc/auxiliar_methods/auxiliar_methods.cpp src/input_output/file_controller/file_controller.cpp

B = src/instructions/riscv/instructions_assembler/instructionsB/instructionsB.cpp
S = src/instructions/riscv/instructions_assembler/instructionsS/instructionsS.cpp
P = src/instructions/riscv/instructions_assembler/instructionsP/instructionsP.cpp
R = src/instructions/riscv/instructions_assembler/instructionsR/instructionsR.cpp
I = src/instructions/riscv/instructions_assembler/instructionsI/instructionsI.cpp
L = src/instructions/riscv/instructions_assembler/instructionsI/instructionsI_load.cpp

ACCUMULATORS = src/accumulator/instruction_accumulator.cpp src/accumulator/label_accumulator.cpp

ELF_GENERATOR = src/elf_generator/elf_generator.cpp src/elf_generator/riscv_elf/riscv_elf.cpp


compile: ${FILES}
	${CC} ${FILES} ${S} ${P} ${R} ${I} ${L} ${B} ${ACCUMULATORS} ${ELF_GENERATOR} -o compiled/assembler

run: 
	./compiled/assembler example.asm -o teste.txt