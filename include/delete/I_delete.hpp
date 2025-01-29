#ifndef I_DELETE_HPP
#define I_DELETE_HPP

class I_delete
{
    public:
    ~I_delete() = default;
    virtual void del_val() = 0;
};

#endif // I_DELETE_HPP