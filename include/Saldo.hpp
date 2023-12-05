#ifndef SALDO_HPP
#define SALDO_HPP

class Saldo {
public:
    Saldo();
    double getSaldo() const;
    void adicionarSaldo(double valor);
    

private:
    double saldo;
};

#endif
