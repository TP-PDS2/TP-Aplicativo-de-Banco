       //////////comentario do arthur: se der certo atrelar o saldo ao numero de cc a gnt vai poder mofificar essa classe pra nao precisar de ter a variavel de rementente e destinatario, a gnt so puxa a cc como parametro
       //////////comentario do Isaac: acho que está funcionando
 #include "Transferencia.hpp"
 #include <cmath>
 #include "Saldo.cpp"  
 #include "Usuario.cpp"
 Transferencia::Transferencia(Usuario& remetente, Usuario& destinatario)
    : remetente_(remetente), destinatario_(destinatario) {}

void Transferencia::realizarTransferencia(double valor) {
    valor = fabs(valor);
  double saldoRemetente = remetente_.obterSaldo();

  if (saldoRemetente >= valor) {
      remetente_.diminuirSaldo(valor);  // 
      destinatario_.adicionarSaldo(valor);
      std::cout << "Transferência de R$ " << valor << " realizada com sucesso." << std::endl;
  } else {
      std::cout << "Saldo insuficiente para realizar a transferência." << std::endl;
  }
}
