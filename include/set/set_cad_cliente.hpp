#ifndef SET_CAD_CLIENTE_HPP
#define SET_CAD_CLIENTE_HPP

#include "I_set.hpp"

class set_cliente:public I_set
{
    private:
    std::string nome,senha,email,priv;
    int id;
    public:
    set_cliente();
    void set_valor(std::string) override;
    ~set_cliente();
};

#endif // SET_CAD_CLIENTE_HPP