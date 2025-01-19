#ifndef GET_DADOS_MAP_HPP
#define GET_DADOS_MAP_HPP

#include "I_get_dados_map.hpp"
#include <map>
#include <list>
#include <string>

class get_dados_map
{
    private:
    std::map<std::string,std::list<std::string>> g_m_data;
    std::map<std::string,std::list<std::string>> g_m_data_parcial;

    public:
    get_dados_map(std::string nome_arquivo);
    void get_dados(std::string& chave);
    const std::map<std::string,std::list<std::string>> transmitir_dados_parciais();
    ~get_dados_map();
};

#endif // GET_DADOS_MAP_HPP

// Essa função é responsável por receber dados de um arquivo csv e armazenarlos para uma variavel map.