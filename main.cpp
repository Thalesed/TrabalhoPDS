#include <iostream>
#include <string>
#include "include/cliente.hpp"
#include "include/gerente.hpp"
#include "include/pedido.hpp"
#include "include/cardapio.hpp"

#define SUCESSO 0 

int main(){
    std::cout << "Bem vindos ao nosso restaurante!!!";

    Cardapio* cardapio = new Cardapio();

    int cmd;
    std::string tmpNome, tmpEmail;
    User usuario;

    std::cout << "Você deseja: \n [0] Fazer login \n [1] Cadastrar-se \n >> ";
    std::cin >> cmd;

    if(cmd == 1){
        std::cout << "Digite o seu nome: ";
        std::cin >> tmpNome;
        std::cout << "Digite o seu email: ";
        std::cin >> tmpEmail;
        usuario = User(tmpNome, tmpEmail);
    }

    

    //limpando a memoria
    delete cardapio;

    return SUCESSO;
}