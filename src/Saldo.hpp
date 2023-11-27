#ifndef SALDO_HPP
#define SALDO_HPP

class Saldo {
public:
    Saldo();

    void adicionarSaldo(double valor);

    // Obter saldo atual
    double obterSaldo() const;

private:
    double saldo_;
};

#endif // SALDO_HPP
