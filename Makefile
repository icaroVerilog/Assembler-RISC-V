compile: src/main.cpp src/instructions/instructionsI/instructionsI.cpp src/instructions/instructionsR/instructionsR.cpp src/seinao/seinao.cpp
	g++ src/main.cpp src/instructions/instructionsI/instructionsI.cpp src/instructions/instructionsR/instructionsR.cpp src/seinao/seinao.cpp -o compiled/assembler
