#ifndef PEDIDO_H
#define PEDIDO_H

#include "user.hpp"
#include "produto.hpp"
#include "prato.hpp"
#include <list>

class Pedido {
private:
    User usuario;
    int status;
    std::list<Prato> pratos;
    std::list<Produto> produtos;
    float precoTotal;
public:
    Pedido();               // Construtor

};

#endif // PEDIDO_H