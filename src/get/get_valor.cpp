#include "get_valor.hpp"
#include "read_dados_map.hpp"
#include <memory>
#include <iostream>

get_valor::get_valor(std::string& nome_arquivo_in,std::list<std::string>& cabecalho_in)
{
    nome_arquivo = nome_arquivo_in;
    cabecalho = cabecalho_in;
}

void get_valor::get_val()
{
    std::shared_ptr<read_dados_map> ptr_1 = std::make_shared<read_dados_map>(nome_arquivo);
    ptr_1->ler_dados_completos(cabecalho);
}

get_valor::~get_valor(){}