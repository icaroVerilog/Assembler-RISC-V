#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include "../../instructions_structures/type_I.hpp"
#include "../../convert_methods/convert_methods.hpp"
#include "../../instruction_parser/instruction_parser.hpp"
#include "../../../accumulator/instruction_ACML.hpp"

class I_assembler: public Convert_methods, public Instruction_parser {

    private: std::string  opcode_B;
    private: std::fstream output_file;
    private: std::string  output_filename;

    private:
        std::string funct3_BEQ;
        std::string funct3_BNE;
        std::string funct3_BLT;
        std::string funct3_BGE;
        std::string funct3_BLTU;
        std::string funct3_BGEU;

    public: B_assembler(){

        this -> opcode_B.assign("1100011");

        this -> funct3_BEQ.assign("000");
        this -> funct3_BNE.assign("001");
        this -> funct3_BLT.assign("100");
        this -> funct3_BGE.assign("101");
        this -> funct3_BLTU.assign("110");
        this -> funct3_BGEU.assign("111");        
    }

    public: void BEQ(std::string& string, Instruction_accumulator* accumulator){

    }

    public: void BNE(std::string& string, Instruction_accumulator* accumulator){

    }

    public: void BLT(std::string& string, Instruction_accumulator* accumulator){

    }

    public: void BGE(std::string& string, Instruction_accumulator* accumulator){

    }

    public: void BLTU(std::string& string, Instruction_accumulator* accumulator){

    }
    
    public: void BGEU(std::string& string, Instruction_accumulator* accumulator){

    }
};