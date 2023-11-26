#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <map>
#include <string>
#include <cctype>

class Usuario {
public:
    void insert(const std::string& usuario_,
                const std::string& nome_,
                const std::string& senha_);

    void remove(const std::string& usuario_);

    bool redefinirSenha(const std::string& usuario_);
    
private:
    bool senhaValida(const std::string& senha_) const;

private:
    struct DadosUsuario_ {
        std::string usuario_;
        std::string senha_;
    };
    std::map<std::string, DadosUsuario_> usuariosRegistrados_;
};

#endif // USUARIO_HPP
