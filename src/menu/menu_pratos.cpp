#include "menu_pratos.hpp"
#include "set_prato.hpp"
#include "get_valor.hpp"
#include "mod_valor.hpp"
#include "del_valor.hpp"
#include "cin_reset.hpp"
#include <iostream>
#include <list>

menu_pratos_g::menu_pratos_g(){}

void menu_pratos_g::criar_menu()
{
    do
    {
        std::cout << "Voce deseja: \n[1] Criar Pratos \n[2] Ver Pratos \n[3] Modificar Pratos \n[4] Deletar Pratos \n";
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
                set_prato s_p;
                s_p.set_valor(nome_arquivo);
                break;
            }
            case 2:
            {
                std::list<std::string> cabecalho = {"Prato:","Preco:"};
                get_valor g_v(nome_arquivo,cabecalho);
                std::cout << "Os Usuarios Registrados sao:\n\n";
                g_v.get_val();
                break;
            }
            case 3:
            {
                mod_valor m_p(nome_arquivo);
                std::cout << "Posicao: [-1] Nome [0] Preco\n";
                m_p.mod_val();
                break;
            }
            case 4:
            {
                del_valor d_p(nome_arquivo);
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

menu_pratos_g::~menu_pratos_g(){}