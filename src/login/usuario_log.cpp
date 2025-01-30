#include "usuario_log.hpp"
#include "set_dados_file.hpp"
#include "read_dados_map.hpp"

#include <iostream>
#include <string>
#include <chrono>

usuario_log::usuario_log(){}

void usuario_log::set_user_log(std::string& user_data)
{
    user_nome = user_data;
    set_dados_file set_acesso(nome_arquivo);
    auto tempo_atual = std::chrono::system_clock::now();
    auto tempo_conv = std::chrono::system_clock::to_time_t(tempo_atual);
    std::string tempo_string = ctime(&tempo_conv);
    std::string hora = tempo_string.substr(11,8);
    std::string data = tempo_string.substr(0,10);

    dados_acesso_out.push_back(hora);
    dados_acesso_out.push_back(data);
    dados_acesso_out.push_back(user_nome);

    set_acesso.abrir_arquivo();
    set_acesso.escrever_arquivo(dados_acesso_out);
    dados_acesso_out.clear();
}
void usuario_log::get_user_log_atual()
{
    std::cout << "O usuario logado agora e:" << user_nome <<"\n";
}

std::string usuario_log::transmitir_user()
{
    return user_nome;
}

void usuario_log::get_user_log_historico()
{
    read_dados_map ler_acesso(nome_arquivo);
    std::list<std::string> cabecalho = {"Acesso na hora:","Acesso na data:","Nome:"};
    ler_acesso.ler_dados_completos(cabecalho);
    //std::map<std::string,std::list<std::string>> dados_acesso_in = get_acesso.transmitir_map();
}

usuario_log::~usuario_log(){}