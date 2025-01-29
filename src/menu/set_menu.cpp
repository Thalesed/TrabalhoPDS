#include "include\menu\set_menu.hpp"
#include "include\manipular_arquivos\get_dados_map.hpp"
#include "string"

set_menu::set_menu(){}

std::string set_menu::transmitir_priv(std::shared_ptr<usuario_log>& ptr_1)
{
    std::string usuario_logado = ptr_1->transmitir_user();
    std::unique_ptr<get_dados_map>ptr_2 = std::make_unique<get_dados_map>("Arquivos_de_dados/usuarios.csv");
    ptr_2->get_dados(usuario_logado);
    std::map<std::string,std::list<std::string>> user_map_log = ptr_2->transmitir_dados_parciais();
    std::string user_priv = user_map_log[usuario_logado].back();
    return user_priv;
}

set_menu::~set_menu(){}