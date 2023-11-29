#include "Saldo.hpp"
#include <iomanip>
#include <cmath>

Saldo::Saldo() : saldo(0.0) {}

double Saldo::obterSaldo() const {
    return (fabs(saldo));
}

void Saldo::adicionarSaldo(double valor) {
    saldo += (fabs(valor));
}

bool Saldo::diminuirSaldo(double valor) {
    if ((fabs(valor)) > saldo) {
        return false; // Não há saldo suficiente para a operação
    }
    saldo -= (fabs(valor));
    return true;
}
