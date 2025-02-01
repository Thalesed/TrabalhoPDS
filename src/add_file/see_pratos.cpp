#include "see_pratos.hpp"
#include "get_file_dados.hpp"
#include "cin_reset.hpp"
#include "see_pratos.hpp"
#include "cin_reset.hpp"
#include <iostream>
#include <map>
#include <list>
#include <vector>

see_pratos::see_pratos(){}

std::string see_pratos::s_prato()
{
    std::string arquivo_pratos = "Arquivos_de_dados/pratos.csv";
    get_file_dados get_pratos(arquivo_pratos);
    get_pratos.abrir_arquivo();
    get_pratos.ler_arquivo();
    std::map<std::string,std::list<std::string>> dados_p = get_pratos.transmitir_map();
    std::vector<std::string> pratos_sel(dados_p.size());
    int i = 0;
    int j = 1;
    std::cout << "Os pratos disponiveis sao:\n";
    for(auto val_pr = dados_p.begin();val_pr != dados_p.end();++val_pr)
    {
        std::cout << "[" << j << "] " << val_pr->first << " preco: " << val_pr->second.front() << "\n";
        pratos_sel[i] = val_pr->first;
        ++i;
        ++j;
    }
    do
    {
        std::cout << "Escolha Qual sera seu prato:\n";
        std::cin >> j;
    	if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
        {
            cin_r reset;
            reset.cin_reset();
        }
        else if(j<= 0 || j>i)
                std::cout << "Valor errado,insira outro numero";
    } while (j<= 0 || j>i);

    std::string prato = pratos_sel[j-1];
    return prato;
}

see_pratos::~see_pratos(){}