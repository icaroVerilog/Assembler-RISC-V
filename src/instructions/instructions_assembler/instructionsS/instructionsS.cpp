#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
// #include "../../instructions_structures/type_S.hpp"
#include "../../../convert_methods/convert_methods.hpp"
#include "../../instruction_parser/instruction_parser.hpp"
#include "../../../accumulator/instruction_ACML.hpp"

class S_assembler: public Convert_methods, Instruction_parser {

    private: std::string opcode_I_load;
    private: std::string output_filename;
    private: std::fstream output_file;

    private:
        std::string funct3_SB;
        std::string funct3_SH;
        std::string funct3_SW;
        std::string funct3_SD;

    public: S_assembler(std::string& output_filename){

        this -> output_filename = output_filename;
        this -> opcode_I_load.assign("0100011");

        this -> funct3_SB.assign("000");
        this -> funct3_SH.assign("001");
        this -> funct3_SW.assign("010");
        this -> funct3_SD.assign("011");
    }

    public: void SB(std::string& string, bool print_flag){
        
    }

    public: void SH(std::string& string, bool print_flag){

    }

    public: void SW(std::string& string, bool print_flag){

    }

    public: void SD(std::string& string, bool print_flag){

    }
};