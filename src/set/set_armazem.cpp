#include "set_armazem.hpp"
#include "get_file_dados.hpp"
#include "set_dados_file.hpp"
#include <iostream>
#include <map>
#include <limits>
#include <list>
#include <any>
#include <memory>

set_armazem::set_armazem(){}

void set_armazem::set_valor(std::string nome_arquivo)
{
    get_file_dados verificar(nome_arquivo);
    verificar.abrir_arquivo();
    verificar.ler_arquivo();
    std::map<std::string,std::list<std::string>> dados_f = verificar.transmitir_map();

    std::cout << "Informe o nome do produto\n";
    std::cin >> nome;
    do
    {
        if(dados_f.find(nome) != dados_f.end())
        {
            std::cout << "Já existe esse produto na memoria do armazem,insira outro:\n";
            std::cin >> nome;
        }
    } while (dados_f.find(nome) != dados_f.end());
    

    std::cout << "Informe a quantidade do produto\n";
    std::cin >> quantidade;
    std::cout << "Informe o preco do produto\n";
    std::cin >> valor;

    std::list<std::any> dados_out;
    dados_out.push_back(nome); // Pro programa funcionar a posicao do nome sempre tem que ser a primeira
    dados_out.push_back(quantidade);
    dados_out.push_back(valor);
    
    set_dados_file escrever(nome_arquivo);
    escrever.abrir_arquivo();
    escrever.escrever_arquivo(dados_out);
    dados_out.clear();

}

set_armazem::~set_armazem(){}
