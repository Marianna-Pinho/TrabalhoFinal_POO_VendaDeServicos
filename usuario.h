#ifndef USUARIO
#define USUARIO

#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

class Servico;

class Usuario{
    string nome;
    string senha;
    float saldo;
    vector<Servico*> servicos;

public:
    Usuario(string nome = "", string senha = "", float saldo = 0.0);

    string getNome();

    string getSenha();

    float getSaldo();

    string toString();

    void depositar(float valor);

    void sacar(float valor);

    void adicionarServico(Servico *servico);

    void removerMeuServico(string tipo);

    string verMeusServicos();

    int qtdServicos();

    void contratarServico(Servico *servico, string nomeContratado);

    void removerTodosServicos();
};


#endif // USUARIO

