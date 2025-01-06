#ifndef GERENTE_H
#define GERENTE_H

#include "user.hpp"

class Gerente : public User{
public:
    Gerente(std::string nome){
        this->nome = nome;
    }              // Construtor

};

#endif // GERENTE_H
