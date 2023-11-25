#ifndef EXTRATO_HPP
#define EXTRATO_HPP

#include <iostream>
#include <vector>

class Extrato {
public:
    void informarExtratoAnual(int idConta);
    void informarExtratoMensal(int idConta);
    void exportarExtratoDigital(int idConta);
};

#endif
