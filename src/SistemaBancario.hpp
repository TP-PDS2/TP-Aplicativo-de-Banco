#ifndef SISTEMABANCARIO_HPP
#define SISTEMABANCARIO_HPP

#include "Usuario.hpp"

class SistemaBancario {
public:
    void executarAplicativo();
    SistemaBancario();

private:
    static void exibirMensagemBoasVindas();
    void cadastrarNovoUsuario();
    void listarCPFsCadastrados();
    void realizarOperacoesAposLogin();
    std::vector<DadosUsuario> usuarios;

    int opcao; 
};

#endif
