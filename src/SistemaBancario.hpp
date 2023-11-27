#ifndef SISTEMABANCARIO_HPP
#define SISTEMABANCARIO_HPP

#include "Usuario.hpp"

class SistemaBancario {
public:
    SistemaBancario();

    void menuPrincipal();

private:
    Usuario usuarioAtual;

    void realizarLogin();
    void cadastrarNovoUsuario();
    void exibirMenuUsuarioLogado();
    void exibirInformacoesUsuario();
};

#endif // SISTEMABANCARIO_HPP
