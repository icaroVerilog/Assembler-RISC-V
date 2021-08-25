compile: src/main.cpp src/instructionsI/instructionsI.cpp src/instructionsR/instructionsR.cpp
	g++ src/main.cpp src/instructionsI/instructionsI.cpp src/instructionsR/instructionsR.cpp -o compiled/assembler

debug: main.cpp instructionsI/instructionsI.cpp instructionsR/instructionsR.cpp
	g++ main.cpp instructionsI/instructionsI.cpp instructionsR/instructionsR.cpp -o main -g

run: 
	./compiled/assembler teste.asm -o teste.txt