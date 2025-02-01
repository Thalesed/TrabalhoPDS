#ifndef DEL_VALOR_PEDIDOS_HPP
#define DEL_VALOR_PEDIDOS_HPP
#include "I_delete.hpp"
#include <string>

class del_pedido:public I_delete
{
    private:
    std::string id;
    std::string diretorio = "Arquivos_de_dados/pedidos/";
    public:
    del_pedido();
    void del_val() override;
    ~del_pedido();
};

#endif // DEL_VALOR_PEDIDOS_HPP