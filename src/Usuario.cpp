#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Usuario.hpp"

#include "Usuario.hpp"

Usuario::Usuario() : tentativasSenha_(0) {
    srand(time(nullptr));
}
void Usuario::insert(const std::string& usuario_, const std::string& senha_, const std::string& opcao_) {
    if (senhaValida(senha_)) {
        auto it = usuariosRegistrados_.find(usuario_);
        if (it == usuariosRegistrados_.end()) {
            DadosUsuario_ usuarioTemp;
            usuarioTemp.usuario_ = usuario_;
            usuarioTemp.senha_ = senha_;
            usuarioTemp.opcao_ = opcao_;
            usuariosRegistrados_[usuario_] = usuarioTemp;
            std::cout << "Usuário registrado com sucesso!" << std::endl;
        }
    } else {
        tentativasSenha_++;
        if (tentativasSenha_ >= 2) {
            std::cout << "Você errou a senha duas vezes. Deseja mudar a senha? (0 para não, 1 para sim): ";
            int opcao;
            std::cin >> opcao;

            if (opcao == 1) {
                std::string novaSenha;
                std::cout << "Digite a nova senha: ";
                std::cin.ignore();
                std::getline(std::cin, novaSenha);

                if (senhaValida(novaSenha)) {
                    usuariosRegistrados_[usuario_].senha_ = novaSenha;
                    std::cout << "Senha alterada com sucesso!" << std::endl;
                } else {
                    std::cout << "Nova senha inválida. A senha não foi alterada." << std::endl;
                }
            }
        }
    }
}
void Usuario::remove(const std::string& usuario_) {
    auto it = usuariosRegistrados_.find(usuario_);
    if (it != usuariosRegistrados_.end()) {
        usuariosRegistrados_.erase(it);
        std::cout << "Usuário removido com sucesso!" << std::endl;
    } else {
        std::cout << "Usuário não encontrado. Nenhum usuário foi removido." << std::endl;
    }
}

bool Usuario::redefinirSenha(const std::string& usuario_) {
    try {
        auto& dadosUsuario = usuariosRegistrados_.at(usuario_);

        std::string novaSenha;
        std::cout << "Digite a nova senha: ";
        std::cin.ignore();
        std::getline(std::cin, novaSenha);

        if (senhaValida(novaSenha)) {
            dadosUsuario.senha_ = novaSenha;
            std::cout << "Senha redefinida com sucesso!" << std::endl;
            return true;
        } else {
            std::cout << "Nova senha inválida. A senha não foi alterada." << std::endl;
            return false;
        }
    } catch (const std::out_of_range& e) {
        std::cout << "Usuário não encontrado. Não foi possível redefinir a senha." << std::endl;
        return false;
    }
}
void Usuario::criarNovoUsuario() {
    DadosUsuario novoUsuario;
    
    std::cout << "Nome completo: ";
    std::getline(std::cin, novoUsuario.nome_);

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

    std::cout << "Novo usuário criado com sucesso!" << std::endl;
}
std::string Usuario::obterEndereco(const std::string& usuario_) const {
    try {
        auto it = usuariosRegistrados_.at(usuario_);
        return it.endereco_;
    } catch (const std::out_of_range& e) {
        return "Usuário não encontrado";
    }
}

std::string Usuario::gerarNumeroContaCorrente() const {
    srand(time(nullptr));

    std::string numeroContaCorrente;
    bool numeroDuplicado;

    do {
        int numeroAleatorio = rand() % 9000 + 1000;
        numeroContaCorrente = "CC" + std::to_string(numeroAleatorio);

        numeroDuplicado = numerosContaCorrenteGerados_.find(numeroContaCorrente) != numerosContaCorrenteGerados_.end();
    } while (numeroDuplicado);

    numerosContaCorrenteGerados_.insert(numeroContaCorrente);

    return numeroContaCorrente;
}
bool Usuario::senhaValida(const std::string& senha_) const {
    if (senha_.length() < 8 || senha_.length() > 30) {
        std::cout << "A senha deve ter entre 8 e 30 caracteres." << std::endl;
        return false;
    }

    bool temMaiuscula = false;
    for (char c : senha_) {
        if (std::isupper(c)) {
            temMaiuscula = true;
            break;
        }
    }

    if (!temMaiuscula) {
        std::cout << "A senha deve conter pelo menos uma letra maiúscula." << std::endl;
        return false;
    }

    bool temCaracterEspecial = false;
    for (char c : senha_) {
        if (!std::isalnum(c)) {
            temCaracterEspecial = true;
            break;
        }
    }

    if (!temCaracterEspecial) {
        std::cout << "A senha deve conter pelo menos um caractere especial." << std::endl;
        return false;
    }

    bool temNumero = false;
    for (char c : senha_) {
        if (std::isdigit(c)) {
            temNumero = true;
            break;
        }
    }

    if (!temNumero) {
        std::cout << "A senha deve conter pelo menos um número." << std::endl;
        return false;
    }

    return true;
}

void Usuario::adicionarSaldo(double valor) {
    dadosUsuario_.saldo_.adicionarSaldo(valor);
}

double Usuario::obterSaldo() const {
    return dadosUsuario_.saldo_.obterSaldo();
}

