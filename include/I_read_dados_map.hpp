#ifndef I_READ_DADOS_MAP_HPP
#define I_READ_DADOS_MAP_HPP

#include "I_open_file.hpp"
#include <string>
#include <list>

class I_read_dados_map
{
    public:
    virtual ~I_read_dados_map() = default;
    virtual void ler_dados_completos(std::list<std::string>&) = 0;
    virtual void ler_dados_parciais(std::string&,std::list<std::string>&) = 0;
};

#endif // I_READ_DADOS_MAP_HPP