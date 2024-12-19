#include <iostream>
#include <string>
#include "include/cliente.hpp"
#include "include/gerente.hpp"
#include "include/pedido.hpp"
#include "include/cardapio.hpp"

#define SUCESSO 0 
#define LINE "\n----------------------------\n"

int main(){
    std::cout << "Bem vindos ao nosso restaurante!!!";

    Cardapio* cardapio = new Cardapio();

    int cmd;
    std::string tmpNome, tmpEmail, tmpSenha, entrada;
    User usuario;

    while((tmpNome.length() > 1) == false){
    	std::cout << LINE << "Você deseja: \n [0] Fazer login \n [1] Cadastrar-se \n >> " << LINE;
    	std::cin >> cmd;

	    if(cmd == 1){
        	std::cout << "Digite o seu nome: ";
	        std::cin >> tmpNome;
        	std::cout << "Digite o seu email: ";
	        std::cin >> tmpEmail;
		std::cout << "Crie sua senha: ";
		std::cin >> tmpSenha;
		std::cout << "Repita sua senha: ";
		std::cin >> entrada;
		if(entrada != tmpSenha){
			std::cout << "As senhas não são iguais" << LINE;
			tmpNome = "";
			tmpEmail = "";
		}else{
        		usuario = User(tmpNome, tmpEmail, tmpSenha);
		}
		tmpSenha = "";
    	}
    }
    

    //limpando a memoria
    delete cardapio;

    return SUCESSO;
}
