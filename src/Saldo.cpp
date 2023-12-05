#include "Saldo.hpp"
#include <iostream>

Saldo::Saldo() : saldo(0.0) {}

double Saldo::getSaldo() const {
    return saldo;
}

void Saldo::adicionarSaldo(double valor) {
    
    saldo += valor;
}