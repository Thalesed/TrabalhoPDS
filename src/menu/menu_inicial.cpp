#include "menu_inicial.hpp"
#include "cin_reset.hpp"
#include "set_cad_cliente.hpp"
#include "login.hpp"
#include "usuario_log.hpp"
#include "set_menu.hpp"
#include "menu_gerente.hpp"
#include "menu_funcionario.hpp"
#include "menu_cliente.hpp"
#include <iostream>
#include <memory>
#include <string>

#define LINE "\n----------------------------\n"

menu_inicial::menu_inicial(){}

void menu_inicial::criar_menu()
{
    std::cout << "Bem vindos ao nosso restaurante!!!";
	std::shared_ptr<usuario_log> ptr_1 = std::make_shared<usuario_log>();
	do
	{
		do
		{
			std::cout << LINE << "Voce deseja: \n [1] Fazer login \n [2] Cadastro de Cliente \n [3] Sair do programa " << LINE;
			std::cin >> cmd;
			if(std::cin.fail())
			{
				cin_r reset;
				reset.cin_reset();
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
						std::string arquivo = {"Arquivos_de_dados/usuarios.csv"};
						set_cliente reg_cliente;
						reg_cliente.set_valor(arquivo);
						break;
					}
					case 3:
					{
						return;
					}
					default:
					{
						std::cout << "Numero invalido, tente novamente:\n";
					}
				}
		} while(cmd != 1);
		set_menu menu_p;
		std::string priv = menu_p.transmitir_priv(ptr_1);

		if(priv == "gerente")
		{
			menu_gerente menu_g;
			menu_g.armazenar_ptr(ptr_1);
			menu_g.criar_menu();
			sair = menu_g.terminar_programa();
		}
		else if(priv == "funcionario")
		{
			menu_funcionario menu_f;
			menu_f.criar_menu();
		}
		else if(priv == "cliente")
		{
			menu_cliente menu_c;
			menu_c.criar_menu();
		}
		else
			std::cout << "Ocorreu um erro grave na sua definicao de usuario,chame um especialista para resolver-lo\n";
	} while (sair == false);
}

menu_inicial::~menu_inicial(){}