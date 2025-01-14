#ifndef CLIENTE_H
#define CLIENTE_H

#include "user.hpp"
#include "historico.hpp"

class Cliente : public User {
private:
    Historico historico;
public:
    Cliente(std::string nome);// Construtor

};

#endif // CLIENTE_H