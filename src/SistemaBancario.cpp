// SistemaBancario.cpp

#include "SistemaBancario.hpp"
#include <iostream>

void SistemaBancario::realizarLogin() {
    std::string usuario, senha;

    std::cout << "===== LOGIN =====" << std::endl;
    std::cout << "Usuário: ";
    std::cin >> usuario;

    std::cout << "Senha: ";
    std::cin >> senha;

    // Verificar se o usuário existe e a senha está correta
    if (Usuario::loginValido(usuario, senha)) {
        usuarioAtual = Usuario::getUsuario(usuario);
        std::cout << "Login bem-sucedido. Bem-vindo, " << usuarioAtual.obterNome() << "!" << std::endl;
        exibirMenuUsuarioLogado();
    } else {
        std::cout << "Login falhou. Usuário ou senha incorretos." << std::endl;
    }
}

void SistemaBancario::realizarCadastroUsuario() {
    Usuario novoUsuario;
    novoUsuario.criarNovoUsuario();
}

void SistemaBancario::exibirMenuUsuarioLogado() {
    int opcao;

    do {
        std::cout << "\n===== MENU DO USUÁRIO =====" << std::endl;
        std::cout << "1. Fazer Depósito" << std::endl;
        std::cout << "2. Mostrar Dados" << std::endl;
        std::cout << "3. Realizar Transferência" << std::endl; // A ser implementado
        std::cout << "4. Solicitar Empréstimo" << std::endl;    // A ser implementado
        std::cout << "5. Extrato Bancário" << std::endl; // A ser implementado
        std::cout << "6. Fazer Logout" << std::endl;
        std::cout << "7. Excluir Conta" << std::endl;       
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha a opção desejada: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                fazerDeposito();
                break;
            case 2:
                mostrarDados();
                break;
            case 3:
                realizarTransferencia(); // A ser implementado
                break;
            case 4:
                solicitarEmprestimo();   // A ser implementado
                break;
           case 5:
                solicitarextrato();   // A ser implementado
                break;
            case 6:
                realizarLogout();
                return;
            case 7:
                excluirConta();
                return;
            case 0:
                std::cout << "Saindo do sistema. Até mais!" << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
        }
    } while (opcao != 0);
}

void SistemaBancario::fazerDeposito() {
    double valor;
    std::cout << "Digite o valor a ser depositado: R$ ";
    std::cin >> valor;

    usuarioAtual.adicionarSaldo(valor);

    std::cout << "Depósito de R$ " << valor << " realizado com sucesso." << std::endl;
}

void SistemaBancario::mostrarDados() {
    std::cout << "\n===== DADOS DO USUÁRIO =====" << std::endl;
    std::cout << "\nNome: " << usuarioAtual.nome_ << std::endl;
    std::cout << "\nEndereço: " << usuarioAtual.endereco_ << std::endl;
    std::cout << "\nCPF: " << usuarioAtual.cpf_ << std::endl;
    std::cout << "\nAno de Nascimento: " << usuarioAtual.anoNascimento_ << std::endl;
    std::cout << "\nNúmero da Conta Corrente: " << usuarioAtual.numeroContaCorrente_ << std::endl;
}

void SistemaBancario::excluirConta() {
    std::cout << "Você está prestes a excluir sua conta. Esta ação é irreversível." << std::endl;
    std::cout << "Para confirmar, digite 'CONFIRMAR': ";

    std::string confirmacao;
    std::cin >> confirmacao;

    if (confirmacao == "CONFIRMAR") {
        Usuario::remove(usuarioAtual.obterUsuario());
        std::cout << "Conta excluída com sucesso. Até mais!" << std::endl;
        realizarLogin();
    } else {
        std::cout << "Exclusão de conta cancelada." << std::endl;
        exibirMenuUsuarioLogado();  
    }
}

void SistemaBancario::realizarLogout() {
    std::cout << "Fazendo Logout..." << std::endl;
    realizarLogin();
}

