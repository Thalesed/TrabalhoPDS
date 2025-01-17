#include "produto.hpp"

Produto::Produto(){

    
}

std::string Produto::getName(){
    return this->nome;
}

void Produto::setName(std::string nome){
    this->nome = nome;
}

float Produto::getPrice(){
    return this->preco;
}