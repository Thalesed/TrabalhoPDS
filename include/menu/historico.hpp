#ifndef HISTORICO_HPP
#define HISTORICO_HPP
#include <string>

class historico
{
    private:
    std::string dir_in = {"Arquivos_de_dados"};
    std::string dir_out = {"Historico"};
    public:
    historico();
    void criar_hist();
    ~historico();
};

#endif // HISTORICO_HPP