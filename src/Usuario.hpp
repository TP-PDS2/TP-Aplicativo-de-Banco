#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <fstream>
#include <vector>
#include <set>
#include "Saldo.hpp"


struct DadosUsuario {
    std::string nome;
    std::string senha;
    std::string dataNascimento;
    std::string endereco;
    std::string cpf;
    std::string numeroContaCorrente;
};

class Usuario {
public:
    // Função para criar um novo usuário
    void criarNovoUsuario(const std::string& nomeArquivo = "usuarios.txt");
    std::string gerarNumeroContaCorrente();
    void salvarUsuariosEmArquivo(const std::string& nomeArquivo = "usuarios.txt") const;
    void carregarUsuariosDeArquivo(const std::string& nomeArquivo = "usuarios.txt");
    bool usuarioExiste(const std::string& nome) const;
    bool fazerLogin(const std::string& cpf, const std::string& senha) const;
    double obterSaldo() const;

private:
    // Vetor para armazenar os usuários
    std::vector<DadosUsuario> usuarios;
    bool senhaValida(const std::string& senha_) const;
    std::set<std::string> numerosContaCorrenteGerados_;
    Saldo saldo;
};

#endif // USUARIO_HPP
