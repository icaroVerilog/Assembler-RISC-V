CC = g++
FILES = src/main.cpp src/instructions/convert_methods/convert_methods.cpp src/instructions/instruction_parser/instruction_parser.cpp src/misc/auxiliar_methods/auxiliar_methods.cpp src/input_output/file_controller/file_controller.cpp

S = src/instructions/instructions_assembler/instructionsS/instructionsS.cpp
P = src/instructions/instructions_assembler/instructionsP/instructionsP.cpp
R = src/instructions/instructions_assembler/instructionsR/instructionsR.cpp
I = src/instructions/instructions_assembler/instructionsI/instructionsI.cpp
L = src/instructions/instructions_assembler/instructionsI/instructionsI_load.cpp

ACCUMULATORS = src/accumulator/instruction_accumulator.cpp src/accumulator/label_accumulator.cpp

FILE_CONTROLLER = src/file/file_controller.cpp

# FILES2 = src/accumulators/instruction_ACML.cpp src/accumulators/label_ACML.cpp


compile: ${FILES}
	${CC} ${FILES} ${S} ${P} ${R} ${I} ${L} ${ACCUMULATORS} -o compiled/assembler

run: 
	./compiled/assembler example.asm -o teste.txt