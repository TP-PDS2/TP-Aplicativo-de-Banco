#include <map>
#include <string>
#include <cctype>

using std::map;
using std::string;

class Usuário{
  public:
  void insert(const string& usuario_, //CPF?
              const string& nome,
              const string& senha);
  //INSERE UM USUÁRIO

   void remove(const string& usuario_);
  //REMOVE UM USUÁRIO

  bool redefinirsenha(const std::string& usuario);
  //REDEFINE A SENHA DO USUÁRIO ATRAVÉS DE UM TOKEN DE CONFIRMAÇÃO
  //(essa função ainda não pode ser implementada pois depende de estruturas que só serão criadas dentro de outras classes)

  private:
  bool senha_valida(const string& senha) const;//VERIFICA SE A SENHA ATENDE AOS REQUISITOS
  //entre 8 e 30 caracteres
  //possui pelo menos um caractere maiusculo
  //possui pelo menos um número
  //possui pelo menos um caractere especial
  
  private:
  struct Usuario {
    string usuario_;  // CPF do usuario.
    string senha;  // senha do usuario.  
  };
 map<string, Usuario> senha_;
};

  
}
