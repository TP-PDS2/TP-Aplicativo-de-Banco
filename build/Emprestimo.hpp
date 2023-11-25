#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include <iostream>
#include <string>

class Emprestimo {
private:
    int idContaCorrente;
    std::string dataVencimento;
    double valorTotal;
    double taxaJuros;
    int qtdParcelas;

public:
    // Métodos para definir e obter informações sobre o empréstimo
    double calcularJuros();
    double calcularValorParcela();
    void confirmarSolicitacao();
};

#endif
