#include "Saldo.hpp"
#include <iomanip>

Saldo::Saldo() : saldo(0.0) {}

double Saldo::obterSaldo() const {
    return saldo;
}

void Saldo::adicionarSaldo(double valor) {
    saldo += valor;
}

bool Saldo::diminuirSaldo(double valor) {
    if (valor > saldo) {
        return false; // Não há saldo suficiente para a operação
    }
    saldo -= valor;
    return true;
}
