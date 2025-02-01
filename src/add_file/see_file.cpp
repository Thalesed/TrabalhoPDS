#include "see_file.hpp"
#include <iostream>
#include <filesystem>

see_file::see_file(std::string& diretorio_in)
{
    diretorio = diretorio_in;
}

void cin_reset_2()
{
    std::cin.clear();//Por isso nunca atribua no switch case uma funcao chamada pelo valor 0
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Valor errado,insira outro numero";
}

void see_file::ver_file()
{
    for(auto arquivos : std::filesystem::directory_iterator(diretorio))
    {
        std::cout << arquivos.path().filename() << "\n";
        f_data.push_back(arquivos.path().filename().string());
        ++i;
    }
}

std::string see_file::selec_file()
{
    int j = 0;
    do
    {
        std::cout << "Qual diretorio voce vai selecionar:\n";
        for(int t = 0;t < i;t++)
        {
            std::cout << "[" << t+1 << "] " << f_data[t] << "\n";
        }
        std::cin >> j;
    	if (std::cin.fail()) // Se o voce inserir um valor errado no cin essa funcao ira "limpar" ele e retornara o valor 0
            cin_reset_2();
        else if(j<=0 || j>i)
            std::cout << "Valor errado,insira novamente.\n";
    } while (j<=0 || j>i);

    std::string nome_arquivo = f_data[j-1];
    return nome_arquivo;
}

void see_file::exibir_file()
{
    std::cout << "Os arquivos existentes no diretorio sao:";
    for(int h = 0;h < i;h++)
    {
        std::cout << f_data[h] << "\n";
    }
}

see_file::~see_file(){}