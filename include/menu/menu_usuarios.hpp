#ifndef MENU_USUARIOS_HPP
#define MENU_USUARIOS_HPP

#include "I_menu.hpp"
#include <string>

class menu_usuarios:public I_menu
{
    private:
    int coef = 0;
    std::string nome_arquivo = {"C:/Users/franc/OneDrive/Documentos/Codigos/Trabalho_git/Arquivos_de_dados/usuarios.csv"};
    public:
    menu_usuarios();
    void criar_menu() override;
    ~menu_usuarios();
};

#endif // MENU_USUARIOS_HPP