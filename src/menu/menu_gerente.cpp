#include "menu_gerente.hpp"
#include "menu_usuarios_g.hpp"
#include "menu_acesso.hpp"
#include "menu_armazem_g.hpp"
#include "menu_pratos.hpp"
#include "menu_pedidos_g.hpp"
#include "read_dados_map.hpp"
#include "historico.hpp"
#include <iostream>
#include <limits>
#include <memory>

menu_gerente::menu_gerente(){}

void menu_gerente::criar_menu()
{
    do
    {
    	std::cout << "Voce deseja: \n[1] Modificar Usuarios \n[2] Modificar Pratos \n[3] Modificar Armazem \n[4] Exibir Cardapio \n";
        std::cout << "[5] Modificar Pedidos \n[6] Criar Historico \n[7] Verificar Acessos ao programa \n[8] Deslogar \n";
        std::cout << "[9] Acabar com a execucao do programa\n";
        std::cin >> coef;
        if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
        {
            std::cin.clear();//Por isso nunca atribua no switch case uma funcao chamada pelo valor 0
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            coef = 0;
        }
        switch(coef)
        {
            case 1:
            {
                std::unique_ptr<menu_usuarios> ptr_1 = std::make_unique<menu_usuarios>();
                ptr_1->criar_menu();
                ptr_1.reset();
                break;
            }
            case 2:
            {
                std::unique_ptr<menu_pratos_g> ptr_2 = std::make_unique<menu_pratos_g>();
                ptr_2->criar_menu();
                ptr_2.reset();
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                std::unique_ptr<historico> ptr_6 = std::make_unique<historico>();
                ptr_6->criar_hist();
                ptr_6.reset();
                break;
            }
            case 7:
            {
                std::unique_ptr<menu_acesso> ptr_7 = std::make_unique<menu_acesso>();
                ptr_7->transferir_ptr(ptr_re);
                ptr_7->criar_menu();
                ptr_7.reset();
                break;
            }
            case 8:
            {
                ptr_re.reset();
                return;
            }
            case 9:
            {
                terminar = true;
                break;
            }
            default:
				std::cout << "Numero invalido, tente novamente:\n";
        }
    } while(coef < 8 || coef > 9);
}

void menu_gerente::armazenar_ptr(std::shared_ptr<usuario_log>& ptr_r)
{
    ptr_re = ptr_r;
}

bool menu_gerente::terminar_programa()
{
    if(terminar == true)
        return true;
    else
        return false;
}

menu_gerente::~menu_gerente(){}
