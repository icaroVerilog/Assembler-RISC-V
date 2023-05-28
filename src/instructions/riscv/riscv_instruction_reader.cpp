#include "riscv_instruction_reader.hpp"

void Riscv_instruction_reader::execute(
    Instruction_accumulator  *instructions, 
    Instruction_accumulator  *output, 
    Label_accumulator        *labels
) {
    
    R_assembler *assembler_R = new R_assembler();
    B_assembler *assembler_B = new B_assembler();
    I_assembler *assembler_I = new I_assembler();
    S_assembler *assembler_S = new S_assembler();
    L_assembler *assembler_L = new L_assembler();
    P_assembler *assembler_P = new P_assembler();
    M_assembler *assembler_M = new M_assembler();

    std::string current_instruction;

    while (instructions -> get_instruction(&current_instruction)){

        /* ::::::::::::::::::::: I FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        if (current_instruction.substr(0, 4).compare("addi") == 0){
            assembler_I -> ADDI(current_instruction, output);
        }
        else if (current_instruction.substr(0, 3).compare("ori") == 0){
            assembler_I -> ORI(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("andi") == 0){
            assembler_I -> ANDI(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("xori") == 0){
            assembler_I -> XORI(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("slli") == 0){
            assembler_I -> SLLI(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("srli") == 0){
            assembler_I -> SRLI(current_instruction, output);
        }

        /* ::::::::::::::::::::: R FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (current_instruction.substr(0, 3).compare("add") == 0){
            assembler_R -> ADD(current_instruction, output);
        }
        else if (current_instruction.substr(0, 3).compare("sub") == 0){
            assembler_R -> SUB(current_instruction, output);
        }
        else if (current_instruction.substr(0, 3).compare("and") == 0){
            assembler_R -> AND(current_instruction, output);
        }
        else if (current_instruction.substr(0, 2).compare("or") == 0){
            assembler_R -> OR(current_instruction, output);
        }
        else if (current_instruction.substr(0, 3).compare("xor") == 0){
            assembler_R -> XOR(current_instruction, output);
        }
        else if (current_instruction.substr(0, 3).compare("sll") == 0){
            assembler_R -> SLL(current_instruction, output);
        }
        else if (current_instruction.substr(0, 3).compare("srl") == 0){
            assembler_R -> SRL(current_instruction, output);
        }
            
        /* ::::::::::::::::::::: L FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (current_instruction.substr(0, 2).compare("lb") == 0){
            assembler_L -> LB(current_instruction, output);
        }
        else if (current_instruction.substr(0, 2).compare("lh") == 0){
            assembler_L -> LH(current_instruction, output);
        }
        else if (current_instruction.substr(0, 2).compare("lw") == 0){
            assembler_L -> LW(current_instruction, output);
        }
        else if (current_instruction.substr(0, 2).compare("ld") == 0){
            assembler_L -> LD(current_instruction, output);
        }

        /* ::::::::::::::::::::: S FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (current_instruction.substr(0, 2).compare("sb") == 0){
            assembler_S -> SB(current_instruction, output);
        }
        else if (current_instruction.substr(0, 2).compare("sh") == 0){
            assembler_S -> SH(current_instruction, output);
        }
        else if (current_instruction.substr(0, 2).compare("sw") == 0){
            assembler_S -> SW(current_instruction, output);
        }
        else if (current_instruction.substr(0, 2).compare("sd") == 0){
            assembler_S -> SD(current_instruction, output);
        }

        /* ::::::::::::::::::::: P FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (current_instruction.substr(0, 2).compare("mv") == 0){
            assembler_P -> MV(current_instruction, output);
        }
        else if (current_instruction.substr(0, 2).compare("li") == 0){
            assembler_P -> LI(current_instruction, output);
        }

        /* ::::::::::::::::::::: B FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (current_instruction.substr(0, 3).compare("beq") == 0){
            assembler_B -> BEQ(current_instruction, output, labels);
        }
        else if (current_instruction.substr(0, 3).compare("bne") == 0){
            assembler_B -> BNE(current_instruction, output, labels);
        }
        else if (current_instruction.substr(0, 3).compare("blt") == 0){
            assembler_B -> BLT(current_instruction, output, labels);
        }
        else if (current_instruction.substr(0, 3).compare("bge") == 0){
            assembler_B -> BGE(current_instruction, output, labels);
        }
        else if (current_instruction.substr(0, 4).compare("bltu") == 0){
            assembler_B -> BLTU(current_instruction, output, labels);
        }
        else if (current_instruction.substr(0, 4).compare("bgeu") == 0){
            assembler_B -> BGEU(current_instruction, output, labels);
        }

        /* :::::::::::::::::::: INSTRUCTIONS EXTENSIONS :::::::::::::::::::: */
        /* ::::::::::::::::::::: M FORMAT INSTRUCTIONS ::::::::::::::::::::: */

        else if (current_instruction.substr(0, 3).compare("mul") == 0){
            assembler_M -> MUL(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("mulh") == 0){
            assembler_M -> MULH(current_instruction, output);                
        }
        else if (current_instruction.substr(0, 6).compare("mulhsu") == 0){
            assembler_M -> MULHSU(current_instruction, output);      
        }
        else if (current_instruction.substr(0, 5).compare("mulhu") == 0){
            assembler_M -> MULHU(current_instruction, output);
        }
        else if (current_instruction.substr(0, 3).compare("div") == 0){
            assembler_M -> DIV(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("divu") == 0){
            assembler_M -> DIVU(current_instruction, output);
        }
        else if (current_instruction.substr(0, 3).compare("rem") == 0){
            assembler_M -> REM(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("remu") == 0){
            assembler_M -> REMU(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("mulw") == 0){
            assembler_M -> MULW(current_instruction, output);
        }
        else if (current_instruction.substr(0, 5).compare("divuw") == 0){
            assembler_M -> DIVUW(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("remw") == 0){
            assembler_M -> REMW(current_instruction, output);
        }
        else if (current_instruction.substr(0, 4).compare("mulw") == 0){
            assembler_M -> MULW(current_instruction, output);
        }
    }
}