#ifndef I_USUARIO_LOG_HPP
#define I_USUARIO_LOG_HPP

#include <map>
#include <string>

class I_usuario_log
{
    public:
    ~I_usuario_log() = default;
    virtual void set_user_log(std::string&) = 0;
    //virtual void set_user_log_file() = 0;
    virtual void get_user_log_atual() = 0;
    virtual void get_user_log_historico() = 0;
};

#endif //I_USUARIO_LOG_HPP