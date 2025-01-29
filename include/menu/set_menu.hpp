#include <memory>
#include "include\login\login.hpp"

class set_menu
{
    public:
    set_menu();
    std::string transmitir_priv(std::shared_ptr<usuario_log>&);
    ~set_menu();
};