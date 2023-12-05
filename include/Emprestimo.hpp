#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include <iostream>
#include <string>

class Emprestimo {
private:
    double valorPagamento;
    double valorTotal;
    double taxaJuros;
    int qtdParcelas;

public:
    // Métodos para definir e obter informações sobre o empréstimo
    Emprestimo (double valorTransferencia, unsigned int parcelas);
    void calcularJuros();
    double calcularValorParcela();
    double confirmarSolicitacao(double salario);
};

#endif
