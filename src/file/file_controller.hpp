#include <iostream>
#include <fstream>
#include "../accumulator/instruction_ACML.hpp"

class File_controller {
    public: File_controller();
    public: int write(Instruction_accumulator *accumulator, std::string filename);
    public: int read(std::string filepath);
};


/*

    lado esquerdo da gramatica livre de contexto, apenas uma variavel e so uma variavel
    lado direito e pode ter qualquer coisa, incluindo terminais e variáveis

    se chama livre de contexto pois possui apenas uma variável do lado esquerdo
    pois ao aplicar as regras nao importando onde o X apareça, a regra pode ser aplicada

    as gramaticas que nao sao livres de contexto, podem ter mais que uma variavel no lado esquerdo
    como aX ou Xb
*/
