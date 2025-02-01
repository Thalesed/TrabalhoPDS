#ifndef MENU_PEDIDOS_G_HPP
#define MENU_PEDIDOS_G_HPP

#include "I_menu.hpp"
#include <string>

class menu_pedidos_g:public I_menu
{
    private:
    int coef_3;
    std::string nome_arquivo = {"Arquivos_de_dados/pedidos.csv"};
    public:
    menu_pedidos_g();
    void criar_menu() override;
    ~menu_pedidos_g();
};

#endif // MENU_PEDIDOS_G_HPP