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