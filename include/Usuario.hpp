#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <fstream>
#include <vector>
#include "Saldo.hpp"
#include "Extrato.hpp"
#include <set>


struct DadosUsuario {
    std::string nome;
    std::string senha;
    std::string dataNascimento;
    std::string endereco;
    std::string cpf;
    std::string numeroContaCorrente;
    Saldo saldo;
    Extrato extrato;
};

class Usuario {
public:
    // Função para criar um novo usuário
    void criarNovoUsuario();
    std::string gerarNumeroContaCorrente();
    static bool cpfExistente(const std::string& cpf);
    static void adicionarUsuarioAdministrador();
    static std::vector<DadosUsuario>& getUsuarios();
    bool validarDataNascimento(const std::string& data) const;
    
private:
    // Vetor para armazenar os usuários
    static std::vector<DadosUsuario> usuarios;
    bool senhaValida(const std::string& senha_) const;
    std::set<std::string> numerosContaCorrenteGerados_;
};

#endif
