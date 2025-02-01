#ifndef MOD_VALOR_PEDIDOS_HPP
#define MOD_VALOR_PEDIDOS_HPP
#include "I_modificar.hpp"
#include <string>

class mod_pedido:public I_modificar
{
    private:
    std::string id,prato;
    std::string diretorio = "Arquivos_de_dados/pedidos/";
    public:
    mod_pedido();
    void mod_val();
    ~mod_pedido();
};

#endif // MOD_VALOR_PEDIDOS_HPP