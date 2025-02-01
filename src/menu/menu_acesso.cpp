#include "menu_acesso.hpp"
#include "usuario_log.hpp"
#include "cin_reset.hpp"
#include <iostream>
#include <memory>
#include <limits>

menu_acesso::menu_acesso(){}

void menu_acesso::criar_menu()
{
    do
    {
    	std::cout << "Voce deseja: \n[1] Verificar Usuarios logados atualmente \n[2] Verificar historico de acessos \n[3] Voltar para o menu anterior \n";
        std::cin >> coef_2;
        if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
        {
            cin_r reset;
            reset.cin_reset();
        }
        switch(coef_2)
        {
            case 1:
            {
                ptr_re->get_user_log_atual();
                break;
            }
            case 2:
            {
                ptr_re->get_user_log_historico();
                break;
            }
            case 3:
                return;
            default:
				std::cout << "Numero invalido, tente novamente:\n";
        }
    } while(coef_2 != 3);
}

void menu_acesso::transferir_ptr(std::shared_ptr<usuario_log>& ptr_r)
{
    ptr_re = ptr_r;
}

menu_acesso::~menu_acesso(){}