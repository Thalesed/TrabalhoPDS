#ifndef MENU_GERENTE_HPP
#define MENU_GERENTE_HPP

#include "I_menu.hpp"

class menu_gerente:public I_menu
{
    private:
    int coef;
    bool terminar = false;

    public:
    menu_gerente();
    void criar_menu() override;
    bool terminar_programa();
    ~menu_gerente();

};

#endif // MENU_GERENTE_HPP