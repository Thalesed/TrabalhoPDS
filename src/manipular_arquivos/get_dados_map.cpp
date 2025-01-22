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


/*  Essa função serve para você conseguir receber um dado especifico do arquivo csv,ela recebe os dados dos arquivos por meio de uma map
quando a função get_dados é chamada o arquivo irá procurar a string chave fornecida e irá atribuir os dados da chave e dos dados dela para uma map
    Essa map então poderá ser transmitida para tal classe por meio de transmitir_dados_parcial()  
    Exemplo: 

        arquivos_pratos.csv =                                                 transmitir_dados_parciais irá retornar =     

        Sanduiche,15.00,carne      get_dados_map("arquivos_pratos.csv")       
        Sorvete,5.00,baunilha ->   get_dados(Sorvete)                     ->  Refrigerante,4.50,Pepsi
        Refrigerante,4.50,Pepsi */