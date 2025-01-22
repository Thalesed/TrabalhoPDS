#ifndef SET_MAP_FILE_HPP
#define SET_MAP_FILE_HPP

#include "I_set_map_file.hpp"
#include <string>
#include <list>
#include <map>
#include <fstream>

class set_map_file:public I_set_map_file
{
    private:
    std::ofstream file_o_m;
    std::string nome_arquivo;
    public:
    set_map_file(std::string& nome_arquivo_in);
    void abrir_arquivo() override;
    void set_m_file(std::map<std::string,std::list<std::string>> o_m_data) override;
    ~set_map_file();
};

#endif // SET_MAP_FILE_HPP

// Essa classe é responsável por escrever no arquivo os dados de uma variável map.