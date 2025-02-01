#include "mod_valor_pedidos.hpp"
#include "add_file_pedidos.hpp"
#include "modificar_dados_file.hpp"
#include "get_file_dados.hpp"
#include "see_file.hpp"
#include "see_pratos.hpp"
#include "cin_reset.hpp"
#include <iostream>
#include <limits>

mod_pedido::mod_pedido(){}

void mod_pedido::mod_val()
{
    add_file_pedidos pedidos_arquivo;
    pedidos_arquivo.add_file();
    std::string arquivo = pedidos_arquivo.trans_pth();
    int coef = 0;
    do
    {
        std::cout << "Escolha uma das seguintes opcoes:\n[1] Modificar o prato do pedido \n[2] Modificar o cliente do pedido\n";
        std::cout << "[3] Modificar o estado do pedido \n[4] Modificar o Arquivo contendo os pedidos\n[5] Voltar\n";
        std::cout << "O arquivo selecionado e: " << arquivo << "\n";
        std::cin >> coef;

        if(std::cin.fail())
        {
            cin_r reset;
            reset.cin_reset();
        }
        switch(coef)
        {
            case 1:
            {
                std::cout << "Qual o valor do id:\n";
                std::cin >> id;

                see_pratos g_prato;
                std::string prato = g_prato.s_prato();

                modificar_dados_file mod_p_prato(arquivo);
                mod_p_prato.modificar_arquivo(prato,0,id);
                break;
            }
            case 2:
            {
                std::cout << "Qual o valor do id:\n";
                std::cin >> id;
                std::string cliente;
                std::cout << "Qual vai ser o novo cliente?\n";
                std::cin >> cliente;

                modificar_dados_file mod_p_cliente(arquivo);
                mod_p_cliente.modificar_arquivo(cliente,2,id);
                break;
            }
            case 3:
            {
                std::cout << "Qual o valor do id:\n";
                std::cin >> id;
                std::string estado;
                std::cout << "Qual vai ser o novo estado?\n";
                std::cin >> estado;

                modificar_dados_file mod_p_estado(arquivo);
                mod_p_estado.modificar_arquivo(estado,3,id);
                break;
            }
            case 4:
            {
                arquivo.clear();
                see_file mudar_file(diretorio);
                mudar_file.ver_file();
                std::string arquivo_novo = mudar_file.selec_file();
                arquivo = diretorio + arquivo_novo;
                break;
            }
            case 5:
                return;
        }
    } while (coef != 5);
}

mod_pedido::~mod_pedido(){}