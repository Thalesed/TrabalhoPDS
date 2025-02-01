#include "menu_usuarios_g.hpp"
#include "set_usuario.hpp"
#include "get_valor.hpp"
#include "mod_valor_usuario.hpp"
#include "del_valor.hpp"
#include "cin_reset.hpp"
#include <iostream>
#include <list>

menu_usuarios::menu_usuarios(){}

void menu_usuarios::criar_menu()
{
    do
    {
        std::cout << "Voce deseja: \n[1] Criar Usuarios \n[2] Ver Usuarios Registrados \n[3] Modificar Usuarios \n[4] Deletar Usuarios \n";
        std::cout << "[5] Voltar ao Menu anterior \n";
        std::cin >> coef_1;
        if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
        {
            cin_r reset;
            reset.cin_reset();
        }
        switch(coef_1)
        {
            case 1:
            {
                set_usuario s_u;
                s_u.set_valor(nome_arquivo);
                break;
            }
            case 2:
            {
                std::list<std::string> cabecalho = {"Usuario:","Senha:","Id:","Email:","Privilegio:"};
                get_valor g_u(nome_arquivo,cabecalho);
                std::cout << "Os Usuarios Registrados sao:\n\n";
                g_u.get_val();
                break;
            }
            case 3:
            {
                mod_valor_usuario m_u(nome_arquivo);
                std::cout << "Posicao: [-1] Nome [0] Senha [1] Id [2] email [3] privilegio [4]\n";
                m_u.mod_val();
                break;
            }
            case 4:
            {
                del_valor d_u(nome_arquivo);
                d_u.del_val();
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
    } while(coef_1 != 5);
}

menu_usuarios::~menu_usuarios(){}