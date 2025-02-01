#ifndef SET_PEDIDO_HPP
#define SET_PEDIDO_HPP

#include <string>
#include <map>
#include <list>

class set_pedido
{
    private:
    std::string prato,descricao,id,nome_arquivo,cliente;
    std::map<std::string,std::list<std::string>> dados_f;
    public:
    set_pedido();
    void criar_arquivo();
    std::string get_hora();
    std::string set_id();
    void set_valor();
    ~set_pedido();
};

#endif // SET_PEDIDO_HPP