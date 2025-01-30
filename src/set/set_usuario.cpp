#include "set_usuario.hpp"
#include "get_file_dados.hpp"
#include "set_dados_file.hpp"
#include <iostream>
#include <map>
#include <limits>
#include <list>
#include <any>
#include <memory>

set_usuario::set_usuario(){}

void set_usuario::set_valor(std::string nome_arquivo)
{
    get_file_dados verificar(nome_arquivo);
    verificar.abrir_arquivo();
    verificar.ler_arquivo();
    std::map<std::string,std::list<std::string>> dados_f = verificar.transmitir_map();

    std::cout << "Informe o nome do usuario\n";
    std::cin >> nome;
    do
    {
        if(dados_f.find(nome) != dados_f.end())
        {
            std::cout << "Já existe esse nome na memoria dos usuarios,insira outro:\n";
            std::cin >> nome;
        }
    } while (dados_f.find(nome) != dados_f.end());
    

    std::cout << "Informe a senha do usuario\n";
    std::cin >> senha;
    std::cout << "Informe o email do usuario\n";
    std::cin >> email;
    int coef;
    do
    {
        std::cout << "Informe o nivel de privilegio do usuario,que e\n[1] Gerente\n[2] Funcionario\n[3] Cliente\n";
        std::cin >> coef;
        if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
        {
            std::cin.clear();//Por isso nunca atribua no switch case uma funcao chamada pelo valor 0
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch(coef)
        {
            case 1:
            {
                priv = {"gerente"};
                break;
            }
            case 2:
            {
                priv = {"funcionario"};
                break;
            }
            case 3:
            {
                priv = {"cliente"};
                break;
            }
            default:
                std::cout << "Valor Errado,insira novamente\n";
        }
    } while(coef < 1 || coef > 3);

    std::cout << "Informe o id do usuario\n";
    std::cin >> id;

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

set_usuario::~set_usuario(){}