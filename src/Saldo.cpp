#include "Saldo.hpp"

Saldo::Saldo() : saldo_(0.0) {}

void Saldo::adicionarSaldo(double valor) {
    saldo_ += valor;
}

double Saldo::obterSaldo() const {
    return saldo_;
}
