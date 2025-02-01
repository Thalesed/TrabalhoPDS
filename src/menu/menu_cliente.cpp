#include "menu_cliente.hpp"
#include "get_valor.hpp"
#include "set_pedido.hpp"
#include "cin_reset.hpp"
#include <iostream>

menu_cliente::menu_cliente(){}

void menu_cliente::criar_menu()
{
    do
    {
    	std::cout << "Voce deseja: \n[1] Ver Cardapio \n[2] Fazer Pedido \n[3] Deslogar\n";
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
                std::string arquivo = {"Arquivos_de_dados/pratos.csv"};
                std::list<std::string> cabecalho = {"Prato","Preco"};
                get_valor get(arquivo,cabecalho);
                get.get_val();
                std::cout << "Os produtos do cardapio sao:\n";
                break;
            }
            case 2:
            {
                std::string arquivo = {"Arquivos_de_dados/pedidos.csv"};
                set_pedido set;
                set.set_valor();
                break;
            }
            case 3:
            {
                return;
            }
            default:
				std::cout << "Numero invalido, tente novamente:\n";
        }
    } while(coef != 3);
}

menu_cliente::~menu_cliente(){}