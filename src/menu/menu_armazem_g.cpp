#include "menu_armazem_g.hpp"
#include "set_armazem.hpp"
#include "get_valor.hpp"
#include "mod_valor.hpp"
#include "del_valor.hpp"
#include "cin_reset.hpp"
#include <iostream>
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
            cin_r reset;
            reset.cin_reset();
        }
        switch(coef_3)
        {
            case 1:
            {
                set_armazem set;
                set.set_valor(nome_arquivo);
                break;
            }
            case 2:
            {
                std::list<std::string> cabecalho = {"Produto:","Quantidade:","Preco:"};
                get_valor get(nome_arquivo,cabecalho);
                get.get_val();
                break;
            }
            case 3:
            {
                mod_valor mod(nome_arquivo);
                std::cout << "Posicao: [-1] Nome [0] Quantidade [1] Preco\n";
                mod.mod_val();
                break;
            }
            case 4:
            {
                del_valor del(nome_arquivo);
                del.del_val();
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