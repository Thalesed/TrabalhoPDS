#include "set_cad_cliente.hpp"
#include "set_usuario.hpp"
#include "get_file_dados.hpp"
#include "set_dados_file.hpp"

#include <iostream>
#include <map>
#include <limits>
#include <list>
#include <any>
#include <memory>

set_cliente::set_cliente(){}

void set_cliente::set_valor(std::string nome_arquivo)
{
    get_file_dados verificar(nome_arquivo);
    verificar.abrir_arquivo();
    verificar.ler_arquivo();
    std::map<std::string,std::list<std::string>> dados_f = verificar.transmitir_map();

    std::cout << "Informe o seu nome de usuario\n";
    std::cin >> nome;
    do
    {
        if(dados_f.find(nome) != dados_f.end())
        {
            std::cout << "Já existe esse nome na memoria dos usuarios,insira outro:\n";
            std::cin >> nome;
        }
    } while (dados_f.find(nome) != dados_f.end());
    

    std::cout << "Informe a sua senha\n";
    std::cin >> senha;
    std::cout << "Informe o seu email\n";
    std::cin >> email;
    std::cout << "Informe a sua identificacao do usuario\n";
    std::cin >> id;
    priv = "cliente";

    std::list<std::any> dados_out;
    dados_out.push_back(nome); // Pro programa funcionar a posicao do nome sempre tem que ser a primeira
    dados_out.push_back(senha);
    dados_out.push_back(id);
    dados_out.push_back(email);
    dados_out.push_back(priv); // Pro programa funcionar a posicao do estado de privilegio sempre tem que ser a ultima
    
    set_dados_file escrever(nome_arquivo);
    escrever.abrir_arquivo();
    escrever.escrever_arquivo(dados_out);
    dados_out.clear();
}

set_cliente::~set_cliente(){}