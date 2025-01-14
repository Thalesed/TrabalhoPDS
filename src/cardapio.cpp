 #include "cardapio.hpp"
#include <list>

Cardapio::Cardapio() {
}

void Cardapio::addPrato(Prato novoPrato) {
    pratos.push_back(novoPrato);  
}
