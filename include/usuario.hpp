#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario {
protected:
    int id;
    std::string nome;
    std::string email;
    std::string senha;
    std::string tipo;

public:
    Usuario(const std::string& nome, const std::string& senha, int id, const std::string& email, const std::string& tipo)
        : nome(nome),senha(senha), id(id), email(email), tipo(tipo) {}

    virtual ~Usuario() = default;

    int getId() const { return id; }
    std::string getNome() const { return nome; }
    std::string getEmail() const { return email; }
    std::string getTipo() const { return tipo; }

    bool fazer_login(const std::string& emailInput, const std::string& senhaInput) {
        return email == emailInput && senha == senhaInput;
    }
};

#endif
