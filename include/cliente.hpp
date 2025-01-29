#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "usuario.hpp"
#include "cardapio.hpp"
#include "pedido.hpp"
#include <iostream>

class Cliente : public Usuario {
public:
    Cliente(const std::string& nome,const std::string& senha, int id, const std::string& email,const std::string& tipo)
        : Usuario(nome,senha, id, email, "cliente") {}

    void visualizar_cardapio(const Cardapio& cardapio) const {
        //cardapio.mostrar_pratos();
    }

    void fazer_pedido(Pedido& pedido) const {
        //pedido.processar();
        std::cout << "Pedido realizado com sucesso pelo cliente " << nome << "!" << std::endl;
    }
};

#endif
