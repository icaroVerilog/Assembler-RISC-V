#ifndef conversion_methods
#define conversion_methods

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
};

#endif /* conversion_methods */

