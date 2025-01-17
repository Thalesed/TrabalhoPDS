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
    std::string getName();
    void setName(std::string nome);
    float getPrice();
    bool operator == (const Produto& p) const { return nome == p.nome; }
    bool operator != (const Produto& p) const { return nome != p.nome; }
};

#endif // PRODUTO_H