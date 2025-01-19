#include "C:\Users\franc\OneDrive\Documentos\Codigos\trabalho_hpp\read_dados_map.hpp"
#include "C:\Users\franc\OneDrive\Documentos\Codigos\trabalho_hpp\get_file_dados.hpp"

#include <iostream>

read_dados_map::read_dados_map(std::string& nome_arquivo)
{
    get_file_dados map_read(nome_arquivo);
    map_read.abrir_arquivo();
    map_read.ler_arquivo();
    r_d_file = map_read.transmitir_map();
}

void read_dados_map::ler_dados_completos(std::list<std::string>& cabecalho)
{
    auto cabecalho_n = cabecalho.begin();
    for(auto& [chave,valores]:r_d_file)
    {
        std::cout << *cabecalho_n << ":" << chave << "\n";
        ++cabecalho_n;
        if(cabecalho_n == cabecalho.end()) 
            cabecalho_n = cabecalho.begin();
        for(auto read_valores:valores)
        {
            std::cout << *cabecalho_n << ":" << read_valores << "\n";
            ++cabecalho_n;
            if(read_valores == valores.back()) 
                std::cout << "\n";
        }
    }
}

void read_dados_map::ler_dados_parciais(std::string& chave_r,std::list<std::string>& cabecalho)
{
    auto cabecalho_n = cabecalho.begin();
    auto ler_par = r_d_file.find(chave_r);
    if(ler_par != r_d_file.end())
    {
        std::cout << *cabecalho_n << ":" << ler_par->first << "\n";
        ++cabecalho_n;
        for(auto read_valores:ler_par->second)
        {
            std::cout << *cabecalho_n << ":" << read_valores << "\n";
            ++cabecalho_n;
        }
    }
    else
        std::cout << "Valor nao encontrado,tente novamente";
}

read_dados_map::~read_dados_map()
{
}