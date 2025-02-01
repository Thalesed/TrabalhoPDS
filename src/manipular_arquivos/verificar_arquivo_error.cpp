#include "verificar_arquivo_error.hpp"

#include <iostream>
#include <fstream>

verificar_arquivo_error::verificar_arquivo_error(std::string& nome_arquivo)
{
    try
    {
        std::fstream verificar_arquivo(nome_arquivo);
        if(!verificar_arquivo.is_open())
        {
            throw std::runtime_error("O arquivo nao conseguiu ser aberto,contate um profissional qualificado para resolver esse problema");
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cout << e.what();
        exit(1);
    }
}
verificar_arquivo_error::~verificar_arquivo_error(){}


/* Esse arquivo serva para verificar se um arquivo existe e consegue ser aberto antes que as linha de abertura de arquivos das outras classe
sejam executadas,estou pensando em caso ocorra alguma falha o programa faça com que o usuario volte ao menu anterior a essa falha,porém ainda temos que ver
como esse menu vai ser feito*/