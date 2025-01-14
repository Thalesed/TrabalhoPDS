#ifndef CARDAPIO_H
#define CARDAPIO_H

#include "prato.hpp"
#include <list>

class Cardapio {
private:
    std::list<Prato> pratos;
public:
    Cardapio();               // Construtor
    void addPrato(Prato novoPrato);

};

#endif // CARDAPIO_H