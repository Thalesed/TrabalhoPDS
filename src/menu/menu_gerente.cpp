#include "menu_gerente.hpp"
#include "menu_usuarios_g.hpp"
#include "menu_acesso.hpp"
#include "menu_armazem_g.hpp"
#include "menu_pratos.hpp"
#include "menu_pedidos_g.hpp"
#include "read_dados_map.hpp"
#include "historico.hpp"
#include "cin_reset.hpp"
#include <iostream>

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
            cin_r reset;
            reset.cin_reset();
        }
        switch(coef)
        {
            case 1:
            {
                menu_usuarios menu_u;
                menu_u.criar_menu();
                break;
            }
            case 2:
            {
                menu_pratos_g menu_p;
                menu_p.criar_menu();
                break;
            }
            case 3:
            {
                menu_armazem_g menu_a;
                menu_a.criar_menu();
                break;
            }
            case 4:
            {
                std::string arquivo_cardapio = {"Arquivos_de_dados/pratos.csv"};
                std::list<std::string> cabecalho = {"Prato","Preco"};
                read_dados_map exibir(arquivo_cardapio);
                std::cout << "Os produtos do cardapio sao:\n";
                exibir.ler_dados_completos(cabecalho);
                break;
            }
            case 5:
            {
                menu_pedidos_g menu_p;
                menu_p.criar_menu();
                break;
            }
            case 6:
            {
                historico hist;
                hist.criar_hist();
                break;
            }
            case 7:
            {
                menu_acesso menu_a;
                menu_a.transferir_ptr(ptr_re);
                menu_a.criar_menu();
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