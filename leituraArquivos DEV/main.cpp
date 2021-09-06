#include <iostream>
#include <vector>
#include <fstream>
#include <boost/convert.hpp> /* remove_if */

bool is_empty(std::string file_line){

    if (file_line.size() == 0){
        return true;
    }

    for (int index = 0; index < file_line.size(); index++){

        /* (char) 32 representa o caractere espaço na tabela ASCII */
        if (file_line[index] != (char) 32){
            return false;
        }
    }

    return true;
}

bool find_label(std::string file_line){

    if (file_line[file_line.size() - 1] == ':'){
        return true;
    }

    else {
        return false;
    }
}

int main(){
    std::fstream file;
    std::string file_line;
    int contador = 0;

    file.open("teste.txt", std::fstream::in);

    while (getline(file, file_line)){

        /* retirando os espaços da string */
        file_line.erase(remove_if(file_line.begin(), file_line.end(), isspace), file_line.end());

        /* caso a string for vazia */
        if (is_empty(file_line)){
            continue;
        }

        if (find_label(file_line)){

            std::cout << "inicio do rotulo" << std::endl;

        }

        else {
            contador++;
            // std::cout << file_line << std::endl;
        }

        /* TODO: ao encotrar uma label, fazer uma cópia da stream, transferir o controle para 
           uma função que erá ler essa cópia e apos issso voltar para o while principal e pular as linhas
           que compõe a instrução lida
        */
    }

    std::cout << contador << std::endl;
}