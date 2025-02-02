
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

class menu_funcionario {
    +menu_funcionario()
    +criar_menu()*
    +~menu_funcionario()
}

class menu_gerente {
    +menu_gerente()
    +criar_menu()*
    +armazenar_ptr(ptr_r: std::shared_ptr<usuario_log>&)
    +terminar_programa(): bool
    +~menu_gerente()
}

class menu_pedidos_g {
    +menu_pedidos_g()
    +criar_menu()*
    +~menu_pedidos_g()
}

class menu_pratos_g {
    +menu_pratos_g()
    +criar_menu()*
    +~menu_pratos_g()
}

class menu_armazem_g {
    +menu_armazem_g()
    +criar_menu()*
    +~menu_armazem_g()
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

class set_menu {
    +set_menu()
    +transmitir_priv(std::shared_ptr<usuario_log>&)
    +~set_menu()
}

class menu_inicial {
    +menu_inicial()
    +criar_menu()
    +~menu_inicial()
}

class historico {
    +historico()
    +criar_hist()
    +~historico()
}

I_menu <|-- menu_cliente
I_menu <|-- menu_funcionario
I_menu <|-- menu_gerente
I_menu <|-- menu_pedidos_g
I_menu <|-- menu_pratos_g
I_menu <|-- menu_armazem_g
I_menu <|-- menu_usuarios
I_menu <|-- menu_acesso
I_menu <|-- menu_inicial

main.cpp o-- menu_inicial
menu_gerente o-- menu_usuarios
menu_gerente o-- menu_pratos_g
menu_gerente o-- menu_armazem_g
menu_gerente o-- menu_pedidos_g
menu_gerente o-- historico
menu_gerente o-- menu_acesso
menu_funcionario o-- menu_pedidos_g
menu_cliente o-- set_menu
menu_inicial o-- set_menu
menu_inicial o-- menu_gerente
menu_inicial o-- menu_funcionario
menu_inicial o-- menu_cliente