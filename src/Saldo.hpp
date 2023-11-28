#ifndef SALDO_HPP
#define SALDO_HPP

class Saldo {
public:
    Saldo();
    double obterSaldo() const;
    void adicionarSaldo(double valor);
    bool diminuirSaldo(double valor);

private:
    double saldo;
};

#endif // SALDO_HPP
