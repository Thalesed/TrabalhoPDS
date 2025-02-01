#ifndef MOD_VALOR_HPP
#define MOD_VALOR_HPP

#include "I_modificar.hpp"
#include <string>

class mod_valor_usuario:public I_modificar
{
    private:
    std::string nome_arquivo,chave,dado;
    int posicao;
    public:
    mod_valor_usuario(std::string&);
    void mod_val() override;
    ~mod_valor_usuario();
};

#endif // MOD_VALOR_HPP