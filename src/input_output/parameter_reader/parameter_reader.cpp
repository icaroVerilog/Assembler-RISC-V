
#define DEFAULT_OUT_FILENAME "out.o"

typedef struct type_parameter type_parameter;

struct type_parameter {
    std::string input_file;
    std::string output_file;
};

class Parameter_reader {
    
    public: type_parameter read(int argc, char *argv[]){
        bool output_filename_flag = false;
        bool input_filename_flag  = false;

        std::string aux;
        std::string input_file_path;
        std::string input_filename;
        std::string output_filename;

        type_parameter parameter;

        try {
        
            if (argc == 1){
                throw std::runtime_error("mensagem 1");
            }

            for (int i = 0; i < argc; i++){
                aux = argv[i];

                if (aux.compare("--in") == 0 | aux.compare("-i")){
                    if (input_filename_flag == true){
                        throw std::runtime_error("mensagem 1");
                    }            
                    else {
                        input_filename_flag = true;

                        if (verify_input_extension(argv[i + 1], ".asm") == true){
                            input_filename.assign(argv[i + 1]);
                        }
                        else {
                            throw std::invalid_argument("formato do arquivo de entrada inválido");
                        }
                    }
                }
                else if (aux.compare("--out") == 0 | aux.compare("-o")){
                    if (output_filename_flag == true){
                        throw std::runtime_error("mensagem 1");
                    }
                    else {
                        output_filename_flag = true;
                        output_filename.assign(argv[i + 1]);
                    }
                }
            }

            if (output_filename_flag == false){
                parameter.output_file.assign(DEFAULT_OUT_FILENAME);
            }
            else {
                parameter.output_file = output_filename;
            }

            if (input_filename_flag == false){
                throw std::runtime_error("mensagem 1");
            }
            else {
                parameter.input_file = input_filename;
            }

            return parameter;
        }
        catch(const std::exception& e){
            std::cerr << e.what() << '\n';

            return parameter;
        }

    }

    private: bool verify_input_extension(std::string filename, std::string extension){

        if (filename.substr(filename.find_last_of(".")).compare(extension) == 0){
            return true;
        }
        else {
            return false;
        }
    }
};