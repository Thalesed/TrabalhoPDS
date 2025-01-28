#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "usuario.hpp"
#include "cardapio.hpp"
#include "pedido.hpp"
#include <iostream>

class Gerente : public Usuario {
public:
    Gerente(int id, const std::string& nome, const std::string& email, const std::string& senha)
        : Usuario(id, nome, email, senha, "gerente") {}

    void adicionar_prato(Cardapio& cardapio, const Prato& prato) const {
        cardapio.adicionar_prato(prato);
        std::cout << "Prato adicionado ao cardápio pelo gerente " << nome << "!" << std::endl;
    }

    void editar_prato(Cardapio& cardapio, int prato_id, const Prato& novos_dados) const {
        cardapio.editar_prato(prato_id, novos_dados);
        std::cout << "Prato editado pelo gerente " << nome << "!" << std::endl;
    }

    void remover_prato(Cardapio& cardapio, int prato_id) const {
        cardapio.remover_prato(prato_id);
        std::cout << "Prato removido do cardápio pelo gerente " << nome << "!" << std::endl;
    }

    void cancelar_pedido(Pedido& pedido) const {
        pedido.cancelar();
        std::cout << "Pedido cancelado pelo gerente " << nome << "!" << std::endl;
    }
};

#endif
