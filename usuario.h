#include <map>
#include <string>

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

  bool senha_valida(const string& senha) const;//uma verificação de senhas válidas?
  private:
  struct Usuario {
    string usuario_;  // CPF do usuario.
    string senha;  // senha do usuario.  
  };
 map<string, Usuario> senha_;
};

  
}
