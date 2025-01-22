#ifndef DELETAR_DADOS_FILE_HPP
#define DELETAR_DADOS_FILE_HPP

#include "I_delete_file.hpp"
#include <map>
#include <list>
#include <string>

class deletar_dados_file:public I_delete_file
{
    private:
    std::string nome_arquivo;
    std::map<std::string,std::list<std::string>> e_data;

    public:
    deletar_dados_file(std::string& nome_arquivo_in);
    void deletar_dados_arquivo(std::string& chave) override;
    ~deletar_dados_file();
};

#endif // DELETAR_DADOS_FILE_HPP

// Essa função é responsável por deletar dados de um arquivo csv.