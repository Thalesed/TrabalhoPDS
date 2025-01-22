#include "modificar_dados_file.hpp"
#include "get_file_dados.hpp"
#include "set_map_file.hpp"

#include <iostream>
#include <any>
#include <list>

modificar_dados_file::modificar_dados_file(std::string& nome_arquivo_in)
{
    get_file_dados ler_arquivo_1(nome_arquivo_in);
    nome_arquivo = nome_arquivo_in;
    ler_arquivo_1.abrir_arquivo();
    ler_arquivo_1.ler_arquivo();
    r_data = ler_arquivo_1.transmitir_map();
}

void modificar_dados_file::modificar_arquivo(std::any& dado,const int& posicao,const std::string& chave)
{
    auto temp = r_data.find(chave);
    if(temp != r_data.end())
    {
        if(posicao == -1 && dado.type() == typeid(std::string))
        {
            bool chave_existente = false;
            for(auto checar = r_data.begin();checar != r_data.end();checar++)
            {
                if(checar->first == std::any_cast<std::string>(dado))
                {
                    std::cout << "Chave de hash ja existente,escolha outra\n";
                    chave_existente = true;
                    break;
                }
            }
            if(chave_existente == false)
            {
                r_data[std::any_cast<std::string>(dado)] = temp->second;
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
            {
                if(dado.type() == typeid(int))
                    *checar_lista = std::any_cast<int>(dado);
                else if(dado.type() == typeid(float))
                    *checar_lista = std::any_cast<float>(dado);
                else if(dado.type() == typeid(std::string))
                    *checar_lista = std::any_cast<std::string>(dado);
                else if(posicao >= 0)
                    *checar_lista = "Erro";
            }
            else
                std::cout << "Valor nao encontrado,tente novamente";
        }
        set_map_file map(nome_arquivo);
        map.abrir_arquivo();
        map.set_m_file(r_data);
    }
    else if(temp == r_data.end())
        std::cout << "Valor nao encontrado,tente novamente";
}

modificar_dados_file::~modificar_dados_file(){}
