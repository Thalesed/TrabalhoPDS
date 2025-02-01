#ifndef SET_PEDIDO_CLIENTE_HPP
#define SET_PEDIDO_CLIENTE_HPP

#include "I_set.hpp"

class set_pedido_cliente:public I_set
{
    private:
    std::string prato,descricao,id;
    public:
    set_pedido_cliente();
    void set_valor(std::string) override;
    ~set_pedido_cliente();
};

#endif // SET_PEDIDO_CLIENTE_HPP