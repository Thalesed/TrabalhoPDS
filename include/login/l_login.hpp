#ifndef I_LOGIN_HPP
#define I_LOGIN_HPP

#include <string>
#include <memory>
#include "usuario_log.hpp"

class I_login
{
    public:
    virtual ~I_login() = default;
    virtual void verificar_usuario() = 0;
    virtual void registrar_acesso(std::shared_ptr<usuario_log>&) = 0;
};

#endif // I_LOGIN_HPP