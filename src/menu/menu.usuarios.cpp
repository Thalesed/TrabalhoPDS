#include "include\menu\menu_usuarios.hpp"
#include "include\set\set_usuario.hpp"
#include "include\get\get_valor.hpp"
#include "include\modificar\mod_valor.hpp"
#include "include\delete\del_valor.hpp"
#include <iostream>
#include <memory>
#include <limits>
#include <list>

menu_usuarios::menu_usuarios(){}

void menu_usuarios::criar_menu()
{
    do
    {
        std::cout << "Você deseja: \n[1] Criar Usuarios \n[2] Ver Usuarios Registrados \n[3] Modificar Usuarios \n[4] Deletar Usuarios \n";
        std::cout << "[5] Voltar ao Menu anterior \n";
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
                std::unique_ptr<set_usuario> ptr_1 = std::make_unique<set_usuario>(nome_arquivo);
                ptr_1->set_valor();
                ptr_1.reset();
                break;
            }
            case 2:
            {
                std::list<std::string> cabecalho = {"Usuario:","Senha:","Id:","Email:","Privilegio:"};
                std::unique_ptr<get_valor> ptr_2 = std::make_unique<get_valor>(nome_arquivo,cabecalho);
                std::cout << "Os Usuarios Registrados sao:\n\n";
                ptr_2->get_val();
                ptr_2.reset();
                break;
            }
            case 3:
            {
                std::unique_ptr<mod_valor> ptr_3 = std::make_unique<mod_valor>(nome_arquivo);
                ptr_3->mod_val();
                ptr_3.reset();
                break;
            }
            case 4:
            {
                std::unique_ptr<del_valor> ptr_4 = std::make_unique<del_valor>(nome_arquivo);
                ptr_4->del_val();
                ptr_4.reset();
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
    } while(coef != 5);
}

menu_usuarios::~menu_usuarios(){}