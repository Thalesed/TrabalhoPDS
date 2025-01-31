#ifndef MENU_ARMAZEM_G_HPP
#define MENU_ARMAZEM_G_HPP

#include "I_menu.hpp"
#include <string>

class menu_armazem_g:public I_menu
{
    private:
    int coef_3;
    std::string nome_arquivo = {"Arquivos_de_dados/armazem.csv"};
    public:
    menu_armazem_g();
    void criar_menu() override;
    ~menu_armazem_g();
};

#endif // MENU_ARMAZEM_G_HPP