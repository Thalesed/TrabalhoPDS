#include "set_pedido.hpp"
#include "add_file_pedidos.hpp"
#include "get_file_dados.hpp"
#include "set_dados_file.hpp"
#include "see_pratos.hpp"
#include "cin_reset.hpp"
#include <iostream>
#include <limits>
#include <any>
#include <memory>
#include <chrono>
#include <vector>


set_pedido::set_pedido(){}

void set_pedido::criar_arquivo()
{
    add_file_pedidos add_f;
    add_f.add_file();
    nome_arquivo = add_f.trans_pth();
}

std::string set_pedido::get_hora()
{
    auto tempo_atual = std::chrono::system_clock::now();
    auto tempo_conv = std::chrono::system_clock::to_time_t(tempo_atual);
    std::string tempo_string = ctime(&tempo_conv);
    tempo_string = tempo_string.substr(11,8);
    return tempo_string;
}

std::string set_pedido::set_id()
{
    if(dados_f.empty())
        return "1";
    else
    {
        for(auto val_id = dados_f.begin();val_id != dados_f.end();++val_id)
        {
            if(std::next(val_id) == dados_f.end())
            {
                std::string id_str = val_id->first;
                int id = std::stoi(id_str);
                id++;
                id_str = std::to_string(id);
                return id_str;
            }
        }
    }
}

void set_pedido::set_valor()
{
    criar_arquivo();
    get_file_dados verificar(nome_arquivo);
    verificar.abrir_arquivo();
    verificar.ler_arquivo();
    dados_f = verificar.transmitir_map();

    std::string data_str = get_hora();
    id = set_id();    

    see_pratos add_prato;
    std::string prato = add_prato.s_prato();

    descricao = "Pedido_em_andamento";

    std::cout << "Qual e o nome do cliente?\n";
    std::cin >> cliente;

    std::list<std::any> dados_out;
    dados_out.push_back(id); // Pro programa funcionar a posicao do nome sempre tem que ser a primeira
    dados_out.push_back(prato);
    dados_out.push_back(data_str);
    dados_out.push_back(cliente);
    dados_out.push_back(descricao);
    
    set_dados_file escrever(nome_arquivo);
    escrever.abrir_arquivo();
    escrever.escrever_arquivo(dados_out);
    dados_out.clear();

}

set_pedido::~set_pedido(){}
