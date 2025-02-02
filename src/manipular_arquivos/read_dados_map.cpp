#include "read_dados_map.hpp"
#include "get_file_dados.hpp"

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
        if(cabecalho_n == cabecalho.end())
            cabecalho_n = cabecalho.begin();
        std::cout << *cabecalho_n << ":" << chave << "\n";
        ++cabecalho_n;
        for(auto read_valores:valores)
        {
            /*if(cabecalho_n == cabecalho.end())
                cabecalho_n = cabecalho.begin();*/
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
        std::cout << "Valor nao encontrado,tente novamente\n";
}

read_dados_map::~read_dados_map(){}

/*  Essa função serve para você conseguir ler as informações do arquivo,ela recebe os dados dos arquivos por meio de uma map,depois ela poderá
ler todos os dados do arquivo,ou só ler os conteudos de uma hash,nesse caso você terá que fornecer a chave para ler ela.
    Depois esses dados da map irão ser transmitidos pela função transmitir_map()
    Exemplo: 

        arquivos_pratos.csv =                                                          
                                                                                
        Sanduiche,15.00,carne      read_dados_map("arquivos_pratos.csv")       prato:Sanduiche preço:15.00 ingredientes:carne
        Sorvete,5.00,baunilha ->   ler_dados_completos(cabecalho)     ->       prato:Sorvete preço:5.00 ingredientes:baunilha
        Refrigerante,4.50,Pepsi                                                prato:Refrigerante preço:4.50 ingredientes:Pepsi

        string cabecalho=       -> ler_dados_parciais(Sanduiche,cabecalho) ->  prato:Sanduiche preço:15.00 ingredientes:carne
        {prato,preço,ingredientes} */