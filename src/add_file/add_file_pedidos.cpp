#include "add_file_pedidos.hpp"
#include <chrono>
#include <filesystem>
#include <vector>
#include <iostream>
#include <algorithm>

add_file_pedidos::add_file_pedidos(){}

std::string add_file_pedidos::get_data()
{
    auto tempo_atual = std::chrono::system_clock::now();
    auto tempo_conv = std::chrono::system_clock::to_time_t(tempo_atual);
    std::string tempo_string = ctime(&tempo_conv);
    std::string tempo_data = tempo_string.substr(0,10);
    std::string tempo_ano = tempo_string.substr(20,4);
    std::replace(tempo_data.begin(),tempo_data.end(),' ','_');
    std::replace(tempo_data.begin(),tempo_data.end(),':','_');
    //std::replace(tempo_ano.begin(),tempo_string.end(),' ','_');
    //std::replace(tempo_ano.begin(),tempo_string.end(),':','_');
    std::string tempo_path = tempo_data + "_" + tempo_ano + ".csv";
    return tempo_path;
}

bool add_file_pedidos::ver_dir(std::string& path,std::string& data)
{
    for(auto files_re : std::filesystem::directory_iterator(path))
    {
        std::string nome_arquivo = files_re.path().filename().string();
        if(data == nome_arquivo)
            return false;
    }
    return true;
}

void add_file_pedidos::add_file()
{
    std::string nome_arquivo = get_data();
    bool criar_file = ver_dir(dir_path,nome_arquivo);

    if(criar_file == true)
    {
        std::string new_file = dir_path + nome_arquivo;
        file_c.open(new_file,std::ios::out);
        file_c.close();
    }
}

std::string add_file_pedidos::trans_pth()
{
    std::string nome_arquivo = get_data();
    fil_path = dir_path + nome_arquivo;
    return fil_path;
}

add_file_pedidos::~add_file_pedidos()
{
    if(file_c.is_open())
        file_c.close();
}