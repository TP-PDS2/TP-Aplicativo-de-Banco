#include <iostream>
#include "SistemaBancario.hpp"
#include "Usuario.hpp"

using namespace std;

int main()
{
    Usuario usuario;
    usuario.adicionarUsuarioAdministrador();
    SistemaBancario sistema;
    sistema.executarAplicativo();
    
    return 0;
    
}
