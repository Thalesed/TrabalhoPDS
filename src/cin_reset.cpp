#include "cin_reset.hpp"
#include <iostream>
#include <limits>

cin_r::cin_r(){}

void cin_r::cin_reset()
{
    std::cin.clear();//Por isso nunca atribua no switch case uma funcao chamada pelo valor 0
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Valor errado,insira outro numero";
}

cin_r::~cin_r(){}