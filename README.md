# 2023-2 
# TP-Aplicativo-de-Banco

Este é o repositório do nosso grupo para o projeto do professor Thiago Ferreira, na disciplina "Programação e Desenvolvimento de Software 2" (PDS2) ofertada pela Universidade Federal de Minas Gerais (UFMG), no segundo período letivo de 2023

# Membros do Projeto

Ana Beatriz (anabeatriz-0702) <br />
Arthur Nolasco (arthurzinnolasco) <br />
Isaac Henrique (isaac02901) <br />

# Visão Geral
Visão Geral do Código do Aplicativo de Banco:

O código apresentado neste repositório é um programa baseado em um Sistema Bancário desenvolvido em C++. Ele permite que os usuários realizem operações relacionadas a um Aplicativo Bancário, como abrir uma conta nova, realizar login, depositar e transferir dinheiro, pedir empréstimos ao banco e olhar o saldo disponível em sua conta corrente.
 
O programa possui as seguintes funcionalidades:

1. Realizar cadastro e abrir uma conta:
Para abrir uma conta, o cliente precisa entrar com seu nome completo, data de nascimento, endereço e CPF. Cada CPF é vinculado a uma conta, de forma que não possa haver mais uma conta para um mesmo número de CPF. O usuário também deverá criar uma senha de 8 a 30 dígitos com pelo menos uma letra, um número e um caractere especial. Ao final desse processo, é gerado um número único da Conta Corrente daquele usuário.

2. Realizar operações bancárias e atualizar informações:
Permite que o usuário realize transferências para outras contas e depósitos bancários em sua própria conta. Voltar ao menu principal, excluir a conta e editar informações pessoais também fazem parte do menu Operações disponibilizado.

3. Receber o extrato bancário detalhado:
Fornece aos clientes um extrato detalhado das transações da conta para um melhor entendimento dos gastos financeiros, tanto na própria página do banco quanto em arquivo .TXT. 

4. Solicitar Empréstimos e Financiamentos:
Permite que os clientes solicitem empréstimos ou financiamentos diretamente pelo aplicativo, tornando o processo mais conveniente e transparente.

Será assegurado a individualidade e segurança de cada conta na realização do login, fazendo a conferância se a senha digitada está correta para o CPF que está tentando realizar o login. Um menu simples com as operações possíveis será mostrado para o usuário, nele contendo o número da CC e seu saldo em conta. Em cada transação bancária ou depósito o usuário deverá digitar a sua senha de login corretamente, como forma de confirmar sua identidade na ação. 

Pensando também em usuário com alguma deficiência cognitiva ou que tenham dificuldades com tecnologias novas, como idosos, foram colocadas saídas de tela o mais claras e obejtivas possível a respeito das operações realizadas ou passos a serem seguidos.

Utilizando os principios da Programação Defensiva, foram feitas estruturas de conferência quando ao número de digitos do CPF, o formato da data de nascimento inserida e se a senha escolhida atende aos requisitos para ser validada. Essas estruturas serão explicadas no tópico "Descrição da Funcionalidade das Classes". 

O trabalho foi criado pensando em cumprir com os Critérios de Aceitação das User Stories abaixo: 

# User Stories: 

_Verficar Saldo Bancário:_

*Descrição:* 

Como um cliente, eu quero poder verificar o saldo da minha conta corrente através do aplicativo do banco para acompanhar meu dinheiro.

*Critérios de aceitação:* 
- Quero conseguir fazer login com sucesso se segurança no aplicativo.
- Ver o saldo da conta de maneira clara e precisa.
- O saldo deve ser atualizado sempre, refletindo minhas transações recentes.
- Meus dados de login, incluindo usuário e senha, devem ser protegidos.


_Transferência entre Contas:_

*Descrição:*

Como um cliente, eu quero poder transferir dinheiro para outras contas bancárias, tanto interna quanto externamente, para pagar contas e fazer transferências entre amigos.

*Critérios de aceitação:*
- Quero conseguir fazer login com sucesso e segurança no aplicativo.
- Ao iniciar uma transferência, o aplicativo deve exigir detalhes precisos, como o valor, a conta de destino e informações de segurança.
- A transferência deve ser processada com segurança, e eu devo receber uma confirmação imediata da transação.
- Os dados de login e as informações de transferência devem ser protegidos. 


_Receber Notificação:_

*Descrição:* 

Como um cliente, eu quero receber notificações em tempo real sobre atividades importantes da minha conta, como depósitos, saques e transferências.

*Critérios de aceitação:* 
- Quero conseguir fazer login com sucesso e segurança no aplicativo.
- O aplicativo deve me enviar notificações para atividades importantes, como depósitos, saques e transferências. 
- Devo poder gerenciar as configurações de notificação, incluindo a ativação e desativação das notificações, de forma segura.


_Extrato bancário detalhado:_

*Descrição:* 

Como um cliente, eu quero poder acessar um extrato detalhado das transações da minha conta, para entender melhor como estou gastando meu dinheiro.

*Critérios de aceitação:*
- Quero conseguir fazer login com sucesso e segurança no aplicativo.
- O extrato bancário detalhado deve exibir informações precisas, incluindo data, tipo de transação e valor.
- Quero ser capaz de exportar o extrato em formato digital de maneira segura para referência futura.
- Tanto os dados de login quanto as informações do extrato devem ser protegidos.


_Solicitar Empréstimos:_

*Descrição:*

Como um cliente, eu quero poder solicitar empréstimos ou financiamentos diretamente pelo aplicativo, tornando o processo mais conveniente e transparente.

*Critérios de aceitação:*
- Quero conseguir fazer login com sucesso e segurança no aplicativo.
- O processo de solicitação de empréstimo deve ser transparente, fornecendo informações claras sobre taxas, prazos e condições.
- Devo receber uma confirmação da solicitação de empréstimo e ser informado sobre o status do processo de aprovação com segurança e confiabilidade.


# Descrição da funcionalidade das classes

*SistemaBancario:*
-
Responsabilidade Principal: Gerenciar o sistema bancário, fornecendo uma interface para interação com o usuário.

_Métodos Principais:_

 - executarAplicativo(): Inicia a execução do aplicativo, permitindo que o usuário escolha entre cada funcionalidade.
 - cadastrarNovoUsuario(): Chama o método de criação de novo usuário da classe Usuario e atualiza o mapa de saldos.
 - fazerLogin(): Realiza o processo de login, solicitando CPF e senha e verificando a correspondência.
 - realizarOperacoesAposLogin(): Oferece opções de operações após o login, como depósito, visualização de informações do usuário, etc.

*Usuario:*
-
Responsabilidade Principal: Gerenciar informações e operações relacionadas aos usuários.

_Métodos Principais:_

- criarNovoUsuario(): Coleta informações para criar um novo usuário.
- cpfExistente(const std::string& cpf): Verifica se um CPF já existe na lista de usuários.
- adicionarUsuarioAdministrador(): Adiciona um usuário administrador ao sistema.

*Saldo:*
-

*Transferencia:*
-

*Extrato:*
-

*Emprestimo:*
-



