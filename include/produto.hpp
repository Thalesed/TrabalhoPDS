#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {
private: 
    std::string nome;
    int quantidade;
    double preco;
public:
    Produto();               // Construtor
};

#endif // PRODUTO_H