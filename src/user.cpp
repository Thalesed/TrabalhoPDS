#include "user.hpp"

User::User(){
    
}

User::User(std::string nome, std::string email){
    this->nome = nome;
    this->nome = email;
}

void User::setName(std::string nome){
    this->nome = nome;
}

std::string User::getName(){
    return this->nome;
}