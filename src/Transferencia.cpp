#include "Transferencia.hpp"

Transferencia::Transferencia(Usuario& remetente, Usuario& destinatario)
    : remetente_(remetente), destinatario_(destinatario) {}

void Transferencia::realizarTransferencia(double valor) {
    if (remetente_.obterSaldo() >= valor) {
        remetente_.adicionarSaldo(-valor);
        destinatario_.adicionarSaldo(valor);
        std::cout << "Transferência de R$ " << valor << " realizada com sucesso." << std::endl;
    } else {
        std::cout << "Saldo insuficiente para realizar a transferência." << std::endl;
    }
}
