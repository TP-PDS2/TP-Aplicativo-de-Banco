#include "Usuario.hpp"

void Usuario::insert(const std::string& usuario_,
                     const std::string& nome_,
                     const std::string& senha_) {
    if (senhaValida(senha_)) {
        auto it = usuariosRegistrados_.find(usuario_);
        if (it == usuariosRegistrados_.end()) {
            DadosUsuario usuarioTemp;
            usuarioTemp.usuario_ = usuario_;
            usuarioTemp.senha_ = senha_;
            usuariosRegistrados_[usuario_] = usuarioTemp;
        }
    }
}

void Usuario::remove(const std::string& usuario_) {
    auto it = usuariosRegistrados_.find(usuario_);
    if (it != usuariosRegistrados_.end()) {
        usuariosRegistrados_.erase(it);
    }
}

bool Usuario::senhaValida(const std::string& senha_) const {
    if (senha_.length() < 8 || senha_.length() > 30) { // verifica se está entre o comprimento mínimo (8) e máximo (30)
        return false;
    } else if (senha_.find("12345678") != std::string::npos || 
               senha_.find("87654321") != std::string::npos ||
               senha_.find("senha") != std::string::npos) { // verifica se não contém sequências ou palavras proibidas
        return false;
    }
    
    bool temMaiuscula = false;
    bool temDigito = false;
    bool temCaracterEspecial = false;

    for (char c : senha_) {
        if (std::isupper(c)) { // verifica se a senha possui pelo menos um caractere maiúsculo
            temMaiuscula = true;
        } else if (std::isdigit(c)) { // verifica se a senha possui pelo menos um dígito
            temDigito = true;
        } else if (std::ispunct(c)) { // verifica se a senha possui pelo menos um caractere especial
            temCaracterEspecial = true;
        }
    }

    // Os três requisitos são atendidos
    return temMaiuscula && temDigito && temCaracterEspecial;
}

bool Usuario::redefinirSenha(const std::string& usuario_) {
    // Implemente a redefinição de senha aqui
    return false; // Retorno falso padrão para a função
}
