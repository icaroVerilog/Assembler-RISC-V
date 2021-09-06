CC = g++
FILES = src/main.cpp src/instructions/instructionsI/instructionsI.cpp src/instructions/instructionsR/instructionsR.cpp src/instructions/convert_operations.cpp
FILES2 = src/accumulators/instruction_ACML.cpp src/accumulators/label_ACML.cpp


compile: ${FILES}
	${CC} ${FILES} -o compiled/assembler

run: 
	./compiled/assembler teste.asm -o teste.txt