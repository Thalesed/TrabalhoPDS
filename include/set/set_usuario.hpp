#ifndef SET_USUARIO_HPP
#define SET_USUARIO_HPP

#include "I_set.hpp"

class set_usuario:public I_set
{
    private:
    std::string nome,senha,email,priv;
    int id;
    public:
    set_usuario();
    void set_valor(std::string) override;
    ~set_usuario();
};

#endif // SET_USUARIO_HPP