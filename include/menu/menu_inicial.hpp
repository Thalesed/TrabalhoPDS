#ifndef MENU_INICIAL_HPP
#define MENU_INICIAL_HPP
#include "I_menu.hpp"

class menu_inicial:public I_menu
{
    private:
    int cmd;
    bool sair;
    public:
    menu_inicial();
    void criar_menu();
    ~menu_inicial();
};

#endif // MENU_INICIAL_HPP