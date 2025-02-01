#ifndef GET_VALOR_PEDIDOS_HPP
#define GET_VALOR_PEDIDOS_HPP
#include "I_get.hpp"
#include <list>
#include <string>

class get_pedidos:public I_get
{
    private:
    std::string diretorio = "Arquivos_de_dados/pedidos/";
    std::list<std::string> cabecalho = {"Id","Prato pedido","Data do pedido:","Cliente:","Status do pedido:"};
    std::string arquivo;
    public:
    get_pedidos();
    void get_val() override;
    ~get_pedidos();
};

#endif // GET_VALOR_PEDIDOS_HPP