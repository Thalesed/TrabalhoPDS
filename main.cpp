#include <iostream>
#include <string>
#include "include/cliente.hpp"
#include "include/gerente.hpp"
#include "include/pedido.hpp"
#include "include/cardapio.hpp"

#define SUCESSO 0 

using namespace std;

int main(){
    cout << "Bem vindos ao nosso restaurante!!!";

    Cardapio* cardapio = new Cardapio();



    //limpando a memoria
    delete cardapio;

    return SUCESSO;
}