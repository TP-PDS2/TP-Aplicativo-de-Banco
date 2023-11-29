#include <iostream>
#include "SistemaBancario.hpp"
#include "Usuario.hpp"

SistemaBancario::SistemaBancario() : opcao(0) {}

void SistemaBancario::exibirMensagemBoasVindas() {
    std::cout << "\n========================================\n";
    std::cout << "        BEM VINDO AO BANCO UFMG        \n";
    std::cout << "========================================\n\n";
}

void SistemaBancario::executarAplicativo() {
    Usuario usuario;
    exibirMensagemBoasVindas();

    do {
        std::cout << "\n\n========================================\n\n";
        std::cout << "Escolha uma opção:\n"
                  << "1. Cadastrar novo usuário\n"
                  << "2. Fazer login\n"
                  << "0. Encerrar o programa\n"
                  << "Opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarNovoUsuario();
                break;
            case 2: {
                
                std::cout << "Opção 2: Fazer login\n";

                std::string cpf, senha;
                std::cout << "CPF: ";
                std::cin >> cpf;
                std::cout << "Senha: ";
                std::cin >> senha;

                // Criar uma instância de Usuario
                Usuario usuario;

                // Verificar se o login é válido
                if (usuario.fazerLogin(cpf, senha)) {
                    std::cout << "Login bem-sucedido!\n";
                    // Adicione aqui as ações que deseja realizar após o login bem-sucedido
                } else {
                    std::cout << "Login falhou. CPF ou senha incorretos.\n";
                }
                break;
            }
            case 0:
                std::cout << "Encerrando o programa. Adeus!\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 0);
}
void SistemaBancario::realizarOperacoesAposLogin() {
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
            case 1:
                std::cout << "Funcionalidade ainda vai ser implementada.\n";
                // Implementação para fazer um novo depósito
                break;
            case 2:
                std::cout << "Funcionalidade ainda vai ser implementada.\n";
                // Implementação para mostrar informações do usuário
                break;
            case 3:
                std::cout << "Funcionalidade ainda vai ser implementada.\n";
                // Implementação para excluir conta do usuário
                break;
            case 0:
                std::cout << "Fazendo logout e voltando ao menu principal.\n";
                // Implementação para fazer logout
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }

    } while (opcao != 0);
}

void SistemaBancario::cadastrarNovoUsuario() {
    Usuario usuario;
    usuario.criarNovoUsuario();
}
