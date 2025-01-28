#ifndef USUARIO_LOG_HPP
#define USUARIO_LOG_HPP

#include "I_usuario_log.hpp"
#include <string>
#include <any>
#include <list>

class usuario_log:public I_usuario_log
{
    private:
    std::string user_nome;
    std::string nome_arquivo = {"Arquivos_de_dados/acesso_usuarios.csv"};
    std::list<std::any> dados_acesso_out;
    public:
    usuario_log();
    void set_user_log(std::string& user_data) override;
    void get_user_log_atual() override;
    void get_user_log_historico() override;
    ~usuario_log();
};

#endif // USUARIO_LOG_HPP