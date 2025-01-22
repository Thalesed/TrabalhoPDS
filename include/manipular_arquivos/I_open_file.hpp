#ifndef I_OPEN_FILE_HPP
#define I_OPEN_FILE_HPP

#include <string>

class I_open_file
{
    public:
    virtual ~I_open_file() = default;
    virtual void abrir_arquivo() = 0;
};

#endif // I_OPEN_FILE_HPP