#include "get_file_dados.hpp"
#include "verificar_arquivo_error.hpp"

#include <iostream>
#include <sstream>

get_file_dados::get_file_dados(std::string& nome_arquivo_in)
{
    verificar_arquivo_error verificar_arquivo(nome_arquivo_in);
    nome_arquivo = nome_arquivo_in;
}

void get_file_dados::abrir_arquivo()
{
    s_arquivo.open(nome_arquivo,std::ios::in);
}

void get_file_dados::ler_arquivo()
{
    std::string linha;
    while(getline(s_arquivo,linha))
    {  
        std::string palavra,chave;
        std::stringstream dividir(linha);
        bool chave_criada = false;

        while(getline(dividir,palavra,','))
        {
            if(chave_criada == false)
            {
                chave = palavra;
                r_file[chave];
                chave_criada = true;
            }
            else
            {
                r_file[chave].push_back(palavra);
            }
        }
    }
    if(s_arquivo.is_open())
        s_arquivo.close();
}

const std::map<std::string,std::list<std::string>>& get_file_dados::transmitir_map() const
{
    return r_file;
}

get_file_dados::~get_file_dados()
{
    if(s_arquivo.is_open())
        s_arquivo.close();
}

/*  Essa função serve para você conseguir receber as informações do arquivo,ela recebe os dados dos arquivos por meio da leitura
dos dados dos arquivos,que irá atribuir cada "tipo" de dado no arquivo em uma map,que poderá ser transmitida para outros lugares.
    Depois esses dados da map irão ser transmitidos pela função transmitir_map()
    Exemplo: 

        arquivos_pratos.csv =                                                       transmitir_map() =     
                                                                                Chave       Dados
        Sanduiche,15.00,carne      get_file_dados("arquivos_pratos.csv")       (Sanduiche)(15.00,carne)
        Sorvete,5.00,baunilha ->   abrir_arquivo()                         ->  (Sorvete)(5.00,baunilha)
        Refrigerante,4.50,Pepsi    ler_arquivo()                               (Refrigerante)(4.50,Pepsi) */