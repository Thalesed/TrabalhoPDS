#include "prato.hpp"

Prato::Prato(){

    
}

std::string Prato::getName(){
    return this->nome;
}

void Prato::setName(std::string nome){
    this->nome = nome;
}

float Prato::getPrice(){
    return this->price;
}