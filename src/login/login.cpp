#include "include\login\login.hpp"
#include "include\login\usuario_log.hpp"
#include "include\manipular_arquivos\get_file_dados.hpp"
#include <limits>

login::login(){}

void login::verificar_usuario()
{
    get_file_dados get_dados(nome_arquivo);
    get_dados.abrir_arquivo();
    get_dados.ler_arquivo();
    std::cout << "1)Coloque o nome de usuario:\n2)Volte ao menu principal\n";
    do
    {
        std::cin >> opcao;
        if (std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch(opcao)
        {
            case 1:
            {
                std::cout << "Por favor,insira o nome de usuario:\n";
                std::cin >> nome;
                break;
            }
            case 2:
            {
                return;
            }
            default:
            {
                std::cout << "Numero invalido, tente novamente:\n";
                break;
            }
        }
    }while (opcao < 1 || opcao > 2);
    if(get_dados.transmitir_map().find(nome)->first == nome)
    {
        std::cout << "Usuario encontrado\n";
        dados_user[nome];
        //nome_user = nome;
    }
    else
    {
        while(get_dados.transmitir_map().find(nome) == get_dados.transmitir_map().end())
        {
            std::cout << "\nUsuario nao encontrado\n1)Tente inserir o nome novamente:\n2)Voltar ao menu principal\n";
            do
            {
                std::cin >> opcao;
                if (std::cin.fail()) 
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                switch(opcao)
                {
                    case 1:
                    {
                        std::cout << "Por favor,insira o nome de usuario:\n";
                        std::cin >> nome;
                        break;
                    }
                    case 2:
                        return;
                    default:
                    {
                        std::cout << "Numero invalido, tente novamente:\n";
                        break;
                    }
                }
            } while (opcao < 1 || opcao > 2);
        }
    }
    std::cout << "Insira sua senha:\n";
    std::cin >> senha;
    auto map_user = get_dados.transmitir_map().find(nome);
    std::string senha_in = map_user->second.front();

    if(map_user != get_dados.transmitir_map().end() && senha_in == senha)
    {
        std::cout << "Senha encontrada\n";
        dados_user[nome] = senha;
        //senha_user = senha;
    }
    else
    {
        while(senha != senha_in)
        {
            std::cout << "Senha Incorreta\n1)Tente inserir a senha novamente:\n2)Voltar ao menu principal\n";
            do
            {
                std::cin >> opcao;
                if (std::cin.fail()) 
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                switch(opcao)
                {
                    case 1:
                    {
                        std::cout << "Por favor insira sua senha:\n";
                        std::cin >> senha;
                        break;
                    }
                    case 2:
                        return;
                    default:
                    {
                        std::cout << "Numero invalido, tente novamente:\n";
                        break;
                    }
                }
            }while (opcao < 1 || opcao > 2);
        }
    }
}

void login::registrar_acesso()
{
    auto dt = dados_user.find(nome);
    if(dt->first == nome && dt->second == senha)
    {
        std::string nome_reg = dt->first;
        usuario_log reg_acesso;
        reg_acesso.set_user_log(nome_reg);
    }
}

login::~login(){}