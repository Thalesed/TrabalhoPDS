#ifndef MODIFICAR_DADOS_FILE_HPP
#define MODIFICAR_DADOS_FILE_HPP

#include "I_modificar_file.hpp"
#include <fstream>
#include <list>
#include <map>
#include <any>

class modificar_dados_file:public I_modificar_file
{
    private:
        std::fstream file_m;
        std::list<std::string> dados_arquivo;
        std::string nome_arquivo;
        std::map<std::string,std::list<std::string>> r_data;
    public:
        modificar_dados_file(std::string& nome_arquivo_in);
        void modificar_arquivo(std::any& dado,const int& posicao,const std::string& chave) override;
        ~modificar_dados_file();
};

#endif // MODIFICAR_DADOS_FILE_HPP

/* Essa classe é responsável por modificar dados de um arquivo csv. A forma como isso será feito será por meio do arquivamento das informações
dos arquviso em uma variavel map que será modificada por essa classe */