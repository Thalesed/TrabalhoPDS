#ifndef DEL_VALOR_HPP
#define DEL_VALOR_HPP
#include "I_delete.hpp"
#include <string>
#include <list>

class del_valor:public I_delete
{
    private:
    std::string nome_arquivo,chave;
    public:
    del_valor(std::string&);
    void del_val() override;
    ~del_valor();
};

#endif // DEL_VALOR_HPP