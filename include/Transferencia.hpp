#ifndef TRANSFERENCIA_HPP
#define TRANSFERENCIA_HPP

#include <iostream>
#include <string>
#include "Usuario.hpp"

class Transferencia {
public:
    
    Transferencia(Usuario& remetente, Usuario& destinatario);

    void realizarTransferencia(double valor);

private:
    Usuario& remetente_;
    Usuario& destinatario_;
};

#endif
