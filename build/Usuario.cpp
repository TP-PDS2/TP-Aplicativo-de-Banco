#include "Usuario.hpp"

void Usuario::insert(const std::string& usuario_,
                     const std::string& nome,
                     const std::string& senha) {
    if (senhaValida(senha)) {
        auto it = senha_.find(usuario_);
        if (it == senha_.end()) {
            Usuar_ usuarioTemp;
            usuarioTemp.usuario_ = usuario_;
            usuarioTemp.senha = senha;
            senha_[usuario_] = usuarioTemp;
        }
    }
}

void Usuario::remove(const std::string& usuario_) {
    auto it = senha_.find(usuario_);
    if (it != senha_.end()) {
        senha_.erase(it);
    }
}

bool Usuario::senhaValida(const std::string& senha) const {
    if (senha.length() < 8 || senha.length() > 30) { // verifica se está entre o comprimento mínimo (8) e máximo (30)
        return false;
    } else if (senha.find("12345678") != std::string::npos) { // verifica se não é uma sequência
        return false;
    } else if (senha.find("87654321") != std::string::npos) {  // verifica se não é uma sequência
        return false;
    } else if (senha.find("senha") != std::string::npos) { // verifica se a senha não possui a palavra "senha"
        return false;
    }
    
    bool eh_maiuscula = false;
    bool eh_digito = false;
    bool eh_cespecial = false;

    for (char c : senha) {
        if (std::isupper(c)) { // verifica se a senha possui pelo menos um caractere maiúsculo
            eh_maiuscula = true;
        } else if (std::isdigit(c)) { // verifica se a senha possui pelo menos um dígito
            eh_digito = true;
        } else if (std::ispunct(c)) { // verifica se a senha possui pelo menos um caractere especial
            eh_cespecial = true;
        }
    }

    if (eh_maiuscula && eh_digito && eh_cespecial) { // os três requisitos são atendidos
        return true;
    } else {
        return false;
    }
}

bool Usuario::redefinirSenha(const std::string& usuario) {
    // Implemente a redefinição de senha aqui
    return false; // Retorno falso padrão para a função
}
