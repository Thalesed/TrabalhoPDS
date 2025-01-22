#include "get_dados_map.hpp"
#include "get_file_dados.hpp"
#include <iostream>

get_dados_map::get_dados_map(std::string nome_arquivo)
{
    get_file_dados map_read(nome_arquivo);
    map_read.abrir_arquivo();
    map_read.ler_arquivo();
    g_m_data = map_read.transmitir_map();
}

void get_dados_map::get_dados(std::string& chave)
{
    if(g_m_data.find(chave) != g_m_data.end())
    {
        g_m_data_parcial[chave] = g_m_data[chave];
    }
    /*auto t_dado_map = g_m_data;
    if(t_dado_map.find(chave) != t_dado_map.end())
    {
        g_m_data_parcial[chave] = t_dado_map[chave];
    }*/
    else
    {
        std::cout << "Valor nao encontrado,tente novamente";
    }
}

const std::map<std::string,std::list<std::string>> get_dados_map::transmitir_dados_parciais()
{
    return g_m_data_parcial;
}

get_dados_map::~get_dados_map(){}
