#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include "Usuario.hpp"
#include "Saldo.hpp"
#include <iostream>
#include <regex> 

std::vector<DadosUsuario> Usuario::usuarios;

void Usuario::criarNovoUsuario()
{
    DadosUsuario novoUsuario;

    std::cout << "\n=========================================================================\n";
    std::cout << "Obrigado por escolher o Banco UFMG, por favor, preencha os dados a seguir:\n";

    std::cout << "Nome completo: ";
    std::getline(std::cin >> std::ws, novoUsuario.nome);

    do {
        std::cout << "Data de Nascimento (DD/MM/AAAA): ";
        std::getline(std::cin, novoUsuario.dataNascimento);
    } while (!validarDataNascimento(novoUsuario.dataNascimento));

    std::cout << "Endereço Completo: ";
    std::getline(std::cin, novoUsuario.endereco);

    bool cpfValido = false;
    do
    {
        std::cout << "CPF (somente números, no formato XXXXXXXXXXX): ";
        std::cin >> novoUsuario.cpf;

        if (std::cin.fail() || novoUsuario.cpf.size() != 11 || novoUsuario.cpf.find_first_not_of("0123456789") != std::string::npos)
        {
            std::cout << "\n===============================================================\n";
            std::cout << "CPF inválido. Deve conter exatamente 11 números. Tente novamente.\n";
            // Limpar o buffer de entrada
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cpfValido = false; // Defina cpfValido como falso para evitar a adição do usuário com CPF inválido
        }
        else if (cpfExistente(novoUsuario.cpf))
        {
            std::cout << "Usuário com o CPF '" << novoUsuario.cpf << "' já existe.\n";
            cpfValido = false; // Defina cpfValido como falso para evitar a adição do usuário com CPF duplicado
        }
        else
        {
            cpfValido = true;
        }
    } while (!cpfValido);

    std::cout << "\nRequisitos para senha:\n"
              << "- Deve ter entre 8 e 30 caracteres.\n"
              << "- Deve conter pelo menos uma letra maiúscula.\n"
              << "- Deve conter pelo menos um caractere especial.\n"
              << "- Deve conter pelo menos um número.\n";

    do
    {
        std::cout << "\nSenha desejada: ";
        std::getline(std::cin >> std::ws, novoUsuario.senha); // Utiliza std::ws para descartar espaços em branco
    } while (!senhaValida(novoUsuario.senha));

    novoUsuario.numeroContaCorrente = gerarNumeroContaCorrente(); // Vincula a CC ao usuário

    // Adicionar o novo usuário ao vetor
    usuarios.push_back(novoUsuario);

    std::cout << "\n========================================\n";
    std::cout << "Novo usuário criado com sucesso!" << std::endl;
    std::cout << "\n========================================\n";
    std::cout << "Novo usuário criado com sucesso!\n";
}

void Usuario::deletarConta() {
    std::string numeroConta;
    std::string nomeUsuario;
    std::string senhaUsuario;

    std::cout << "Para deletar sua conta, por favor, insira os seguintes dados:\n";
    
    std::cout << "Número da conta: ";
    std::cin >> numeroConta;

    std::cout << "Nome do usuário: ";
    std::cin.ignore(); // Limpa o buffer do teclado
    std::getline(std::cin, nomeUsuario);

    std::cout << "Senha: ";
    std::getline(std::cin, senhaUsuario);

    // Encontrar o usuário com o número da conta fornecido
    auto it = std::find_if(usuarios.begin(), usuarios.end(), [&](const DadosUsuario& usuario) {
        return usuario.numeroContaCorrente == numeroConta &&
               usuario.nome == nomeUsuario &&
               usuario.senha == senhaUsuario;
    });

    if (it != usuarios.end()) {
        // Confirmação do usuário para deletar a conta
        char opcao;
        std::cout << "Tem certeza que deseja deletar sua conta? (S/N): ";
        std::cin >> opcao;

        if (std::toupper(opcao) == 'S') {
            usuarios.erase(it);
            std::cout << "Conta deletada com sucesso.\n";
        } else {
            std::cout << "Operação de exclusão cancelada.\n";
        }
    } else {
        std::cout << "Dados incorretos ou conta não encontrada.\n";
    }
}

bool Usuario::senhaValida(const std::string &senha_) const
{
    if (senha_.length() < 8 || senha_.length() > 30)
    {
        std::cout << "A senha deve ter entre 8 e 30 caracteres." << std::endl;
        return false;
    }

    bool temMaiuscula = false;
    bool temCaracterEspecial = false;
    bool temNumero = false;

    for (char c : senha_)
    {
        if (std::isupper(c))
        {
            temMaiuscula = true;
        }
        else if (std::isdigit(c))
        {
            temNumero = true;
        }
        else if (!std::isalnum(c))
        {
            temCaracterEspecial = true;
        }
    }

    if (!temMaiuscula || !temNumero || !temCaracterEspecial)
    {
        std::cout << "A senha deve atender aos requisitos de maiúsculas, números e caracteres especiais." << std::endl;
        return false;
    }

    return true;
}

std::string Usuario::gerarNumeroContaCorrente()
{
    srand(time(nullptr));

    std::string numeroContaCorrente;
    bool numeroDuplicado;

    do
    {
        int numeroAleatorio = rand() % 900000 + 100000; // Gera 6 números aleatórios
        numeroContaCorrente = std::to_string(numeroAleatorio);

        numeroDuplicado = numerosContaCorrenteGerados_.find(numeroContaCorrente) != numerosContaCorrenteGerados_.end();
    } while (numeroDuplicado);

    numerosContaCorrenteGerados_.insert(numeroContaCorrente);

    return numeroContaCorrente;
}

bool Usuario::cpfExistente(const std::string &cpf)
{
    for (const auto &usuario : usuarios)
    {
        if (usuario.cpf == cpf)
        {
            return true; // Usuário com o CPF já existe
        }
    }
    return false; // Usuário com o CPF não existe
}

void Usuario::adicionarUsuarioAdministrador()
{
    DadosUsuario adminUsuario;

    // Definindo as informações do usuário administrador
    adminUsuario.nome = "Administrador";
    adminUsuario.cpf = "12345678910";
    adminUsuario.senha = "#Senha123";

    // Adicionando o usuário administrador ao vetor de usuários
    usuarios.push_back(adminUsuario);

    std::cout << "Usuário Administrador criado com sucesso!\n";
}
bool Usuario::validarDataNascimento(const std::string& data) const {
    const std::regex formatoData("^\\d{2}/\\d{2}/\\d{4}$");

    if (!std::regex_match(data, formatoData)) {
        std::cout << "Data de nascimento inválida. Use o formato DD/MM/AAAA.\n";
        return false;
    }

    // Extrair dia, mês e ano
    int dia, mes, ano;
    sscanf(data.c_str(), "%2d/%2d/%4d", &dia, &mes, &ano);

    // Verificar se o mês está entre 1 e 12
    if (mes < 1 || mes > 12) {
        std::cout << "Mês inválido. Deve estar entre 1 e 12.\n";
        return false;
    }

    // Verificar dias em meses específicos
    if ((dia < 1) || 
        (dia > 31 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) ||
        (dia > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) ||
        (dia > 29 && mes == 2 && (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))) ||
        (dia > 28 && mes == 2 && !(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)))) 
    {
        std::cout << "Dia inválido para o mês especificado.\n";
        return false;
    }

    return true;
}
