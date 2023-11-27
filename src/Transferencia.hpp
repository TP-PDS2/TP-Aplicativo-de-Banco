#ifndef TRANSFERENCIA_HPP
#define TRANSFERENCIA_HPP

#include <iostream>

class Transferencia {
public:
    void realizarTransferencia(int idContaOrigem, int idContaDestino, double valor);
    void notificarErro();
    void notificarTransf();
};

#endif
