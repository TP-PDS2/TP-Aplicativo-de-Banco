#include "Banco.hpp"
#include "Saldo.hpp"

int Banco::gerarContaCorrente() {
    // Geração de um número aleatório para a conta corrente (exemplo)
    srand(time(NULL));
    int idConta = rand() % 900000 + 100000; // Número de 6 dígitos
    contasCorrentes[idConta] = Saldo(); // Inicializa a conta corrente com saldo zero
    return idConta;
}

double Banco::informarSaldo(int idConta) {
    return contasCorrentes[idConta].getSaldo();
}

void Banco::deposito(int idConta, double valor) {
    contasCorrentes[idConta].setSaldo(contasCorrentes[idConta].getSaldo() + valor);
}

void Banco::enviarNotificacoes() {
    // Lógica para enviar notificações
}

void Banco::ativarNotificacoes(int idConta) {
    // Lógica para ativar notificações para a conta específica
}

void Banco::desativarNotificacoes(int idConta) {
    // Lógica para desativar notificações para a conta específica
}
