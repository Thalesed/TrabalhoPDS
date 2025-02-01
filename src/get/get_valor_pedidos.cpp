#include "get_valor_pedidos.hpp"
#include "add_file_pedidos.hpp"
#include "read_dados_map.hpp"
#include "see_file.hpp"
#include "cin_reset.hpp"
#include <iostream>
#include <algorithm>
#include <limits>

get_pedidos::get_pedidos(){}

void get_pedidos::get_val()
{
    add_file_pedidos pedidos_arquivo;
    pedidos_arquivo.add_file();
    std::string arquivo = pedidos_arquivo.trans_pth();
    int coef = 0;
    do
    {
        std::cout << "Escolha uma das seguintes opcoes:\n[1] Ver todos os pedidos do dia selecionado \n[2] Ver um valor especifico do dia selecionado\n";
        std::cout << "[3] Mudar o Arquivo contendo os pedidos \n[4] Voltar\n";
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
                read_dados_map ler_total(arquivo);
                ler_total.ler_dados_completos(cabecalho);
                break;
            }
            case 2:
            {
                std::string id;
                std::cout << "Insira o valor do id do pedido.\n";
                std::cin >> id;
                read_dados_map ler_parcial(arquivo);
                ler_parcial.ler_dados_parciais(id,cabecalho);
                break;
            }
            case 3:
            {
                arquivo.clear();
                see_file mudar_file(diretorio);
                mudar_file.ver_file();
                std::string arquivo_novo = mudar_file.selec_file();
                arquivo = diretorio + arquivo_novo;
                break;
            }
            case 4:
            {
                return;
            }
        }
    } while (coef != 4);
}

get_pedidos::~get_pedidos(){}