#include "deletar_dados_file.hpp"
#include "get_file_dados.hpp"
#include "set_map_file.hpp"

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

/*  Essa função serve para você conseguir deletar alguma informação do arquivo,ela recebe os dados dos arquivos por meio de uma map
quando a função deletar_dados_file é chamada o arquivo irá procurar a string chave fornecida e irá deletar ela se for encontrada
    Depois esses dados da map irão ser escritos no arquivo por meio da classe set_map_file
    Exemplo: 

        arquivos_pratos.csv =                                                       arquivos_pratos.csv =     

        Sanduiche,15.00,carne      deletar_dados_file("arquivos_pratos.csv")       Sanduiche,15.00,carne,
        Sorvete,5.00,baunilha ->   deletar_dados_arquivo(Sorvete)              ->  Refrigerante,4.50,Pepsi
        Refrigerante,4.50,Pepsi */