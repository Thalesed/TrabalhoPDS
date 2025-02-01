#ifndef MENU_CLIENTE_HPP
#define MENU_CLIENTE_HPP

#include "I_menu.hpp"

class menu_cliente:public I_menu
{
    private:
    int coef;
    public:
    menu_cliente();
    void criar_menu() override;
    ~menu_cliente();
};

#endif // MENU_CLIENTE_HPP