#ifndef SISTEMA
#define SISTEMA

#include <iostream>
#include "controller.h"
#include "repository.h"
#include "usuario.h"
#include "servico.h"
#include "poo_aux.h"

using namespace std;
using namespace poo;

string HELP_SYS = R"(
CadastrarUsuario            _nome   _senha      _saldoInicial
Login                       _nome   _senha
)";

string HELP_USUARIO = R"(
CadastrarServico            _tipo   _descricao  _precoInicial
AlterarPrecoServico         _tipo   _novoPreco
DeletarConta
MostrarTodosServicos
MostrarUsuariosComServico
ProcurarServicoNome         _tipo
VerPerfil                   _nome
VerMeusServicos
RemoverMeuServico           _tipo
AdicionarServico            _tipo
ContratarServico            _tipo   _usuarioContratado
Depositar                   _valor
Sacar                       _valor
Logout
)";

void checkLogin(Usuario *usuario){
    if(usuario == nullptr){
        throw string("Nenhum Usuario Logado!");
    }
}


class Sistema : public Controller{
    Repository <Usuario> r_usuarios;
    Repository <Servico> r_servicos;

    Usuario * usuario_aux = nullptr, *usuario_aux2 = nullptr;
    Servico * servico_aux = nullptr, *servico_aux2 = nullptr;
    string menu = HELP_SYS;

public:
    Sistema():  r_usuarios("usuario"), r_servicos("servico") {}

    string process(string line){
        auto ui = poo::split(line);
        auto cmd = ui[0];

       if(cmd == "help"){
            return menu;
       }else if(cmd == "CadastrarUsuario"){
            if(usuario_aux != nullptr){
                return "Erro | Não pode cadastrar novo usuario estando logado";
            }
            r_usuarios.add(ui[1], Usuario(ui[1], ui[2], Float(ui[3]))); //ui[1]: nome, ui[2]: senha, ui[3]: saldo inicial
            return "Usuário Cadastrado!";
        }else if(cmd == "CadastrarServico"){
            string desc = join(poo::slice(ui,2, ui.size()-1), " ");
            checkLogin(usuario_aux);
            r_servicos.add(ui[1], Servico(ui[1], desc, Float(ui[ui.size()-1]))); //ui[1]: tipo, ui[2]: descrição, ui[3]: preço inicial
            return "Servico Cadastrado!";
        }else if(cmd == "AlterarPrecoServico"){
            checkLogin(usuario_aux);
            servico_aux = r_servicos.get(ui[1]);  //ui[1]: tipo, ui[2]: novo preco
            servico_aux->alterarPreco(Float(ui[2]));
            return "Preco Alterado!";
        }else if(cmd == "DeletarConta"){
            checkLogin(usuario_aux);
            usuario_aux->removerTodosServicos(); //Remove todos os servicos dos usuario e o usuario de todos os servicos que ele tem
            r_usuarios.rm(usuario_aux->getNome());       //ui[1]: nome
            usuario_aux = nullptr;      //Usuario apagou propria conta
            menu = HELP_SYS;
                return "Usuario Removido";
        }else if(cmd == "MostrarTodosServicos"){
            checkLogin(usuario_aux);
            auto vetor = r_servicos.values(); //recebe todos os servicos
            for(auto servico : vetor){
                cout << servico.toString();
            }
        }else if(cmd == "MostrarUsuariosComServico"){
            checkLogin(usuario_aux);
            auto vetor = r_usuarios.values();
            for(auto usuario : vetor){
                if(usuario.qtdServicos() != 0){
                    cout << usuario.toString();
                }
            }
        }else if(cmd == "ProcurarServicoNome"){
            checkLogin(usuario_aux);
            return r_servicos.get(ui[1])->toString(); //ui[1]: tipo
   ///////////////////USUARIO/////////////////////////////////////
        }else if(cmd == "VerPerfil"){
            checkLogin(usuario_aux);
            usuario_aux2 = r_usuarios.get(ui[1]); //ui[1]: nome   Ele pode ver o dele ou o de outro
            if(usuario_aux->getNome() == ui[1]){
                cout << "\nSaldo: " << usuario_aux->getSaldo() << endl;
            }
            return usuario_aux2->toString();
        }else if(cmd == "VerMeusServicos"){
            checkLogin(usuario_aux);
            return usuario_aux->verMeusServicos();
        }else if(cmd == "RemoverMeuServico"){
            checkLogin(usuario_aux);
            usuario_aux->removerMeuServico(ui[1]); //ui[1]: tipo  Remove o servico dele e ele do servico
            return "Servico Removido";
        }else if(cmd == "AdicionarServico"){
            checkLogin(usuario_aux);
            usuario_aux->adicionarServico(r_servicos.get(ui[1])); //ui[1]: tipo
            return "Servico Adicionado";
        }else if(cmd == "ContratarServico"){
            checkLogin(usuario_aux);
            usuario_aux->contratarServico(r_servicos.get(ui[1]), ui[2]); //ui[1]: tipo
            return "Servico Realizado";
        }else if(cmd == "Depositar"){
            checkLogin(usuario_aux);
            usuario_aux->depositar(Float(ui[1])); //ui[1]: valor
            return "Deposito Realizado";
        }else if(cmd == "Sacar"){
            checkLogin(usuario_aux);
            usuario_aux->sacar(Float(ui[1])); //ui[1]: valor
            return "Saque Realizado";
        }else if(cmd == "Login"){
            if(usuario_aux == nullptr){
               usuario_aux = r_usuarios.get(ui[1]); //ui[1]: nome, ui[2]: senha
               if(usuario_aux->getSenha() == ui[2]){
                   menu = HELP_USUARIO;
                   return "Login Realizado";
               }else{
                   usuario_aux = nullptr;
                   return "Erro | Senha Inválida";
               }
            }else{
               return "Erro | Já Há Usuario Logado";
            }
        }else if(cmd == "Logout"){
            if(usuario_aux != nullptr){
                usuario_aux = nullptr;
                menu = HELP_SYS;
                return "Logout Realizado";

            }else{
                return "Erro | Não Há Usuarios Logados";
            }
        }else if(cmd == "fim"){
            return "";
        }else{
            return string("") + "comando invalido " + "[" + cmd + "]";
        }

        return "done";
    }



};















#endif // SISTEMA

