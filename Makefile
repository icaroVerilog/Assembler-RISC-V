CC = g++
FILES = src/main.cpp src/convert_methods/convert_methods.cpp src/instruction_parser/instruction_parser.cpp src/misc/auxiliar_methods/auxiliar_methods.cpp src/misc/input_methods/input_methods.cpp

# S = src/instructions/instructions_assembler/instructionsS/instructionsS.cpp
P = src/instructions/instructions_assembler/instructionsP/instructionsP.cpp
R = src/instructions/instructions_assembler/instructionsR/instructionsR.cpp
I = src/instructions/instructions_assembler/instructionsI/instructionsI.cpp
L = src/instructions/instructions_assembler/instructionsI/instructionsI_load.cpp


# FILES2 = src/accumulators/instruction_ACML.cpp src/accumulators/label_ACML.cpp


compile: ${FILES}
	${CC} ${FILES} ${S} ${P} ${R} ${I} ${L} -o compiled/assembler

run: 
	./compiled/assembler example.asm -o teste.txt