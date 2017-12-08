#include <iostream>
#include "servico.h"
#include "usuario.h"

using namespace std;



Servico::Servico(string tipo, string descricao, float preco){
    this->tipo = tipo;
    this->descricao = descricao;
    this->preco = preco;
}

string Servico::getTipo(){
    return this->tipo;
}

string Servico::getDescricao(){
    return this->descricao;
}

float Servico::getPreco(){
    return this->preco;
}

void Servico::alterarPreco(float novoPreco){
    this->preco = novoPreco;
}

void Servico::adicionarUsuario(Usuario *usuario){
    for(auto us : usuarios){
        if(us->getNome() == usuario->getNome()){
            throw string ("Você Já Possui esse Servico");
        }
    }
    usuarios.push_back(usuario);

}

void Servico::removerUsuario(string nome){
    int posicao = 0;
    for(auto usuario : usuarios){
        if(usuario->getNome() == nome){
            usuarios.erase(usuarios.begin()+posicao);
            return;
        }
        posicao++;
    }

    throw string ("Serviço Não Possui esse Usuario");

}

vector<Usuario *> Servico::getUsuarios(){
    return this->usuarios;
}

string Servico::toString(){
    stringstream ss;
    ss << "\nTipo: "      << this->tipo      << endl
       << "Preco: "       << this->preco     << endl
       << "Descricao: "   << this->descricao << endl
       << "[ ";
    for(auto usuario : usuarios){
        ss << usuario->getNome() << " ";
    }

    ss << " ]" << endl;

    return ss.str();
}
