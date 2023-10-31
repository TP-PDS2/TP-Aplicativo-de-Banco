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

  if (senha.length() < 8 || senha.length() > 30 {   // Comprimento mínimo e máximo
    return false;
  } else if (senha.find("12345678") != std::string::npos){
    return false;
  } else if (senha.find("87654321") != std::string::npos){
    return false;
  } else if (senha.find("senha") != std::string::npos){
    return false;
  }
}
