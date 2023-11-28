#include <iostream>
#include "SistemaBancario.hpp"
#include "Usuario.hpp"

void exibirMensagemBoasVindas() {
    std::cout << "\n========================================\n";
    std::cout << "        BEM VINDO AO BANCO UFMG        \n";
    std::cout << "========================================\n\n";
}

void SistemaBancario::executarAplicativo() {
    Usuario usuario;
    int opcao;

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
                usuario.criarNovoUsuario();
                break;
            case 2:
                usuario.fazerLogin();
                return;
            case 0:
                std::cout << "Encerrando o programa...\n";
                break;
            default:
                std::cout << "Opcao inválida. Tente novamente.\n";
        }
    } while (opcao != 0);
}

