#include "del_valor.hpp"
#include "deletar_dados_file.hpp"
#include <iostream>
#include <memory>

del_valor::del_valor(std::string& nome_arquivo_in)
{
    nome_arquivo = nome_arquivo_in;
}

void del_valor::del_val()
{
    std::cout << "Qual sera o valor da chave (ou seja do primeiro valor (nome do prato,usuario...) do dado que voce quer deletar)\n";
    std::cin >> chave;

    std::unique_ptr<deletar_dados_file> ptr_1 = std::make_unique<deletar_dados_file>(nome_arquivo);
    ptr_1->deletar_dados_arquivo(chave);
}

del_valor::~del_valor(){}