#include "mod_valor.hpp"
#include "modificar_dados_file.hpp"
#include <iostream>
#include <memory>
#include <limits>


mod_valor::mod_valor(std::string& nome_arquivo_in)
{
    nome_arquivo = nome_arquivo_in;
}

void mod_valor::mod_val()
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
    } while(std::cin.fail());

    std::cout << "Qual e o dado que voce quer inserir\n";
    std::cin >> dado;

    ptr_1->modificar_arquivo(dado,posicao,chave);
}

mod_valor::~mod_valor(){}