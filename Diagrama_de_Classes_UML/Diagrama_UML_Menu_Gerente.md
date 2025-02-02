```mermaid
classDiagram

class I_menu {
    +criar_menu()*
}

class menu_gerente {
    +menu_gerente()
    +criar_menu()*
    +armazenar_ptr(ptr_r: std::shared_ptr<usuario_log>&)
    +terminar_programa(): bool
    +~menu_gerente()
}

class menu_usuarios {
    +menu_usuarios()
    +criar_menu()*
    +~menu_usuarios()
}

class menu_acesso {
    +menu_acesso()
    +criar_menu()*
    +transferir_ptr(ptr_r: std::shared_ptr<usuario_log>&)
    +~menu_acesso()
}

class menu_armazem_g {
    +menu_armazem_g()
    +criar_menu()*
    +~menu_armazem_g()
}

class menu_pratos_g {
    +menu_pratos_g()
    +criar_menu()*
    +~menu_pratos_g()
}

class menu_pedidos_g {
    +menu_pedidos_g()
    +criar_menu()*
    +~menu_pedidos_g()
}

class historico {
    +historico()
    +criar_hist()
    +~historico()
}

class read_dados_map {
    +read_dados_map(arquivo: std::string)
    +ler_dados_completos(cabecalho: std::list<std::string>)
    +~read_dados_map()
}

class cin_r {
    +cin_reset()
}

class usuario_log {
    +usuario_log()
    +~usuario_log()
}

I_menu <|-- menu_gerente
I_menu <|-- menu_usuarios
I_menu <|-- menu_acesso
I_menu <|-- menu_armazem_g
I_menu <|-- menu_pratos_g
I_menu <|-- menu_pedidos_g

menu_gerente o-- menu_usuarios
menu_gerente o-- menu_acesso
menu_gerente o-- menu_armazem_g
menu_gerente o-- menu_pratos_g
menu_gerente o-- menu_pedidos_g
menu_gerente o-- historico
menu_gerente o-- read_dados_map
menu_gerente o-- cin_r
menu_gerente o-- usuario_log