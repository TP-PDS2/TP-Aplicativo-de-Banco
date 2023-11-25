# 2023-2 
# TP-Aplicativo-de-Banco

Este é o repositório do nosso grupo para o projeto do professor Thiago Ferreira, na disciplina "Programação e Desenvolvimento de Software 2" (PDS2) ofertada pela Universidade Federal de Minas Gerais (UFMG), no segundo período letivo de 2023

# Membros do Projeto

Ana Beatriz (anabeatriz-0702) <br />
Arthur Nolasco (arthurzinnolasco) <br />
Isaac Henrique (isaac02901) <br />

# Visão Geral
Visão Geral do Código do Aplicativo de Banco:

O código apresentado neste repositório é um programa baseado em um sistema bancário desenvolvido em C++. Ele permite que os usuários realizem várias operações relacionadas a um aplicativo bancário, como abrir uma conta nova, realizar login, depositar e transferir dinheiro, pedir empréstimos ao banco e olhar o saldo disponível em sua conta corrente.
 
O programa possui diversas funcionalidades, incluindo:

1. Transferência Entre Contas:
Descrição:
Permite aos clientes transferir dinheiro para outras contas bancárias, tanto internamente quanto externamente, para pagar contas e fazer transferências entre amigos.

2. Receber Notificação em Tempo Real:
Descrição:
Mantém os clientes informados em tempo real sobre atividades importantes da conta, como depósitos, saques e transferências.

3. Extrato Bancário Detalhado:
Descrição:
Fornece aos clientes um extrato detalhado das transações da conta para um melhor entendimento dos gastos financeiros.

4. Solicitar Empréstimos e Financiamentos:
Descrição:
Permite que os clientes solicitem empréstimos ou financiamentos diretamente pelo aplicativo, tornando o processo mais conveniente e transparente.

5. Cadastro e Gerenciamento de Clientes:
Descrição:
Os usuários podem cadastrar novos clientes, editar informações pessoais e remover contas de clientes existentes.

# Comandos do sistema
COMANDOS GERAIS:

*'cadastrar cliente'

*'mostrar meus dados'

*'editar meus dados'

*'apagar minha conta'

*'efetuar logout'


<br />
PERMISSÃO 0 (NINGUÉM LOGADO):
<br />

*'logar cliente'

*'cadastrar conta'

*'recuperar conta'


<br />
PERMISSÃO 1 (CLIENTE):
<br />

*'mostrar extrato'

*'mostrar dados da conta corrente'

*'realizar transferência'

*'solicitar empréstimo'

*'fazer logout'

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
- Quero conseguir fazer login com sucesso se segurança no aplicativo.
- Ao iniciar uma transferência, o aplicativo deve exigir detalhes precisos, como o valor, a conta de destino e informações de segurança.
- A transferência deve ser processada com segurança, e eu devo receber uma confirmação imediata da transação.
- Os dados de login e as informações de transferência devem ser protegidos. 


_Receber Notificação:_

*Descrição:* 

Como um cliente, eu quero receber notificações em tempo real sobre atividades importantes da minha conta, como depósitos, saques e transferências.

*Critérios de aceitação:* 
- Quero conseguir fazer login com sucesso se segurança no aplicativo.
- O aplicativo deve me enviar notificações para atividades importantes, como depósitos, saques e transferências. 
- Devo poder gerenciar as configurações de notificação, incluindo a ativação e desativação das notificações, de forma segura.


_Extrato bancário detalhado:_

*Descrição:* 

Como um cliente, eu quero poder acessar um extrato detalhado das transações da minha conta, para entender melhor como estou gastando meu dinheiro.

*Critérios de aceitação:*
- Quero conseguir fazer login com sucesso se segurança no aplicativo.
- O extrato bancário detalhado deve exibir informações precisas, incluindo data, tipo de transação e valor.
- Quero ser capaz de exportar o extrato em formato digital de maneira segura para referência futura.
- Tanto os dados de login quanto as informações do extrato devem ser protegidos.


_Solicitar Empréstimos:_

*Descrição:*

Como um cliente, eu quero poder solicitar empréstimos ou financiamentos diretamente pelo aplicativo, tornando o processo mais conveniente e transparente.

*Critérios de aceitação:*
- Quero conseguir fazer login com sucesso se segurança no aplicativo.
- O processo de solicitação de empréstimo deve ser transparente, fornecendo informações claras sobre taxas, prazos e condições.
- Os dados pessoais e financeiros inseridos durante a solicitação de empréstimo devem ser protegidos de maneira segura.
- Devo receber uma confirmação da solicitação de empréstimo e ser informado sobre o status do processo de aprovação com segurança e confiabilidade.



# Descrição da funcionalidade das classes



