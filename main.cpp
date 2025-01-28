#include <iostream>
#include <string>
#include <limits>
#include "include/cliente.hpp"
#include "include/gerente.hpp"
#include "include/pedido.hpp"
#include "include/cardapio.hpp"
#include "login.hpp"

#define SUCESSO 0 
#define LINE "\n----------------------------\n"

int main(){
    std::cout << "Bem vindos ao nosso restaurante!!!";

    Cardapio* cardapio = new Cardapio();

    int cmd;
    std::string tmpNome, tmpEmail, tmpSenha, entrada;
    //User usuario;

	do
	{
		std::cout << LINE << "Você deseja: \n [1] Fazer login \n [2] Cadastrar-se \n >> " << LINE;
		std::cin >> cmd;
		if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
		{
			std::cin.clear();//Por isso nunca atribua no switch case uma funcao chamada pelo valor 0
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		switch(cmd)
		{
			case 1:
			{
				login fazer_login;
				fazer_login.verificar_usuario();
				fazer_login.registrar_acesso();
				break;
			}
			case 2:
			{
				break;
			}
			default:
			{
                std::cout << "Numero invalido, tente novamente:\n";
                break;
			}
		}
	} while (cmd < 1 || cmd > 2);
	

    /*while((tmpNome.length() > 1) == false){
    	std::cout << LINE << "Você deseja: \n [0] Fazer login \n [1] Cadastrar-se \n >> " << LINE;
    	std::cin >> cmd;

	    if(cmd == 1){
			login fazer_login;
			fazer_login.verificar_usuario();
			fazer_login.registrar_acesso();
			/*
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
        		//usuario = User(tmpNome, tmpEmail, tmpSenha);
		}
		tmpSenha = "";
    	}*/

    //limpando a memoria
    //delete cardapio;

    return SUCESSO;
}
