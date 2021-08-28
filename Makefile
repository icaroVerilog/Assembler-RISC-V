compile: src/main.cpp src/instructions/instructionsI/instructionsI.cpp src/instructions/instructionsR/instructionsR.cpp src/instructions/convert_operations.cpp
	g++ src/main.cpp src/instructions/instructionsI/instructionsI.cpp src/instructions/instructionsR/instructionsR.cpp src/instructions/convert_operations.cpp -o compiled/assembler

run: 
	./compiled/assembler teste.asm -o teste.txt