#ifndef MENU_GERENTE_HPP
#define MENU_GERENTE_HPP

#include "usuario_log.hpp"
#include "I_menu.hpp"

#include <memory>

class menu_gerente:public I_menu
{
    private:
    int coef;
    bool terminar = false;
    std::shared_ptr<usuario_log> ptr_re = std::make_shared<usuario_log>();
    public:
    menu_gerente();
    void criar_menu() override;
    void armazenar_ptr(std::shared_ptr<usuario_log>&);
    bool terminar_programa();
    ~menu_gerente();

};

#endif // MENU_GERENTE_HPP