---
layout: post
title:  "Venda de Serviços"
category: 'Trabalho Final'
description: 'Pessoas podem oferecer e contratar serviços'
image: 'agoravai.png'
---

- Usuários podem ser cadastrados no sistema e devem possuir Nome, Senha e um Saldo Inicial.
    - O nome do usuário deve ser único no sistema. 
```
CadastrarUsuario bia 123 1
 Usuário Cadastrado!
CadastrarUsuario ana 345 500
  Usuário Cadastrado!
CadastrarUsuario leo 542 10
  Usuário Cadastrado!
```
- Usuários podem cadastrar serviços, os quais têm um tipo (nome do serviço), uma descrição e um preço.
    - O nome do serviço deve ser único no sistema.
```
CadastrarServico professora ingles 10
  Servico Cadastrado!
CadastrarServico cantora pop 50
  Servico Cadastrado!
CadastrarServico piloto sou muito rapido 50
  Servico Cadastrado!
```
- Usuários podem alterar o preço dos serviços.
```
AlterarPrecoServico cantora 100
  Preco Alterado!
```
- Usuários podem apagar sua própria conta.
```
Login bia 123
  Login Realizado
DeletarConta
  Usuario Removido
```
- Usuários podem passar a fornecer um serviço, adicicionando-o à sua lista de serviços
    -   O serviço deve estar cadastrado no sistema. 
```
AdicionarServico professora
  Servico Adicionado
AdicionarServico piloto
  Servico Adicionado
```
-   Usuários podem deixar de oferecer um serviço, removendo-o.
```
RemoverMeuServico professora
  Servico Removido
```
-   Usuários podem ver todos os serviços cadastrados no sistema e todos os usuários que os oferecem.
```
MostrarTodosServicos
Tipo: cantora
Preco: 100
Descricao: pop
[ ana  ]

Tipo: professora
Preco: 10
Descricao: ingles
[  ]
```
- Usuários podem ver todos os usuários que fornecem algum serviço.
```
MostrarUsuariosComServico
 Nome: ana
 Nome: leo
```
- Usuários podem procurar um serviço por nome.
```
ProcurarServicoNome magico
  servico magico nao existe
```
- Usuários podem ver seu perfil e o de outros usuários. 
    -   Um usuário não pode ver o saldo de outro usuário. 
```
VerPerfil leo
   Saldo: R$110,00
   Nome: leo
   
VerPerfil ana
   Nome: ana
```
- Usuários podem ver todos os seus serviços.
```
VerMeusServicos
  Tipo: professora
  Preco: 10
  Descricao: ingles
  [ ana  ]
  
  Tipo: cantora
  Preco: 100
  Descricao: pop
  [ ana  ]
```
- Usuários podem contratar o serviço de outro usuário.
    - O usuário deve pagar pelo serviço contratado, portanto, deve ter saldo suficiente.
```
ContratarServico cantora ana
  Servico Realizado
```
-   Usuários podem depositar dinheiro em suas próprias contas.
```
Depositar 200
  Deposito Realizado
```
-   Usuários podem sacar dinheiro de suas próprias contas.
```
Sacar 400
  Saque Realizado
```
-   Para realizar a maioria das operações acima, exceto Cadastro do Usuário, o usuário deve estar logado no sistema.

## Diagrama de Classes

![](agoravai.png)

