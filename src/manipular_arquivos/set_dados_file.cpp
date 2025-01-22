#include "set_dados_file.hpp"
#include "verificar_arquivo_error.hpp"

#include <iostream>

set_dados_file::set_dados_file(std::string& nome_arquivo_in)
{
    verificar_arquivo_error verificar_arquivo(nome_arquivo_in);
    nome_arquivo = nome_arquivo_in;
}

void set_dados_file::abrir_arquivo()
{
    file_w_e.open(nome_arquivo,std::ios::app);
}

void set_dados_file::escrever_arquivo(const std::list<std::any>& dado)
{
    if(file_w_e.tellp() != 0)
        file_w_e << "\n";
    for(auto& out:dado)
    {
        if(out.type() == typeid(int))
            file_w_e << std::any_cast<int>(out);
        else if(out.type() == typeid(float))
            file_w_e << std::any_cast<float>(out);
        else if(out.type() == typeid(std::string))
            file_w_e << std::any_cast<std::string>(out);
        else if(out.type() == typeid(double))
            file_w_e << std::any_cast<double>(out);
        else if(out.type() == typeid(char))
            file_w_e << std::any_cast<char>(out);
        else
            file_w_e << "Erro";
        if(&out != &dado.back())
        {
            file_w_e << ",";
        }
    }
}

set_dados_file::~set_dados_file()
{
    if(file_w_e.is_open())
        file_w_e.close();
}
