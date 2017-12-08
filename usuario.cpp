#include <iostream>
#include "usuario.h"
#include "servico.h"


using namespace std;

Usuario::Usuario(string nome, string senha, float saldo){
    this->nome = nome;
    this->senha = senha;
    this->saldo = saldo;
}

string Usuario::getNome(){
    return this->nome;
}

string Usuario::getSenha(){
    return this->senha;
}

float Usuario::getSaldo(){
    return this->saldo;
}

string Usuario::toString(){
    stringstream ss;

    ss <<" Nome: " << this->nome << endl;

    return ss.str();
}

void Usuario::depositar(float valor){
    if(valor <= 0.0){
        throw string("Valor Invalido");
    }
    this->saldo+= valor;
}

void Usuario::sacar(float valor){
    if(valor <= 0.0){
        throw string("Valor Invalido");
    }

    if((this->saldo <= 0) || (valor > this->saldo)){
        throw string("Saldo Insuficiente");
    }
    this->saldo -= valor;
}

void Usuario::adicionarServico(Servico *servico){
    for(auto serv : servicos){
        if(serv->getTipo() == servico->getTipo()){
            throw string ("Você Já Possui esse Servico");
        }
    }

    servicos.push_back(servico);
    servico->adicionarUsuario(this);
}

void Usuario::removerMeuServico(string tipo){
    int posicao = 0;
    for(auto serv : servicos){
        if(serv->getTipo() == tipo){
            servicos.erase(servicos.begin()+posicao);
            serv->removerUsuario(this->nome);
            return;
        }
        posicao++;
    }

    throw string ("Você Não Possui esse Servico");


}

string Usuario::verMeusServicos(){
    stringstream ss;

    for(auto serv: servicos){
        ss << serv->toString();
    }
    return  ss.str();
}

int Usuario::qtdServicos(){
    return servicos.size();
}

void Usuario::contratarServico(Servico *servico, string nomeContratado){
    if(nomeContratado == this->nome){
        throw string("Voce não pode se contratar");
    }
    for(auto usuario : servico->getUsuarios()){
        if(usuario->getNome() == nomeContratado){
            this->sacar(servico->getPreco());
            usuario->depositar(servico->getPreco());
            return;
        }
    }
    throw string("Servico não possui esse usuario");
}

void Usuario::removerTodosServicos(){
    for(auto serv : servicos){
        this->removerMeuServico(serv->getTipo());
    }
}
