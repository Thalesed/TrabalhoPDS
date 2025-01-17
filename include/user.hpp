#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    std::string nome;
    std::string email;
    std::string senha;
    bool nivel; // 0 cliente; 1 gerente; 
public:
    User();
    User(std::string nome, std::string email);               // Construtor
    void setName(std::string nome);
    std::string getName();
};

#endif // USER_H