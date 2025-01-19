#ifndef GET_FILE_DADOS_HPP
#define GET_FILE_DADOS_HPP

#include "I_read_file.hpp"
#include <string>
#include <fstream>
#include <list>
#include <map>

class get_file_dados:public I_read_file
{
    private:
    std::ifstream s_arquivo;
    std::map<std::string,std::list<std::string>> r_file;
    std::string nome_arquivo;

    public:
    get_file_dados(std::string nome_arquivo_in);
    void abrir_arquivo() override;
    void ler_arquivo() override;
    const std::map<std::string,std::list<std::string>>& transmitir_map() const;
    ~get_file_dados();
};


#endif // GET_FILE_DADOS_HPP

// Essa função é responsável por receber dados de um arquivo csv e armazenarlos para uma variavel map.