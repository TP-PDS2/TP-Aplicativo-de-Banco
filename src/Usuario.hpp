#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <map>
#include <set>
#include <string>
#include <cctype>
#include "SistemaBancario.hpp"
#include <iostream>
#include "Saldo.hpp"

class Usuario {
public:
    void insert(const std::string& usuario_, const std::string& senha_, const std::string& opcao_);

    void remove(const std::string& usuario_);

    bool redefinirSenha(const std::string& usuario_);

    // Novo método para criar um novo usuário
    void criarNovoUsuario();
   void adicionarSaldo(double valor);
   double obterSaldo() const;
   bool fazerLogin();
   void realizarOperacoesAposLogin();
   void fazerLogout();
   void mostrarInformacoesUsuario();
   bool excluirConta();

private:
    std::string usuarioAtual_;
    bool senhaValida(const std::string& senha_) const;

private:
    struct DadosUsuario_ {
        std::string usuario_;
        std::string senha_;
        std::string opcao_;
        std::string nome_;
        std::string endereco_;
        std::string cpf_;
        int anoNascimento_;
        std::string numeroContaCorrente_; // Adicionando o número de conta corrente
    };
    Saldo saldo;

    std::map<std::string, DadosUsuario_> usuariosRegistrados_;
    std::set<std::string> numerosContaCorrenteGerados_; // Conjunto para armazenar números de conta corrente gerados

    int tentativasSenha_;

    // Função auxiliar para gerar número de conta corrente aleatório
    std::string gerarNumeroContaCorrente();
};

#endif
