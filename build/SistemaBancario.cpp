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
