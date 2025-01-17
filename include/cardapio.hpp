#ifndef CARDAPIO_H
#define CARDAPIO_H

#include "prato.hpp"
#include "produto.hpp"
#include <iostream>
#include <list>
#include <string>

class Cardapio {
private:
    std::list<Prato> pratos;
    std::list<Produto> produtos;;
public:
    Cardapio();               // Construtor
    void addPrato(Prato novoPrato);
    void rmPrato(std::string item);
    void addProduto(Produto novoProduto);
    void rmProduto(std::string item);
    void print();

};

#endif // CARDAPIO_H