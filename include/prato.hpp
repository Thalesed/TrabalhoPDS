#ifndef PRATO_H
#define PRATO_H

#include <string>

class Prato {
private:
    std::string nome;
    float price;
public:
    Prato();               // Construtor
    std::string getName();
    void setName(std::string nome);
    float getPrice();
    bool operator == (const Prato& p) const { return nome == p.nome; }
    bool operator != (const Prato& p) const { return nome != p.nome; }

};

#endif // PRATO_H