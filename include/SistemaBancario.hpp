#ifndef SISTEMABANCARIO_HPP
#define SISTEMABANCARIO_HPP

#include "Usuario.hpp"
#include "Transferencia.hpp"
#include "Emprestimo.hpp"

class SistemaBancario {
public:
    void executarAplicativo();
    SistemaBancario();
    double lerNumero();

private:
    static void exibirMensagemBoasVindas();
    void cadastrarNovoUsuario();
    std::vector<DadosUsuario> usuarios;
    DadosUsuario* usuarioLogado;
    DadosUsuario* usuarioTransfere;
    void fazerLogin();
    Usuario usuario;
    void realizarOperacoesAposLogin();
    int opcao; 
};

#endif
