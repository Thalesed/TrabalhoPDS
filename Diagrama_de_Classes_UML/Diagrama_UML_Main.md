```mermaid
classDiagram

class I_menu {
    +criar_menu()*
}

class menu_inicial {
    +menu_inicial()
    +criar_menu()
    +~menu_inicial()
}

class cin_r {
    +cin_reset()
}

class set_cliente {
    +set_cliente()
    +set_valor(arquivo: std::string)
    +~set_cliente()
}

class login {
    +login()
    +verificar_usuario()
    +registrar_acesso(ptr: std::shared_ptr<usuario_log>)
    +~login()
}

class usuario_log {
    +usuario_log()
    +~usuario_log()
}

class set_menu {
    +set_menu()
    +transmitir_priv(ptr: std::shared_ptr<usuario_log>&): std::string
    +~set_menu()
}

class menu_gerente {
    +menu_gerente()
    +criar_menu()*
    +armazenar_ptr(ptr: std::shared_ptr<usuario_log>&)
    +terminar_programa(): bool
    +~menu_gerente()
}

class menu_funcionario {
    +menu_funcionario()
    +criar_menu()*
    +~menu_funcionario()
}

class menu_cliente {
    +menu_cliente()
    +criar_menu()*
    +~menu_cliente()
}

I_menu <|-- menu_inicial
I_menu <|-- menu_gerente
I_menu <|-- menu_funcionario
I_menu <|-- menu_cliente

main.cpp o-- menu_inicial
menu_inicial o-- cin_r
menu_inicial o-- set_cliente
menu_inicial o-- login
menu_inicial o-- usuario_log
menu_inicial o-- set_menu
menu_inicial o-- menu_gerente
menu_inicial o-- menu_funcionario
menu_inicial o-- menu_cliente