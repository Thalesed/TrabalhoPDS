#ifndef SEE_FILE_HPP
#define SEE_FILE_HPP
#include "I_see_file.hpp"
#include <string>
#include <vector>

class see_file:public I_see_file
{
    private:
    int i = 0;
    std::string diretorio;
    std::vector<std::string> f_data;
    public:
    see_file(std::string&);
    void ver_file() override;
    std::string selec_file();
    void exibir_file();
    ~see_file();
};


#endif // SEE_FILE_HPP