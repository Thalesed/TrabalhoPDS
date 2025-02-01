#ifndef ADD_FILE_PEDIDOS_HPP
#define ADD_FILE_PEDIDOS_HPP

#include "I_add_file.hpp"
#include <fstream>
#include <string>

class add_file_pedidos:public I_add_file
{
    private:
    std::ofstream file_c;
    std::string dir_path = "Arquivos_de_dados/pedidos/";
    std::string fil_path;
    public:
    add_file_pedidos();
    std::string get_data();
    bool ver_dir(std::string&,std::string&);
    void add_file() override;
    std::string trans_pth();
    ~add_file_pedidos();
};

#endif // ADD_FILE_PEDIDOS_HPP