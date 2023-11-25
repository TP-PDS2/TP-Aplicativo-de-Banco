#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <map>
#include <string>
#include <cctype>

class Usuario {
public:
    void insert(const std::string& usuario_,
                const std::string& nome,
                const std::string& senha);
    // INSERE UM USUÁRIO

    void remove(const std::string& usuario_);
    // REMOVE UM USUÁRIO

    bool redefinirSenha(const std::string& usuario);
    // REDEFINE A SENHA DO USUÁRIO ATRAVÉS DE UM TOKEN DE CONFIRMAÇÃO

private:
    bool senhaValida(const std::string& senha) const;
    // VERIFICA SE A SENHA ATENDE AOS REQUISITOS

private:
    struct Usuar_ {
        std::string usuario_;  // CPF do usuário.
        std::string senha;     // senha do usuário.
    };
    std::map<std::string, Usuar_> senha_;
};

#endif
