#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <map>
#include <string>
#include <cctype>

class Usuario {
public:
    void insert(const std::string& usuario_,
                const std::string& nome_,
                const std::string& senha_);

    void remove(const std::string& usuario_);

    bool redefinirSenha(const std::string& usuario_);

// Novo método para criar um novo usuário
    void criarNovoUsuario();
    
private:
    bool senhaValida(const std::string& senha_) const;

private:
    struct DadosUsuario_ {
        std::string usuario_;
        std::string senha_;
        std::string nome_;
        std::string endereco_;
        std::string cpf_;
        int anoNascimento_;
        std::string numeroContaCorrente_; // Adicionando o número de conta corrente
     };

    std::map<std::string, DadosUsuario_> usuariosRegistrados_;
    std::set<std::string> numerosContaCorrenteGerados_; // Conjunto para armazenar números de conta corrente gerados

    // Função auxiliar para gerar número de conta corrente aleatório
    std::string gerarNumeroContaCorrente() const;
};

#endif // USUARIO_HPP
