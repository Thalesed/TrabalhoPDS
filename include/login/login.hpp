#ifndef LOGIN_HPP
#define LOGIN_HPP

#include "l_login.hpp"
#include <iostream>
#include <string>
#include <map>
#include <memory>

class login:public I_login
{
    private:
    std::string nome,senha;
    std::string nome_arquivo = {"Arquivos_de_dados/usuarios.csv"};
    std::map<std::string, std::string> dados_user;
    int opcao;
    public:
    login();
    void verificar_usuario() override;
    void registrar_acesso(std::shared_ptr<usuario_log>&) override;
    ~login();
};

#endif // LOGIN_HPP