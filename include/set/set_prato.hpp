#ifndef SET_PRATO_HPP
#define SET_PRATO_HPP

#include "I_set.hpp"

class set_prato:public I_set
{
    private:
    std::string nome,valor;
    public:
    set_prato();
    void set_valor(std::string) override;
    ~set_prato();
};

#endif // SET_PRATO_HPP