#ifndef MENU_FUNCIONARIO_HPP
#define MENU_FUNCIONARIO_HPP

#include "I_menu.hpp"

class menu_funcionario:public I_menu
{
    private:
    int coef;
    public:
    menu_funcionario();
    void criar_menu() override;
    ~menu_funcionario();
};

#endif // MENU_FUNCIONARIO_HPP