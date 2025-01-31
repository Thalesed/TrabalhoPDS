#ifndef SET_ARMAZEM_HPP
#define SET_ARMAZEM_HPP

#include "I_set.hpp"

class set_armazem:public I_set
{
    private:
    std::string nome,quantidade,valor;
    public:
    set_armazem();
    void set_valor(std::string) override;
    ~set_armazem();
};

#endif // SET_ARMAZEM_HPP