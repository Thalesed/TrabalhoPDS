```mermaid
classDiagram

class I_menu {
    +criar_menu()*
}

class menu_funcionario {
    +menu_funcionario()
    +criar_menu()*
    +~menu_funcionario()
}

class menu_pedidos_g {
    +menu_pedidos_g()
    +criar_menu()*
    +~menu_pedidos_g()
}

class get_valor {
    +get_valor(arquivo: std::string, cabecalho: std::list<std::string>)
    +get_val()
    +~get_valor()
}

class cin_r {
    +cin_reset()
}

I_menu <|-- menu_funcionario
I_menu <|-- menu_pedidos_g

menu_funcionario o-- menu_pedidos_g
menu_funcionario o-- get_valor
menu_funcionario o-- cin_r