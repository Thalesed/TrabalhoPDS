#include "menu_armazem_g.hpp"
#include "set_armazem.hpp"
#include "get_valor.hpp"
#include "mod_valor.hpp"
#include "del_valor.hpp"
#include <iostream>
#include <memory>
#include <limits>
#include <list>

menu_armazem_g::menu_armazem_g(){}

void menu_armazem_g::criar_menu()
{
    do
    {
        std::cout << "Voce deseja: \n[1] Criar Produto no Armazem \n[2] Ver Produtos do Armazem \n[3] Modificar Produtos do Armazem \n[4] Deletar Produtos do Armazem \n";
        std::cout << "[5] Voltar ao Menu anterior \n";
        std::cin >> coef_3;
        if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
        {
            std::cin.clear();//Por isso nunca atribua no switch case uma funcao chamada pelo valor 0
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            coef_3 = 0;
        }
        switch(coef_3)
        {
            case 1:
            {
                std::unique_ptr<set_armazem> ptr_1 = std::make_unique<set_armazem>();
                ptr_1->set_valor(nome_arquivo);
                ptr_1.reset();
                break;
            }
            case 2:
            {
                std::list<std::string> cabecalho = {"Produto:","Quantidade:","Preco:"};
                std::unique_ptr<get_valor> ptr_2 = std::make_unique<get_valor>(nome_arquivo,cabecalho);
                std::cout << "Os Usuarios Registrados sao:\n\n";
                ptr_2->get_val();
                ptr_2.reset();
                break;
            }
            case 3:
            {
                std::unique_ptr<mod_valor> ptr_3 = std::make_unique<mod_valor>(nome_arquivo);
                std::cout << "Posicao: [-1] Nome [0] Quantidade [1] Preco\n";
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
    } while(coef_3 != 5);
}

menu_armazem_g::~menu_armazem_g(){}