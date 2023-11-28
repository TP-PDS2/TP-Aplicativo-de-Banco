#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include "Usuario.hpp"

void Usuario::criarNovoUsuario() {
    DadosUsuario_ novoUsuario;
    
    std::cout << "Nome completo: ";
    std::getline(std::cin >> std::ws, novoUsuario.nome_);

    std::cout << "Endereço: ";
    std::getline(std::cin, novoUsuario.endereco_);

    std::cout << "CPF (somente números, no formato XXXXXXXXXXX): ";
    std::cin >> novoUsuario.cpf_;

    if (novoUsuario.cpf_.size() != 11 || novoUsuario.cpf_.find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "CPF inválido. Deve conter exatamente 11 números." << std::endl;
        return;
    }

    std::cout << "Ano de nascimento: ";
    std::cin >> novoUsuario.anoNascimento_;
    
    std::cout << "\nRequisitos para senha:\n"
              << "- Deve ter entre 8 e 30 caracteres.\n"
              << "- Deve conter pelo menos uma letra maiúscula.\n"
              << "- Deve conter pelo menos um caractere especial.\n"
              << "- Deve conter pelo menos um número.\n";

    do {
        std::cout << "Senha desejada: ";
        std::cin.ignore();
        std::getline(std::cin, novoUsuario.senha_);
    } while (!senhaValida(novoUsuario.senha_));

    novoUsuario.usuario_ = novoUsuario.cpf_;
    novoUsuario.usuario_.erase(remove_if(novoUsuario.usuario_.begin(), novoUsuario.usuario_.end(),
                                         [](char c) { return c == '.' || c == '-'; }), novoUsuario.usuario_.end());

    novoUsuario.numeroContaCorrente_ = gerarNumeroContaCorrente();

    usuariosRegistrados_[novoUsuario.usuario_] = novoUsuario;
    
    std::cout << "\n========================================\n";
    std::cout << "Novo usuário criado com sucesso!" << std::endl;
    std::cout << "\n========================================\n";
}

bool Usuario::senhaValida(const std::string& senha_) const {
    if (senha_.length() < 8 || senha_.length() > 30) {
        std::cout << "A senha deve ter entre 8 e 30 caracteres." << std::endl;
        return false;
    }

    bool temMaiuscula = false;
    bool temCaracterEspecial = false;
    bool temNumero = false;

    for (char c : senha_) {
        if (std::isupper(c)) {
            temMaiuscula = true;
        } else if (std::isdigit(c)) {
            temNumero = true;
        } else if (!std::isalnum(c)) {
            temCaracterEspecial = true;
        }
    }

    if (!temMaiuscula || !temNumero || !temCaracterEspecial) {
        std::cout << "A senha deve atender aos requisitos de maiúsculas, números e caracteres especiais." << std::endl;
        return false;
    }

    return true;
}

std::string Usuario::gerarNumeroContaCorrente(){
    srand(time(nullptr));

    std::string numeroContaCorrente;
    bool numeroDuplicado;

    do {
        int numeroAleatorio = rand() % 900000 + 100000;  // Gera 6 números aleatórios
        numeroContaCorrente = std::to_string(numeroAleatorio);

        numeroDuplicado = numerosContaCorrenteGerados_.find(numeroContaCorrente) != numerosContaCorrenteGerados_.end();
    } while (numeroDuplicado);

    numerosContaCorrenteGerados_.insert(numeroContaCorrente);

    return numeroContaCorrente;
}

bool Usuario::fazerLogin() {
    std::string usuario, senha;

    std::cout << "CPF: ";
    std::cin >> usuario;

    auto it = usuariosRegistrados_.find(usuario);

    if (it != usuariosRegistrados_.end()) {
        std::cout << "Senha: ";
        std::cin >> senha;

        if (senha == it->second.senha_) {
            std::cout << "\n========================================\n";
            std::cout << "   Bem-vind" << ((it->second.opcao_ == "feminino") ? "a" : "o") << ", " << it->second.nome_ << "!\n";
            std::cout << "   Sua conta corrente é CC: " << it->second.numeroContaCorrente_ << "\n";
            std::cout << "   Seu saldo atual é: R$ " << std::fixed << std::setprecision(2) << saldo.obterSaldo() << "\n";
            std::cout << "========================================\n";
            realizarOperacoesAposLogin();
            return true;
        } else {
            std::cout << "\n========================================";
            std::cout << "Senha incorreta.\n";
            std::cout << "========================================\n";
        }
    } else {
        std::cout << "\n\n========================================\n\n";
        std::cout << "Usuário não encontrado.\n";
        std::cout << "\n\n========================================\n\n";
    }}
    
    void Usuario::realizarOperacoesAposLogin() {
    int opcao;
    do {
        std::cout << "\nEscolha uma ação:\n";
        std::cout << "1. Fazer um novo depósito\n";
        std::cout << "2. Mostrar informações do usuário\n";
        std::cout << "3. Excluir conta do usuário\n";
        std::cout << "0. Fazer logout e voltar ao menu principal\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1: {
                double valorDeposito;
                std::cout << "Informe o valor que deseja depositar: R$ ";
                std::cin >> valorDeposito;

                if (valorDeposito > 0) {
                    saldo.adicionarSaldo(valorDeposito);
                    std::cout << "Depósito de R$ " << std::fixed << std::setprecision(2) << valorDeposito << " realizado com sucesso.\n";
                    std::cout << "Novo saldo: R$ " << std::fixed << std::setprecision(2) << saldo.obterSaldo() << "\n";
                } else {
                    std::cout << "Valor de depósito inválido.\n";
                }
                break;
            }
            case 2:
                mostrarInformacoesUsuario();
                break;
            case 3:
                if (excluirConta()) {
                   std::cout << "Conta excluída com sucesso. Fazendo logout...\n";
                   fazerLogout();
                   break;
            }
                break;
            case 0:
                std::cout << "Fazendo logout...\n";
                fazerLogout();
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 0);
}

        void Usuario::fazerLogout() {
    std::cout << "Fazendo logout...\n";
    SistemaBancario sistemaBancario;
    sistemaBancario.executarAplicativo();
}
      void Usuario::mostrarInformacoesUsuario() {
    std::string usuario;
    std::cout << "Informe o CPF do usuário para mostrar as informações: ";
    std::cin >> usuario;

    auto it = usuariosRegistrados_.find(usuario);

    if (it != usuariosRegistrados_.end()) {
        std::cout << "\nInformações do usuário:\n";
        std::cout << "Nome: " << it->second.nome_ << "\n";
        std::cout << "Endereço: " << it->second.endereco_ << "\n";
        std::cout << "CPF: " << it->second.cpf_ << "\n";
        std::cout << "Data de Nascimento: " << it->second.anoNascimento_ << "\n";
        std::cout << "Conta Corrente: " << it->second.numeroContaCorrente_ << "\n";
        std::cout << "Saldo Atual: R$ " << std::fixed << std::setprecision(2) << saldo.obterSaldo() << "\n";
        std::cout << "========================================\n";
    } else {
        std::cout << "\nUsuário não encontrado.\n";
        std::cout << "========================================\n";
    }
}
            bool Usuario::excluirConta() {
    std::string senha;

    std::cout << "ATENÇÃO: A exclusão da conta é uma ação irreversível.\n";
    std::cout << "Para confirmar, insira sua senha: ";
    std::cin >> senha;

    if (senha == usuariosRegistrados_[usuarioAtual_].senha_) {
        usuariosRegistrados_.erase(usuarioAtual_);
        std::cout << "Conta excluída com sucesso.\n";
        return true;
    } else {
        std::cout << "Senha incorreta. A exclusão da conta foi cancelada.\n";
        return false;
    }
}
