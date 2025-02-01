#include "menu_inicial.hpp"
#define SUCESSO 0 
#define LINE "\n----------------------------\n"

int main(){

	menu_inicial menu_i;
	menu_i.criar_menu();

    return SUCESSO;
    /*std::cout << "Bem vindos ao nosso restaurante!!!";

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
			std::cout << LINE << "Voce deseja: \n [1] Fazer login \n [2] Cadastro de Cliente \n >> " << LINE;
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
					std::string arquivo = {"Arquivos_de_dados/usuarios.csv"};
					set_cliente reg_cliente;
					reg_cliente.set_valor(arquivo);
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
		{
			std::shared_ptr<menu_funcionario> ptr_4 = std::make_shared<menu_funcionario>();
			ptr_4->criar_menu();
			ptr_4.reset();
		}
		else if(priv == "cliente")
		{
			std::shared_ptr<menu_cliente> ptr_5 = std::make_shared<menu_cliente>();
			ptr_5->criar_menu();
			ptr_5.reset();
		}
		else
			std::cout << "Ocorreu um erro grave na sua definicao de usuario,chame um especialista para resolver-lo\n";
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

}