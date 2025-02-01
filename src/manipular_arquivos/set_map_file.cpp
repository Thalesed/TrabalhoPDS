#include "set_map_file.hpp"
#include "verificar_arquivo_error.hpp"


set_map_file::set_map_file(std::string& nome_arquivo_in)
{
    verificar_arquivo_error verificar_arquivo(nome_arquivo_in);
    nome_arquivo = nome_arquivo_in;
}

void set_map_file::abrir_arquivo()
{
    file_o_m.open(nome_arquivo,std::ios::out);
}

void set_map_file::set_m_file(std::map<std::string,std::list<std::string>> o_m_data)
{
    auto ultima_key = --o_m_data.end();
    file_o_m.seekp(0);
    for(auto& temp:o_m_data)
    {
        file_o_m << temp.first << ",";
        for(auto& vector_valores:temp.second)
        {
            file_o_m << vector_valores << ",";
        }
        if(&temp != &*ultima_key)
            file_o_m << "\n";
    }
    if(file_o_m.is_open())
        file_o_m.close();
}

set_map_file::~set_map_file()
{
    if(file_o_m.is_open())
        file_o_m.close();
}

/*  Essa função serve para você conseguir escrever um map no arquivo,ela recebe os dados modificados pelo usuario do map,
quando a função escrever_arquivo é chamada o arquivo irá escrever os dados desse map no arquivo.
    Exemplo: 

        map file_o_m =              arquivos_pratos.csv =                               arquivos_pratos.csv =     

        Sorvete,5.00,chocolate      Sanduiche,15.00,carne                               Sorvete,5.00,chocolate
        Refrigerante,4.50,Pepsi ->  Sorvete,5.00,baunilha -> set_map_file(file_o_m) ->  Refrigerante,4.50,Pepsi
        Hamburguer,15.00,carne      Refrigerante,4.50,Pepsi                             Hamburguer,15.00,carne */