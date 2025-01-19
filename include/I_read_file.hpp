#ifndef I_READ_FILE_HPP
#define I_READ_FILE_HPP

#include "I_open_file.hpp"
#include <string>

class I_read_file:public I_open_file
{
    public:
    virtual ~I_read_file() = default;
    virtual void ler_arquivo() = 0;
};

#endif // I_READ_FILE_HPP