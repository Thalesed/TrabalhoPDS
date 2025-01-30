#ifndef I_SET_HPP
#define I_SET_HPP
#include<string>

class I_set
{
    public:
    ~I_set() = default;
    virtual void set_valor(std::string) = 0;
};

#endif // I_SET_HPP