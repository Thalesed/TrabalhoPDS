#include <iostream>
#include <string>
#include <limits>
#include <memory>
#include "include/cliente.hpp"
#include "include/gerente.hpp"
#include "include/pedido.hpp"
#include "include/cardapio.hpp"
#include "include/login/login.hpp"
#include "include\login\usuario_log.hpp"
#include "include\menu\set_menu.hpp"
#include "include\menu\menu_gerente.hpp"

#define SUCESSO 0 
#define LINE "\n----------------------------\n"

int main(){
    std::cout << "Bem vindos ao nosso restaurante!!!";

    Cardapio* cardapio = new Cardapio();
	//usuario_log usuario_seccao;
    int cmd;
    std::string tmpNome, tmpEmail, tmpSenha, entrada;
	bool sair = false;
	std::shared_ptr<usuario_log> ptr_1 = std::make_shared<usuario_log>();
	//std::unique_ptr<bool> ptr_00 = std::make_unique<bool>(sair);
    //User usuario;
	do
	{
		do
		{
			std::cout << LINE << "Você deseja: \n [1] Fazer login \n [2] Cadastro de Cliente \n >> " << LINE;
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
					fazer_login.registrar_acesso(ptr_1);
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
		} while (cmd != 1);
		std::shared_ptr<set_menu>ptr_2 = std::make_shared<set_menu>();
		std::string priv = ptr_2->transmitir_priv(ptr_1);
				
		if(priv == "gerente")
		{
			std::shared_ptr<menu_gerente> ptr_3 = std::make_shared<menu_gerente>();
			ptr_3->armazenar_ptr(ptr_1);
			ptr_3->criar_menu();
			sair = ptr_3->terminar_programa();
			ptr_2.reset();
		}
		else if(priv == "funcionario")
			std::cout << "a";
		else if(priv == "cliente")
			std::cout << "a";
		else
			std::cout << "a";
	} while(sair == false);
	

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