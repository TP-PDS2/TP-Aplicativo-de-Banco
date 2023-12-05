#include "Emprestimo.hpp"

Emprestimo::Emprestimo (double valorTransferencia, unsigned int parcelas) : valorTotal(valorTransferencia), qtdParcelas(parcelas), taxaJuros(1.1) {}

void Emprestimo::calcularJuros() {
    // Lógica para calcular juros do empréstimo
    valorPagamento=valorTotal*1.1;
}

double Emprestimo::calcularValorParcela() {
    // Lógica para calcular valor da parcela do empréstimo
    calcularJuros();
    std::cout<<"Pagamento total: "<<valorPagamento<<"\n";
    std::cout<<"Valor de cada Parcela: "<<valorPagamento/qtdParcelas<<"\n";

    return (valorPagamento/qtdParcelas); // Exemplo: retorna 0
}

double Emprestimo::confirmarSolicitacao(double salario) {
    // Lógica para confirmar a solicitação do empréstimo
    if(salario>(calcularValorParcela()/2)){
        std::cout<<"Solitação confirmada"<<std::endl;
        return valorTotal;
    }else{
        std::cout<<"Salario insuficiente"<<std::endl;
        return 0;
    }
}
