#include "include\menu\menu_gerente.hpp"
#include "include\menu\menu_usuarios.hpp"
#include <iostream>
#include <limits>
#include <memory>

menu_gerente::menu_gerente(){}

void menu_gerente::criar_menu()
{
    do
    {
    	std::cout << "Você deseja: \n[1] Modificar Usuarios \n[2] Modificar Pratos \n[3] Modificar Armazem \n[4] Exibir Cardapio \n";
        std::cout << "[5] Modificar Pedidos \n[6] Criar Historico \n[7] Verificar Acessos ao programa \n[8] Deslogar \n";
        std::cout << "[9] Acabar com a execucao do programa\n";
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
                std::unique_ptr<menu_usuarios> ptr_1 = std::make_unique<menu_usuarios>();
                ptr_1->criar_menu();
                ptr_1.reset();
                break;
            }
            case 2:
                std::cout << "a";
            case 3:
                std::cout << "a";
            case 4:
                std::cout << "a";
            case 5:
                std::cout << "a";
            case 6:
                std::cout << "a";
            case 7:
                std::cout << "a";
            case 8:
                return;
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

bool menu_gerente::terminar_programa()
{
    if(terminar == true)
        return true;
    else
        return false;
}

menu_gerente::~menu_gerente(){}