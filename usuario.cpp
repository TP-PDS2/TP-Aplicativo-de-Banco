#include "usuario.h"

using namespace std;

void insert(const string& usuario_,
              const string& nome,
              const string& senha){ //INSERE UM USUÁRIO
  
  if (senha_valida(senha)) {
    auto it = senha.find(usuario_);
    if (it == senha.end()) {
      Usuario usuario_;
      usuario_.nome = nome;
      usuario_.senha = senha;
      senha[usuario] = usuario_;
    }
  }
}

  

void remove(const string& usuario_){  //REMOVE UM USUÁRIO
  
}
 

bool senha_valida(const string& senha) const{//uma verificação de senhas válidas?
  
}
