#include "menu_funcionario.hpp"
#include "menu_pedidos_g.hpp"
#include "get_valor.hpp"
#include "cin_reset.hpp"
#include <iostream>

menu_funcionario::menu_funcionario(){}

void menu_funcionario::criar_menu()
{
    do
    {
    	std::cout << "Voce deseja: \n[1] Modificar Pedidos \n[2] Exibir Cardapio \n[3] Exibir Armazem \n[4] Deslogar \n";
        std::cin >> coef;
        if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
        {
            cin_r reset;
            reset.cin_reset();
        }
        switch(coef)
        {
            case 1:
            {
                menu_pedidos_g menu;
                menu.criar_menu();
                break;
            }
            case 2:
            {
                std::string arquivo = {"Arquivos_de_dados/pratos.csv"};
                std::list<std::string> cabecalho = {"Prato","Preco"};
                get_valor get(arquivo,cabecalho);
                get.get_val();
                break;
            }
            case 3:
            {
                std::string arquivo = {"Arquivos_de_dados/armazem.csv"};
                std::list<std::string> cabecalho = {"Prato","Quantidade","Preco"};
                get_valor get(arquivo,cabecalho);
                get.get_val();
                break;
            }
            case 4:
            {
                return;
            }
            default:
				std::cout << "Numero invalido, tente novamente:\n";
        }
    } while(coef != 4);
}

menu_funcionario::~menu_funcionario(){}