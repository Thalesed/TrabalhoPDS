#ifndef GET_VALOR_HPP
#define GET_VALOR_HPP
#include "I_get.hpp"
#include <string>
#include <list>

class get_valor:public I_get
{
    private:
    std::string nome_arquivo;;
    std::list<std::string> cabecalho;
    public:
    get_valor(std::string&,std::list<std::string>&);
    void get_val() override;
    ~get_valor();
};

#endif // GET_VALOR_HPP