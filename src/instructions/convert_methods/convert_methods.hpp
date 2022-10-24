#ifndef CONVERT_METHODS_HEADER
#define CONVERT_METHODS_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>
#include <boost/convert.hpp>
#include <bitset>
#include <regex>

class Convert_methods {
    protected: std::string register_to_binary(std::string& reg);
    protected: std::string immediate_to_binary(std::string& number);
    protected: std::string r_binary_to_string(std::string funct7, std::string reg1, std::string reg2, std::string funct3, std::string dest_reg, std::string opcode);
    protected: std::string i_binary_to_string(std::string immediate, std::string reg1, std::string funct3, std::string dest_reg, std::string opcode);
    protected: std::string l_binary_to_string(std::string immediate, std::string reg1, std::string funct3, std::string dest_reg, std::string opcode);
    protected: std::string s_binary_to_string(std::string immediate, std::string source_reg2, std::string funct3, std::string source_reg1, std::string opcode);
    protected: std::string b_binary_to_string(std::string immediate, std::string source_reg2, std::string source_reg1, std::string funct3, std::string opcode);
};

#endif /* CONVERT_METHODS_HEADER */

