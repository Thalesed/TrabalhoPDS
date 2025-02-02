#include "del_valor_pedidos.hpp"
#include "add_file_pedidos.hpp"
#include "deletar_dados_file.hpp"
#include "see_file.hpp"
#include "cin_reset.hpp"
#include <iostream>
#include <limits>

del_pedido::del_pedido(){}

void del_pedido::del_val()
{
    add_file_pedidos pedidos_arquivo;
    pedidos_arquivo.add_file();
    std::string arquivo = pedidos_arquivo.trans_pth();
    int coef = 0;
    do
    {
        std::cout << "Escolha uma das seguintes opcoes:\n[1] Modificar o Arquivo contendo os pedidos \n[2] Deletar um pedido\n";
        std::cout << "[3] Voltar \n";
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
                arquivo.clear();
                see_file mudar_file(diretorio);
                mudar_file.ver_file();
                std::string arquivo_novo = mudar_file.selec_file();
                arquivo = diretorio + arquivo_novo;
                break;
            }
            case 2:
            {
                std::string chave;
                std::cout << "Qual sera o valor da chave (ou seja do primeiro valor (nome do prato,usuario...) do dado que voce quer deletar)\n";
                std::cin >> chave;

                deletar_dados_file deletar(arquivo);
                deletar.deletar_dados_arquivo(chave);
                break;
            }
            case 3:
            {
                return;
            }
        }
    } while (coef != 3);
}

del_pedido::~del_pedido(){}