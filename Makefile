CC = g++
FILES = src/main.cpp src/instructions/instructions_assembler/instructionsI/instructionsI.cpp src/instructions/instructions_assembler/instructionsR/instructionsR.cpp src/convert_methods/convert_methods.cpp src/instruction_parser/instruction_parser.cpp
# FILES2 = src/accumulators/instruction_ACML.cpp src/accumulators/label_ACML.cpp


compile: ${FILES}
	${CC} ${FILES} -o compiled/assembler

run: 
	./compiled/assembler teste.asm -o teste.txt