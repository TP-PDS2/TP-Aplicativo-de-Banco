#include "usuario.h"

using namespace std;

void insert(const string& usuario_,
              const string& nome,
              const string& senha){ //INSERE UM USUÁRIO
  
  if (senha_valida(senha)) {
    auto it = senha_.find(usuario_);
    if (it == senha_.end()) {
      Usuario usuario_;
      usuario_.nome = nome;
      usuario_.senha = senha;
      senha_[usuario] = usuario_;
    }
  }
}

void remove(const string& usuario_){  //REMOVE UM USUÁRIO
   auto it = usuario.find(usuario_);
    if (it != usuario.end()) {
        usuario.erase(it);
    }
}
 
bool senha_valida(const string& senha) const{//uma verificação de senhas válidas?

    if (senha.length() < 8 || senha.length() > 30 {   // verifica se está entre o comprimento mínimo (8) e máximo (30)
      return false;
    } else if (senha.find("12345678") != std::string::npos){ // verifica se não é uma sequnencia
      return false;
    } else if (senha.find("87654321") != std::string::npos){  // verifica se não é uma sequnencia
      return false;
    } else if (senha.find("senha") != std::string::npos){ // verifica se a senha não possui a palavfra senha
      return false;
    }
    bool eh_maiuscula = false;
    bool eh_digito = false;
    bool eh_cespecial = false;
  
  for (char c : password) {
    if (std::isupper(c)) { //verifica se a senha possui pelo menos um caractere maiusculo
      eh_maiuscula = true;
    } else if (std::isdigit(c)) { //verifica se a senha possui pelo menos um digito
      eh_digito = true;
    } else if (ispunct(c)) { //verifica se a senha possui pelo menos um caractere especial
       eh_cespecial = true;
    }
  }
  if (eh_maiuscula && eh_digito && eh_cespecial) { //os tres requisitos são atendidos
      return true;
  } else {
    return false;
  }
}
