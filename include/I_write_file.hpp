#ifndef I_WRITE_FILE_HPP
#define I_WRITE_FILE_HPP

#include "I_open_file.hpp"
#include <string>
#include <list>
#include <any>

class I_write_file:public I_open_file
{
    public:
    virtual ~I_write_file() = default;
    virtual void escrever_arquivo(const std::list<std::any>&) = 0;
};

#endif // I_WRITE_FILE_HPP