```mermaid
classDiagram

class I_usuario_log {
    +~I_usuario_log() = default
    +set_user_log()
    +get_user_log_atual()
    +get_user_log_historico()
}

class usuario_log {
    -std::string user_nome
    -std::string nome_arquivo
    -std::list<std::any> dados_acesso_out
    +usuario_log()
    +set_user_log(user_data: std::string&)
    +get_user_log_atual()
    +get_user_log_historico()
    +transmitir_user(): std::string
}

class I_login {
    +~I_login() = default
    +verificar_usuario()
    +registrar_acesso(ptr_1: std::shared_ptr<usuario_log>&)
}

class login {
    -std::string nome
    -std::string senha
    -std::string nome_arquivo
    -std::map<std::string, std::string> dados_user
    -int opcao
    +login()
    +verificar_usuario()
    +registrar_acesso(ptr_1: std::shared_ptr<usuario_log>&)
}

I_usuario_log <|-- usuario_log
I_login <|-- login

usuario_log o-- set_dados_file
usuario_log o-- read_dados_map
login o-- get_file_dados