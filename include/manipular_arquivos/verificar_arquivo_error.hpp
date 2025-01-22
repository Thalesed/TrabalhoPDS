#ifndef VERIFICAR_ARQUIVO_ERROR_HPP
#define VERIFICAR_ARQUIVO_ERROR_HPP

#include <string>

struct verificar_arquivo_error
{
    verificar_arquivo_error(std::string& nome_arquivo);
    ~verificar_arquivo_error();
};

#endif // VERIFICAR_ARQUIVO_ERROR_HPP

/* Essa função é responsável por verificar se o arquivo existe, caso não exista ele irá retornar uma mensagem de erro.Quando a parte do menu
for feita caso aconteça algum erro o programa irá mandar o usuário para o menu principal*/