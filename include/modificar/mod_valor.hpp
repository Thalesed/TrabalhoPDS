#ifndef MOD_VALOR_HPP
#define MOD_VALOR_HPP

#include "I_modificar.hpp"
#include <string>

class mod_valor:public I_modificar
{
    private:
    std::string nome_arquivo,chave,dado;
    int posicao;
    public:
    mod_valor(std::string&);
    void mod_val() override;
    ~mod_valor();
};

#endif // MOD_VALOR_HPP