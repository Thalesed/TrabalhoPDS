#ifndef I_DELETE_FILE_HPP
#define I_DELETE_FILE_HPP

#include <string>

class I_delete_file
{
    public:
    virtual ~I_delete_file() = default;
    virtual void deletar_dados_arquivo(std::string&) = 0;
};

#endif // I_DELETE_FILE_HPP