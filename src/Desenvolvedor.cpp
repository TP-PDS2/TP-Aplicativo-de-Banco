#include "Desenvolvedor.hpp"
#include <iostream>

void Desenvolvedor::listarUsuarios(const std::vector<DadosUsuario>& usuarios) {
    std::cout << "Lista de Usuários:\n";
    for (const auto& usuario : usuarios) {
        std::cout << "Nome: " << usuario.nome << "\tCPF: " << usuario.cpf << "\tSenha: " << usuario.senha
                  << "\tSaldo: R$ " << usuario.saldo.getSaldo() << "\n";
    }
}