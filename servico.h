#ifndef SERVICO
#define SERVICO

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Usuario;

class Servico{
    string tipo;
    string descricao;
    float preco;
    vector<Usuario*> usuarios;

public:

    Servico(string tipo = "", string descricao = "", float preco = 0.0);

    string getTipo();

    string getDescricao();

    float getPreco();

    void alterarPreco(float novoPreco);

    void adicionarUsuario(Usuario* usuario);

    void removerUsuario(string nome);

    vector<Usuario*> getUsuarios();

    string toString();
};



#endif // SERVICO

