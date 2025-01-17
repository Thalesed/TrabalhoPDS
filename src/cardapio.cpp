#include "cardapio.hpp"
#include <list>
#include "prato.hpp"

Cardapio::Cardapio() {
}

void Cardapio::addPrato(Prato novoPrato) {
    for(Prato p : this->pratos){
        if(p == novoPrato){
            return;
        }
    }
    this->pratos.push_back(novoPrato);  
}

void Cardapio::rmPrato(std::string item) {
    for(Prato p : this->pratos){
        if(item == p.getName()){
            pratos.remove(p);
        }
    } 
}

void Cardapio::addProduto(Produto novoProduto) {
    for(Produto p : this->produtos){
        if(p == novoProduto){
            return;
        }
    }
    this->produtos.push_back(novoProduto);  
}

void Cardapio::rmProduto(std::string item) {
    for(Produto p : this->produtos){
        if(item == p.getName()){
            produtos.remove(p);
        }
    } 
}

void Cardapio::print(){
    for(Prato p : this->pratos){
        std::cout << p.getName() << p.getPrice();
    }
}
