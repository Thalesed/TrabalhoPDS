# Diagrama UML dos Menus Centrais e suas Derivações

```mermaid
classDiagram

class I_menu {
    +criar_menu()*
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

class set_pedido {
    +set_pedido()
    +set_valor()
    +~set_pedido()
}

class set_prato {
    +set_prato()
    +set_valor()
    +~set_prato()
}

class set_armazem {
    +set_armazem()
    +set_valor()
    +~set_armazem()
}

class set_usuario {
    +set_usuario()
    +set_valor()
    +~set_usuario()
}

class mod_valor_pedidos {
    +mod_valor_pedidos()
    +mod_val()
    +~mod_valor_pedidos()
}

class mod_valor_pratos {
    +mod_valor_pratos()
    +mod_val()
    +~mod_valor_pratos()
}

class mod_valor_armazem {
    +mod_valor_armazem()
    +mod_val()
    +~mod_valor_armazem()
}

class mod_valor_usuarios {
    +mod_valor_usuarios()
    +mod_val()
    +~mod_valor_usuarios()
}

class get_valor_pedidos {
    +get_valor_pedidos()
    +get_val()
    +~get_valor_pedidos()
}

class get_valor_pratos {
    +get_valor_pratos()
    +get_val()
    +~get_valor_pratos()
}

class get_valor_armazem {
    +get_valor_armazem()
    +get_val()
    +~get_valor_armazem()
}

class get_valor_usuarios {
    +get_valor_usuarios()
    +get_val()
    +~get_valor_usuarios()
}

class del_valor_pedidos {
    +del_valor_pedidos()
    +del_val()
    +~del_valor_pedidos()
}

class del_valor_pratos {
    +del_valor_pratos()
    +del_val()
    +~del_valor_pratos()
}

class del_valor_armazem {
    +del_valor_armazem()
    +del_val()
    +~del_valor_armazem()
}

class del_valor_usuarios {
    +del_valor_usuarios()
    +del_val()
    +~del_valor_usuarios()
}

I_menu <|-- menu_pedidos_g
I_menu <|-- menu_pratos_g
I_menu <|-- menu_armazem_g
I_menu <|-- menu_usuarios
I_menu <|-- menu_acesso

menu_pedidos_g o-- set_pedido
menu_pedidos_g o-- mod_valor_pedidos
menu_pedidos_g o-- get_valor_pedidos
menu_pedidos_g o-- del_valor_pedidos

menu_pratos_g o-- set_prato
menu_pratos_g o-- mod_valor_pratos
menu_pratos_g o-- get_valor_pratos
menu_pratos_g o-- del_valor_pratos

menu_armazem_g o-- set_armazem
menu_armazem_g o-- mod_valor_armazem
menu_armazem_g o-- get_valor_armazem
menu_armazem_g o-- del_valor_armazem

menu_usuarios o-- set_usuario
menu_usuarios o-- mod_valor_usuarios
menu_usuarios o-- get_valor_usuarios
menu_usuarios o-- del_valor_usuarios

menu_acesso o-- usuario_log