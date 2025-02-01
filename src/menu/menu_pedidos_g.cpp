#include "menu_pedidos_g.hpp"
#include "set_pedido.hpp"
#include "get_valor_pedidos.hpp"
#include "mod_valor_pedidos.hpp"
#include "del_valor_pedidos.hpp"
#include "cin_reset.hpp"
#include <iostream>
#include <list>

menu_pedidos_g::menu_pedidos_g(){}

void menu_pedidos_g::criar_menu()
{
    do
    {
        std::cout << "Voce deseja: \n[1] Criar Pedido \n[2] Ver Pedido \n[3] Modificar Pedido \n[4] Deletar Pedido \n";
        std::cout << "[5] Voltar ao Menu anterior \n";
        std::cin >> coef_3;
        if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
        {
            cin_r reset;
            reset.cin_reset();
        }
        switch(coef_3)
        {
            case 1:
            {
                set_pedido s_p;
                s_p.set_valor();
                break;
            }
            case 2:
            {
                get_pedidos g_p;
                g_p.get_val();
                break;
            }
            case 3:
            {
                mod_pedido m_p;
                m_p.mod_val();
                break;
            }
            case 4:
            {
                del_pedido d_p;
                d_p.del_val();
                break;
            }
            case 5:
            {
                return;
                break;
            }
            default:
                std::cout << "Numero invalido, tente novamente:\n";
        }
    } while(coef_3 != 5);
}

menu_pedidos_g::~menu_pedidos_g(){}