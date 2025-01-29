#ifndef I_MENU_HPP
#define I_MENU_HPP

class I_menu
{
    public:
    virtual ~I_menu() = default;
    virtual void criar_menu() = 0;
};

#endif // I_MENU_HPP