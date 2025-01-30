#ifndef MENU_ACESSO_HPP
#define MENU_ACESSO_HPP
#include "usuario_log.hpp"
#include "I_menu.hpp"
#include <string>
#include <memory>

class menu_acesso:public I_menu
{
    private:
    int coef_2 = 0;
    std::string nome_arquivo = {"acesso_usuarios.csv"};
    std::shared_ptr<usuario_log> ptr_re = std::make_shared<usuario_log>();

    public:
    menu_acesso();
    void criar_menu() override;
    void transferir_ptr(std::shared_ptr<usuario_log>&);
    ~menu_acesso();

};

#endif // MENU_ACESSO_HPP