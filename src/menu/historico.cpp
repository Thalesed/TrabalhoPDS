#include "historico.hpp"

#include <filesystem>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <iostream>

historico::historico(){}

void historico::criar_hist()
{
    auto tempo_atual = std::chrono::system_clock::now();
    auto tempo_conv = std::chrono::system_clock::to_time_t(tempo_atual);
    std::string tempo_string = ctime(&tempo_conv);
    tempo_string = tempo_string.substr(0,19);
    std::replace(tempo_string.begin(),tempo_string.end(),' ','_');
    std::replace(tempo_string.begin(),tempo_string.end(),':','_');
    std::string nome_dir = tempo_string;
    std::string novo_dir = dir_out + "/" + nome_dir;

    std::filesystem::create_directories(novo_dir);
    std::filesystem::path pth_des = novo_dir + "/" + "historico";
    std::filesystem::copy(dir_in,pth_des);
    std::cout << "Historico Feito.\n";
}

historico::~historico(){}


