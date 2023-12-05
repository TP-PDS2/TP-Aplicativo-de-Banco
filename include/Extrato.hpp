#ifndef EXTRATO_HPP
#define EXTRATO_HPP

#include <iostream>
#include <vector>
#include <fstream>

class Extrato {
public:
    void informarExtrato();
    void adicionarTransacao(double valor);
    void exportarExtratoDigital(std::string cc);
private:
    std::vector<double> transacoes;
};

#endif
