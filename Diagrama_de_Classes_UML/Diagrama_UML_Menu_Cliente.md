```mermaid
classDiagram

class I_menu {
    +criar_menu()*
}

class menu_cliente {
    +menu_cliente()
    +criar_menu()*
    +~menu_cliente()
}

class set_menu {
    +set_menu()
    +transmitir_priv(std::shared_ptr<usuario_log>&)
    +~set_menu()
}

class get_valor {
    +get_valor(arquivo: std::string, cabecalho: std::list<std::string>)
    +get_val()
    +~get_valor()
}

class cin_r {
    +cin_reset()
}

I_menu <|-- menu_cliente

menu_cliente o-- set_menu
menu_cliente o-- get_valor
menu_cliente o-- cin_r