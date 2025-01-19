#include "C:\Users\franc\OneDrive\Documentos\Codigos\trabalho_hpp\verificar_arquivo_error.hpp"

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
        //Aqui deve ter uma função que permite com que o programa retorne para o menu de acesso anterior
        //ja que esse menu ainda não foi feito o programa apenas será encerrado
        exit(1);
    }
}
verificar_arquivo_error::~verificar_arquivo_error(){}


/*main.cpp deletar_dados_file.cpp get_dados_map.cpp get_file_dados.cpp modificar_dados_file.cpp read_dados_map.cpp set_dados_file.cpp set_map_file.cpp verificar_arquivo_error.cpp*/