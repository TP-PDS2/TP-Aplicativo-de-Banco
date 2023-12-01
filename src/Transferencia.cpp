//to com sono tem que dar um jeito de fazer o destinatario ter o dinheiro somado e quem esta enviando ter o dinheiro decrescido na hora da transferencia 
#include "Transferencia.hpp"

Transferencia::Transferencia(Usuario& remetente, Usuario& destinatario)
    : remetente_(remetente), destinatario_(destinatario) {}

void Transferencia::realizarTransferencia(double valor) {
    valor = abs(valor);
    if (remetente_.obterSaldo() >= valor) {
        remetente_.adicionarSaldo(-valor);
        destinatario_.adicionarSaldo(valor);
        std::cout << "Transferência de R$ " << valor << " realizada com sucesso." << std::endl;
    } else {
        std::cout << "Saldo insuficiente para realizar a transferência." << std::endl;
    }
}
// aparentemente é isso aqui, mas tem que modificar algumas coisas 

       //////////comentario do arthur: se der certo atrelar o saldo ao numero de cc a gnt vai poder mofificar essa classe pra nao precisar de ter a variavel de rementente e destinatario, a gnt so puxa a cc como parametro

// #include "Transferencia.hpp"
// #include <cmath>
// #include "Saldo.cpp"  
// #include "Usuario.cpp"
// Transferencia::Transferencia(Usuario& remetente, Usuario& destinatario)
//     : remetente_(remetente), destinatario_(destinatario) {}

// void Transferencia::realizarTransferencia(double valor) {
//     valor = fabs(valor);
//     if (remetente_.obterSaldo().diminuirSaldo(valor)) {
//         destinatario_.obterSaldo().adicionarSaldo(valor);
//         std::cout << "Transferência de R$ " << valor << " realizada com sucesso." << std::endl;
//     } else {
//         std::cout << "Saldo insuficiente para realizar a transferência." << std::endl;
//     }
// }
