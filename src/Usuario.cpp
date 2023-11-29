#include <ctime>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include "Usuario.hpp"
#include "Saldo.hpp"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;


void Usuario::criarNovoUsuario(const std::string& nomeArquivo) {
    DadosUsuario novoUsuario;
    
    system("clear||cls");

    std::cout << "\n=========================================================================\n";
    std::cout << "Obrigado por escolher o Banco UFMG, por favor, preencha os dados a seguir:\n";

    std::cout << "Nome completo: ";
    std::getline(std::cin >> std::ws, novoUsuario.nome);

    std::cout << "Data de Nascimento: ";
    std::getline(std::cin, novoUsuario.dataNascimento);

    std::cout << "Endereço Completo: ";
    std::getline(std::cin, novoUsuario.endereco);

    bool cpfValido = false;
    do {
        std::cout << "CPF (somente números, no formato XXXXXXXXXXX): ";
        std::cin >> novoUsuario.cpf;

        if (std::cin.fail() || novoUsuario.cpf.size() != 11 || novoUsuario.cpf.find_first_not_of("0123456789") != std::string::npos) {
            system("clear||cls");
            std::cout << "\n===============================================================\n";
            std::cout << "CPF inválido. Deve conter exatamente 11 números. Tente novamente.\n";
            // Limpar o buffer de entrada
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cpfValido = false;  // Defina cpfValido como falso para evitar a adição do usuário com CPF inválido
        } else if (usuarioExiste(novoUsuario.cpf)) {
            std::cout << "Usuário com o CPF '" << novoUsuario.cpf << "' já existe.\n";
            cpfValido = false;  // Defina cpfValido como falso para evitar a adição do usuário com CPF duplicado
        } else {
            cpfValido = true;
        }
    } while (!cpfValido);
    
    system("clear||cls");
    std::cout << "\nRequisitos para senha:\n"
              << "- Deve ter entre 8 e 30 caracteres.\n"
              << "- Deve conter pelo menos uma letra maiúscula.\n"
              << "- Deve conter pelo menos um caractere especial.\n"
              << "- Deve conter pelo menos um número.\n";
              
    do {
        std::cout << "\nSenha desejada: ";
        std::getline(std::cin >> std::ws, novoUsuario.senha); // Utiliza std::ws para descartar espaços em branco
    } while (!senhaValida(novoUsuario.senha));
    
    novoUsuario.numeroContaCorrente = gerarNumeroContaCorrente(); //Vincula a CC ao usuário

    // Adicionar o novo usuário ao vetor
    usuarios.push_back(novoUsuario);
    salvarUsuariosEmArquivo("Usuarios.txt");
    
    system("clear||cls");
    std::cout << "\n========================================\n";
    std::cout << "Novo usuário criado com sucesso!" << std::endl;
    std::cout << "\n========================================\n";
    std::cout << "Novo usuário criado com sucesso!\n";
    std::cout << "CPF: " << novoUsuario.cpf << "\n";
    std::cout << "Senha: " << novoUsuario.senha << "\n";
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
        system("clear||cls");
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

void Usuario::salvarUsuariosEmArquivo(const std::string& nomeArquivo) const {
    std::string nomeArquivoPadronizado = nomeArquivo;
    std::transform(nomeArquivoPadronizado.begin(), nomeArquivoPadronizado.end(), nomeArquivoPadronizado.begin(), ::tolower);

    std::ofstream arquivo(nomeArquivoPadronizado, std::ios::app);  // Abre o arquivo no modo de adição
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo para salvar.\n";
        return;
    }

    const DadosUsuario& ultimoUsuario = usuarios.back();
    arquivo << ultimoUsuario.nome << " " << ultimoUsuario.dataNascimento
            << " " << ultimoUsuario.endereco << " " << ultimoUsuario.cpf << "\n";
    // Adicione outras informações do usuário conforme necessário

    arquivo.close();  // Feche o arquivo imediatamente após a escrita
    std::cout << "Usuários salvos com sucesso no arquivo " << nomeArquivoPadronizado << ".\n";
}

void Usuario::carregarUsuariosDeArquivo(const std::string& nomeArquivo) {
    std::cout << "Iniciando carregamento de usuários do arquivo " << nomeArquivo << "...\n";
    std::cout << "Iniciando carregamento de usuários do arquivo " << nomeArquivo << "...\n";
    std::cout << "Carregando usuários do arquivo " << nomeArquivo << "...\n";

    std::set<std::string> cpfsCarregados;  // Usar um conjunto para garantir CPFs únicos

    // Verificar se o arquivo existe
    if (fs::exists(nomeArquivo)) {
        std::ifstream arquivo(nomeArquivo);
        if (arquivo.is_open()) {
            // Não limpar usuários existentes, apenas carregar novos
            DadosUsuario usuario;
            while (arquivo >> usuario.nome >> usuario.dataNascimento >> usuario.endereco >> usuario.cpf >> usuario.numeroContaCorrente >> usuario.senha) {
                std::cout << "Lendo dados do usuário: " << usuario.nome << " - CPF: " << usuario.cpf << "\n";
                // Verificar se o CPF já foi carregado
                if (cpfsCarregados.find(usuario.cpf) == cpfsCarregados.end()) {
                    // Este é um novo CPF, adiciona o usuário
                    usuarios.push_back(usuario);
                    cpfsCarregados.insert(usuario.cpf);
                    std::cout << "Usuário carregado: " << usuario.nome << " - CPF: " << usuario.cpf << "\n";
                } else {
                    // Já carregamos um usuário com esse CPF
                    std::cout << "Usuário com CPF duplicado encontrado e ignorado: " << usuario.nome << " - CPF: " << usuario.cpf << "\n";
                }
            }

            if (usuarios.empty()) {
                for (const auto& usuario : usuarios) {
    std::cout << "Usuário carregado: " << usuario.nome << " - CPF: " << usuario.cpf << "\n";
}
                std::cout << "Nenhum usuário foi carregado.\n";
            } else {
                std::cout << "Usuários carregados com sucesso do arquivo " << nomeArquivo << ".\n";
            }

            arquivo.close();
        } else {
            std::cout << "Erro ao abrir o arquivo " << nomeArquivo << " para leitura.\n";
        }
    } else {
        std::cout << "O arquivo " << nomeArquivo << " não existe. Criando um novo arquivo.\n";

        // Criar um novo arquivo vazio
        std::ofstream novoArquivo(nomeArquivo);
        if (novoArquivo.is_open()) {
            std::cout << "Novo arquivo " << nomeArquivo << " criado com sucesso.\n";
            novoArquivo.close();
        } else {
            std::cout << "Erro ao criar o novo arquivo " << nomeArquivo << ".\n";
        }
    }
}

bool Usuario::usuarioExiste(const std::string& cpf) const {
    for (const auto& usuario : usuarios) {
        if (usuario.cpf == cpf) {
            return true; // Usuário encontrado
        }
    }
    return false; // Usuário não encontrado
}

bool Usuario::fazerLogin(const std::string& cpf, const std::string& senha) const {
    auto it = std::find_if(usuarios.begin(), usuarios.end(), [cpf](const DadosUsuario& usuario) {
        return usuario.cpf == cpf;
    });

    system("clear||cls");

    if (it != usuarios.end()) {
        // Usuário encontrado, verifique a senha
        if (senha == it->senha) {
            std::cout << "\n========================================\n";
            std::cout << "   Bem-vindx" << it->nome << "!\n";
            std::cout << "   Sua conta corrente é CC: " << it->numeroContaCorrente << "\n";
            std::cout << "   Seu saldo atual é: R$ " << std::fixed << std::setprecision(2) << saldo.obterSaldo() << "\n";
            std::cout << "========================================\n";
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
    }

    return false;
}
