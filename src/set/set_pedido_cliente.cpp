#include "set_pedido_cliente.hpp"
#include "get_file_dados.hpp"
#include "set_dados_file.hpp"
#include <iostream>
#include <map>
#include <limits>
#include <list>
#include <any>
#include <memory>
#include <chrono>

set_pedido_cliente::set_pedido_cliente(){}

void set_pedido_cliente::set_valor(std::string nome_arquivo)
{
    get_file_dados verificar(nome_arquivo);
    verificar.abrir_arquivo();
    verificar.ler_arquivo();
    std::map<std::string,std::list<std::string>> dados_f = verificar.transmitir_map();

    auto tempo_atual = std::chrono::system_clock::now();
    auto tempo_conv = std::chrono::system_clock::to_time_t(tempo_atual);
    std::string tempo_string = ctime(&tempo_conv);
    tempo_string = tempo_string.substr(0,19);

    std::cout << "Informe a identificacao do pedido\n";
    std::cin >> id;
    do
    {
        if(dados_f.find(id) != dados_f.end())
        {
            std::cout << "Já existe esse id na memoria dos usuarios,insira outro:\n";
            std::cin >> id;
        }
    } while (dados_f.find(id) != dados_f.end());

    std::cout << "Informe o nome do prato pedido\n";
    std::cin >> prato;

    descricao = {"Pedido_feito"};

    std::list<std::any> dados_out;
    dados_out.push_back(id); // Pro programa funcionar a posicao do nome sempre tem que ser a primeira
    dados_out.push_back(tempo_string);
    dados_out.push_back(prato);
    dados_out.push_back(descricao);
    
    set_dados_file escrever(nome_arquivo);
    escrever.abrir_arquivo();
    escrever.escrever_arquivo(dados_out);
    dados_out.clear();

}

set_pedido_cliente::~set_pedido_cliente(){}
