#include "modificar_dados_file.hpp"
#include "get_file_dados.hpp"
#include "set_map_file.hpp"

#include <iostream>
#include <any>
#include <list>
#include <memory>

modificar_dados_file::modificar_dados_file(std::string& nome_arquivo_in)
{
    get_file_dados ler_arquivo_1(nome_arquivo_in);
    nome_arquivo = nome_arquivo_in;
    ler_arquivo_1.abrir_arquivo();
    ler_arquivo_1.ler_arquivo();
    r_data = ler_arquivo_1.transmitir_map();
}

bool modificar_dados_file::procurar_key(std::string& dado_1)
{
    //bool chave_existente = false;
    for(auto checar = r_data.begin();checar != r_data.end();checar++)
    {
        if(checar->first == dado_1)
        {
            std::cout << "Chave de hash ja existente,escolha outra\n";
            return true;
        }
    }
    return false;
}

void modificar_dados_file::modificar_arquivo(std::string& dado,const int& posicao,const std::string& chave)
{
    auto temp = r_data.find(chave);
    if(temp != r_data.end())
    {
        if(posicao == -1)
        {
            bool chave_existente = procurar_key(dado);
            if(chave_existente == false)
            {
                r_data[dado] = temp->second;
                r_data.erase(temp);
                set_map_file map(nome_arquivo);
                map.abrir_arquivo();
                map.set_m_file(r_data);
            }
        }
        else
        {
            auto checar_lista = temp->second.begin();
            std::advance(checar_lista, posicao);
            if(checar_lista != temp->second.end())
                *checar_lista = dado;
            else
                std::cout << "Valor nao encontrado,tente novamente\n";
        }
        set_map_file map(nome_arquivo);
        map.abrir_arquivo();
        map.set_m_file(r_data);
    }
    else if(temp == r_data.end())
        std::cout << "Valor nao encontrado,tente novamente\n";
}

modificar_dados_file::~modificar_dados_file(){}

/*  Essa função serve para você conseguir modificar alguma informação da do arquivo,ela recebe os dados dos arquivos por meio de uma map
quando a função modificar_dados_file é chamada o arquivo irá procurar a string chave fornecida e irá modificar se for encontrada é importante 
notar que existirá um valor int que irá determinar qual valor da chave do map será modificado,se esse valor for -1 a chave em sí será modificada
    Depois esses dados da map irão ser escritos no arquivo por meio da classe set_map_file
    Exemplo: 

        arquivos_pratos.csv =                                                       arquivos_pratos.csv =     

        Sanduiche,15.00,carne      modificar_dados_file("arquivos_pratos.csv")       Sorvete,5.00,chocolate
        Sorvete,5.00,baunilha ->   modificar_arquivo("chocolate",1,Sorvete)      ->  Refrigerante,4.50,Pepsi
        Refrigerante,4.50,Pepsi    modificar_arquivo("Hamburguer",-1,Sanduiche)      Hamburguer,15.00,carne */