#include "C:\Users\franc\OneDrive\Documentos\Codigos\trabalho_hpp\deletar_dados_file.hpp"
#include "C:\Users\franc\OneDrive\Documentos\Codigos\trabalho_hpp\get_file_dados.hpp"
#include "C:\Users\franc\OneDrive\Documentos\Codigos\trabalho_hpp\set_map_file.hpp"

#include <iostream>

deletar_dados_file::deletar_dados_file(std::string& nome_arquivo_in)
{
    get_file_dados ler_arquivo_1(nome_arquivo_in);
    nome_arquivo = nome_arquivo_in;
    ler_arquivo_1.abrir_arquivo();
    ler_arquivo_1.ler_arquivo();
    e_data = ler_arquivo_1.transmitir_map();
}

void deletar_dados_file::deletar_dados_arquivo(std::string& chave)
{
    //auto temp = e_data.find(chave);
    if(e_data.find(chave) != e_data.end())
    {
        e_data.erase(chave);
        set_map_file map_out(nome_arquivo);
        map_out.abrir_arquivo();
        map_out.set_m_file(e_data);
    }
    else
        std::cout << "Valor nao encontrado,tente novamente";
}
deletar_dados_file::~deletar_dados_file(){}
