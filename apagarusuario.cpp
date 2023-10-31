#include "apagarusuario.h"
#include "usuario.h"

void apagarUsuario(const std::string& cpf) {
    auto it = usuarios.find(cpf);
    if (it != usuarios.end()) {
        usuarios.erase(it);
    }
}
