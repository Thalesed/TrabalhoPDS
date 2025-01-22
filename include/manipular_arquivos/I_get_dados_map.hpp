#ifndef I_GET_DADOS_MAP_HPP
#define I_GET_DADOS_MAP_HPP

#include <string>

class I_get_dados_map
{
    public:
    virtual ~I_get_dados_map() = default;
    virtual void get_dados(std::string&) = 0;
    //virtual const std::map<std::string,std::list<std::string>> transmitir_dados_parciais(std::string chave) = 0;
};

#endif // I_GET_DADOS_MAP_HPP