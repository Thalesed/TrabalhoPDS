```mermaid
classDiagram

class I_open_file {
    +virtual void abrir_arquivo() = 0
}

class I_read_file {
    +virtual void ler_arquivo() = 0
}

class I_read_dados_map {
    +virtual void ler_dados_completos(std::list<std::string>&) = 0
    +virtual void ler_dados_parciais(std::string&,std::list<std::string>&) = 0
}

class I_modificar_file {
    +virtual void modificar_arquivo(std::any&, const int&, const std::string&) = 0
}

class I_write_file {
    +virtual void escrever_arquivo(const std::list<std::any>&) = 0
}

class I_set_map_file {
    +virtual void set_m_file(std::map<std::string,std::list<std::string>>) = 0
}

class I_delete_file {
    +virtual void deletar_dados_arquivo(std::string&) = 0
}
class I_get_dados_map{
    +virtual void get_data_map(std::string&) = 0
}

class get_file_dados {
    -std::ifstream s_arquivo
    -std::map<std::string,std::list<std::string>> r_file
    -std::string nome_arquivo
    +get_file_dados(std::string nome_arquivo_in)
    +void abrir_arquivo()
    +void ler_arquivo()
    +const std::map<std::string, std::vector<std::string>>& transmitir_map()
}

class read_dados_map {
    -std::map<std::string,std::list<std::string>> r_d_file
    +read_dados_map(std::string& arquivo)
    +void ler_dados_completos(std::list<std::string>& cabecalho)
    +void ler_dados_parciais(std::string& chave_r,std::list<std::string>& cabecalho)
}

class set_dados_file {
    -std::ofstream file_w_e
    -std::list<std::string> dados_convertidos
    -std::string nome_arquivo
    +set_dados_file(std::string& nome_arquivo_in)
    +void abrir_arquivo()
    +void escrever_arquivo(const std::list<std::any>& dado)
}

class modificar_dados_file {
    -std::fstream file_m
    -std::list<std::string> dados_arquivo
    -std::string nome_arquivo
    -std::map<std::string,std::list<std::string>> r_data
    +modificar_dados_file(std::string& nome_arquivo_in)
    +void modificar_arquivo(std::any& dado,const int& posicao,const std::string& chave)
}

class deletar_dados_file {
    -std::string nome_arquivo
    -std::map<std::string,std::list<std::string>> e_data
    +deletar_dados_file(std::string& nome_arquivo_in)
    +void deletar_dados_arquivo(std::string& chave)
}

class set_map_file{
    -std::ofstream file_o_m
    -std::string nome_arquivo
    +set_map_file(std::string& nome_arquivo_in)
    +void set_m_file(std::map<std::string,std::list<std::string>> o_m_data)
}

class get_dados_map{
    -std::map<std::string,std::list<std::string>> g_m_data;
    -std::map<std::string,std::list<std::string>> g_m_data_parcial;
    +get_dados_map(std::string& nome_arquivo)
    +void get_dados(std::string& chave);
    +const std::map<std::string,std::list<std::string>> transmitir_dados_parciais();
}
class verificar_arquivo_error{
    +verificar_arquivo_error(std::string& nome_arquivo)
}

I_open_file <|-- I_read_file
I_open_file <|-- I_write_file
I_open_file <|-- I_set_map_file

I_read_file <|-- get_file_dados
I_read_dados_map <|-- read_dados_map
I_modificar_file <|-- modificar_dados_file
I_write_file <|-- set_dados_file
I_set_map_file <|-- set_map_file
I_delete_file <|-- deletar_dados_file
I_get_dados_map <|-- get_dados_map

read_dados_map *-- get_file_dados
modificar_dados_file *-- get_file_dados
deletar_dados_file *-- get_file_dados
get_dados_map *-- get_file_dados

get_file_dados *-- verificar_arquivo_error
set_dados_file *-- verificar_arquivo_error
set_map_file *-- verificar_arquivo_error
