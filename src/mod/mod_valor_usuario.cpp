#include "mod_valor_usuario.hpp"
#include "modificar_dados_file.hpp"
#include <iostream>
#include <memory>
#include <limits>


mod_valor_usuario::mod_valor_usuario(std::string& nome_arquivo_in)
{
    nome_arquivo = nome_arquivo_in;
}

void mod_valor_usuario::mod_val()
{
    std::unique_ptr<modificar_dados_file> ptr_1 = std::make_unique<modificar_dados_file>(nome_arquivo);
    
    std::cout << "Qual sera o valor da chave (ou seja do primeiro valor (nome do prato,usuario...) do dado)\n";
    std::cin >> chave;

    std::cout << "Qual e a posicao:\n";
    std::cin >> posicao;
    do
    {    
        if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
        {
            std::cin.clear();//Por isso nunca atribua no switch case uma funcao chamada pelo valor 0
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Valor invalido,insira outro\n";
            std::cin >> posicao;
        }
        if(posicao == 2)
        {
            int coef = 0;
            do
            {
                std::cout << "Informe o nivel de privilegio do usuario,que e\n[1] Gerente\n[2] Funcionario\n[3] Cliente\n";
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
                        dado = {"gerente"};
                        break;
                    }
                    case 2:
                    {
                        dado = {"funcionario"};
                        break;
                    }
                    case 3:
                    {
                        dado = {"cliente"};
                        break;
                    }
                    default:
                        std::cout << "Valor Errado,insira novamente\n";
                }
            } while(coef < 1 || coef > 3);
        }
    } while(std::cin.fail());

    std::cout << "Qual e o dado que voce quer inserir\n";
    std::cin >> dado;

    ptr_1->modificar_arquivo(dado,posicao,chave);

    /*do
    {
        std << 
    } while()*/
}

mod_valor_usuario::~mod_valor_usuario(){}