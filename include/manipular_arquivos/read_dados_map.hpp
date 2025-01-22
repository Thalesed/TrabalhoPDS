#ifndef READ_DADOS_MAP_HPP
#define READ_DADOS_MAP_HPP

#include "I_read_dados_map.hpp"
#include <string>
#include <list>
#include <map>

class read_dados_map:public I_read_dados_map
{
    private:
    std::map<std::string,std::list<std::string>> r_d_file;

    public:
    read_dados_map(std::string& arquivo);
    void ler_dados_completos(std::list<std::string>& cabecalho) override;
    void ler_dados_parciais(std::string& chave_r,std::list<std::string>& cabecalho) override;
    ~read_dados_map();
};

#endif // READ_DADOS_MAP_HPP

/* Essa classe é responsável por ler dados de um arquivo csv e mostrar-los na tela.*/ 
