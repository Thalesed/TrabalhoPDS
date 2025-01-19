#ifndef SET_DADOS_FILE_HPP
#define SET_DADOS_FILE_HPP

#include "I_write_file.hpp"
#include <string>
#include <list>
#include <fstream>
#include <any>

class set_dados_file:public I_write_file
{
    private:
        std::ofstream file_w_e;
        std::list<std::string> dados_convertidos;
        std::string nome_arquivo;
    public:
        set_dados_file(std::string& nome_arquivo_in);
        void abrir_arquivo() override;
        void escrever_arquivo(const std::list<std::any>& dado) override;
        ~set_dados_file();
};

#endif // SET_DADOS_FILE_HPP

/* Essa classe é responsável por escrever dados em um arquivo csv. Nesse caso a classe não precisa de um arquivo map,
ela irá escrever no fim do arquivo.*/