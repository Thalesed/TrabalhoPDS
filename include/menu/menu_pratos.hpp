#ifndef MENU_PRATOS_G_HPP
#define MENU_PRATOS_G_HPP

#include "I_menu.hpp"
#include <string>

class menu_pratos_g:public I_menu
{
    private:
    int coef_3;
    std::string nome_arquivo = {"Arquivos_de_dados/pratos.csv"};
    public:
    menu_pratos_g();
    void criar_menu() override;
    ~menu_pratos_g();
};

#endif // MENU_PRATOS_G_HPP