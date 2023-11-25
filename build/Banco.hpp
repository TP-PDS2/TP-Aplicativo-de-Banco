#ifndef BANCO_HPP
#define BANCO_HPP

#include <iostream>
#include <map>
#include <vector>
#include <ctime>

class Saldo;

class Banco {
private:
    std::map<int, Saldo> contasCorrentes; // Mapa com IDs de contas e seus saldos

public:
    int gerarContaCorrente();
    double informarSaldo(int idConta);
    void deposito(int idConta, double valor);
    void enviarNotificacoes();
    void ativarNotificacoes(int idConta);
    void desativarNotificacoes(int idConta);
};

#endif
