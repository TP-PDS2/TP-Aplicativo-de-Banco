#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <fstream>
#include <vector>
#include "Saldo.hpp"
#include <set>


struct DadosUsuario {
    std::string nome;
    std::string senha;
    std::string dataNascimento;
    std::string endereco;
    std::string cpf;
    std::string numeroContaCorrente;
    Saldo saldo;
};

class Usuario {
public:
    // Função para criar um novo usuário
    void criarNovoUsuario();
    std::string gerarNumeroContaCorrente();
    static bool cpfExistente(const std::string& cpf);
    static void adicionarUsuarioAdministrador();
    static const std::vector<DadosUsuario>& getUsuarios();
    double obterSaldo() const;
    void adicionarSaldo(double valor);
    bool diminuirSaldo(double valor);
    bool validarDataNascimento(const std::string& data) const;

    Saldo& getSaldo(){
       return saldo;
    }

    const Saldo& getSaldo() const{
      return saldo;
    }
    
    void setSaldo(const Saldo& novoSaldo){
      saldo = novoSaldo;
    }

private:
    // Vetor para armazenar os usuários
    static std::vector<DadosUsuario> usuarios;
    Saldo saldo;
    bool senhaValida(const std::string& senha_) const;
    std::set<std::string> numerosContaCorrenteGerados_;
};

#endif
