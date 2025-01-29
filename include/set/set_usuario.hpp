#ifndef SET_USUARIO_HPP
#define SET_USUARIO_HPP

#include "I_set.hpp"
#include <string>

class set_usuario:public I_set
{
    private:
    std::string nome,senha,email,priv;
    std::string nome_arquivo;
    int id;
    public:
    set_usuario(std::string&);
    void set_valor() override;
    ~set_usuario();
};

#endif // SET_USUARIO_HPP