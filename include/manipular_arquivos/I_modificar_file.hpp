#ifndef I_MODIFICAR_FILE_HPP
#define I_MODIFICAR_FILE_HPP

#include <string>
#include <any>

class I_modificar_file
{
    public:
    virtual ~I_modificar_file() = default;
    virtual void modificar_arquivo(std::any&,const int&,const std::string&) = 0;
};

#endif // I_MODIFICAR_FILE_HPP