#include <iostream>
#include "SistemaBancario.hpp"
#include "Usuario.hpp"
#include "Desenvolvedor.hpp"
#include <locale>
#include <limits>
#include <sstream> 

SistemaBancario::SistemaBancario() : opcao(0) {}

void SistemaBancario::exibirMensagemBoasVindas() {
    std::cout << "\n========================================\n";
    std::cout << "        BEM VINDO AO BANCO UFMG        \n";
    std::cout << "========================================\n\n";
}

void SistemaBancario::executarAplicativo() {
    Usuario usuario;
    Desenvolvedor desenvolvedor;
    exibirMensagemBoasVindas();

    bool continuarExecucao = true;

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
            case 2:
                fazerLogin();
                continuarExecucao = false; // Não continuar o loop após o login bem-sucedido
                break;
            case 666:
                // Opção secreta desenvolvedor
                int escolhaDesenvolvedor;
                do {
                    std::cout << "\nEscolha uma opção:\n"
                              << "1. Listar usuários\n"
                              << "2. Possível teste futuro\n"
                              << "0. Voltar\n"
                              << "Opção: ";

                    std::cin >> escolhaDesenvolvedor;

                    switch (escolhaDesenvolvedor) {
                        case 1:
                            desenvolvedor.listarUsuarios(Usuario::getUsuarios());
                            break;
                        case 2:
                            // Possível teste futuro
                            break;
                        case 0:
                            break;
                        default:
                            std::cout << "Opção inválida. Tente novamente.\n";
                            break;
                    }
                } while (escolhaDesenvolvedor != 0); // Repetir enquanto a escolha não for "Voltar"
                break;
            case 0:
                std::cout << "Encerrando o programa. Adeus!\n";
                continuarExecucao = false; // Encerrar o loop
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (continuarExecucao);
}

void SistemaBancario::cadastrarNovoUsuario() {
    usuario.criarNovoUsuario();
}

void SistemaBancario::fazerLogin() {
    std::string cpf, senha;

    do {
        std::cout << "Digite o CPF: ";
        std::cin >> cpf;

        // Verificar se o CPF existe
        if (!Usuario::cpfExistente(cpf)) {
            // Se o CPF não existe, pedir para digitar novamente
            std::cout << "CPF não encontrado. Tente novamente.\n";
        }
    } while (!Usuario::cpfExistente(cpf));

    // Loop para solicitar senha até que seja correta
    do {
        std::cout << "Digite a senha: ";
        std::cin >> senha;

        // Verificar se a senha corresponde ao CPF fornecido
        const std::vector<DadosUsuario>& usuarios = Usuario::getUsuarios();
        for (const auto& usuario : usuarios) {
            if (usuario.cpf == cpf && usuario.senha == senha) {
                // Login bem-sucedido
                std::cout << "Login realizado com sucesso!\n";
                usuarioLogado = usuario; 
                realizarOperacoesAposLogin();
                return;
            }
        }

        // Se chegou aqui, a senha está incorreta
        std::cout << "Senha incorreta. Tente novamente.\n";
    } while (true);  // Loop até que a senha seja correta
}

const std::vector<DadosUsuario>& Usuario::getUsuarios() {
    return usuarios;
}

void SistemaBancario::realizarOperacoesAposLogin() {
    int opcao;
    do {
        std::cout << "\n========================================\n";
        std::cout << "Bem-vindx, " << usuarioLogado.nome << "!\n";
        std::cout << "CC: " << usuarioLogado.numeroContaCorrente << "\n";
        std::cout << "Saldo: R$ " << usuarioLogado.saldo.obterSaldo() << "\n";
        std::cout << "========================================\n";
        std::cout << "Escolha uma acao:\n";
        std::cout << "1. Fazer um novo depósito\n";
        std::cout << "2. Mostrar informacoes do usuário\n";
        std::cout << "3. Excluir conta do usuário\n";
        std::cout << "0. Fazer logout e voltar ao menu principal\n";
        std::cout << "Opção: ";
        std::cin >> opcao;

        switch (opcao) {
          case 1:
          {
              std::cout << "Informe o valor do depósito: R$ ";
              double valorDeposito;

              // Ler o valor do depósito considerando vírgula ou ponto decimal
              std::cin >> std::ws;  // Descartar espaços em branco
              valorDeposito = lerNumero();

              if (valorDeposito >= 0.0) {
                  usuarioLogado.saldo.adicionarSaldo(valorDeposito);
                  std::cout << "Depósito realizado com sucesso!\n";
              } else {
                  std::cout << "Valor de depósito inválido. O valor deve ser maior ou igual a zero.\n";
              }
              break;
          }
          case 2:
              std::cout << "\nInformacoes do Usuário:\n";
              std::cout << "Nome: " << usuarioLogado.getNome() << "\n";
              std::cout << "CPF: " << usuarioLogado.getCPF() << "\n";
              std::cout << "Data de Nascimento: " << usuarioLogado.getDataNascimento() << "\n";
              std::cout << "Endereço: " << usuarioLogado.getEndereco() << "\n";
              std::cout << "CC: " << usuarioLogado.getNumeroContaCorrente() << "\n";
              std::cout << "Saldo: R$ " << usuarioLogado.getSaldo().obterSaldo() << "\n"; // Ajuste para acessar o saldo do usuário logado
              std::cout << "========================================\n";
              break;
        }

    } while (opcao != 0);
}
double lerNumero() {
    std::string entrada;
    std::cin >> entrada;

    // Substituir vírgulas por pontos
    for (char& c : entrada) {
        if (c == ',') {
            c = '.';
        }
    }

    std::istringstream stream(entrada);
    double numero;
    stream >> numero;

    // Verificar se a leitura foi bem-sucedida
    if (stream.fail()) {
        std::cout << "Entrada inválida. Tente novamente.\n";
        // Limpar o estado de erro do stream e descartar a entrada inválida
        stream.clear();
        stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return lerNumero();  // Chamar recursivamente para obter uma entrada válida
    }

    return numero;
}
