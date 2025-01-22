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
    for(auto& temp:o_m_data)
    {
        file_o_m << temp.first << ",";
        for(auto& vector_valores:temp.second)
        {
            file_o_m << vector_valores << ",";
        }
        file_o_m << "\n";
    }
}

set_map_file::~set_map_file()
{
    if(file_o_m.is_open())
        file_o_m.close();
}