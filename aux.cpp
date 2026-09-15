#include "aux.h"
#include "automato.h"
#include <bits/stdc++.h>
using namespace std; 

vector<string> tirar_virgula(string linha){
    vector<string>result;
    string elemento;

    for(char c:linha){ 
        if(c == ','){
            result.push_back(elemento);
            elemento = "";
        }else{
            elemento+=c;
        }
    }
    if(!elemento.empty()){
        result.push_back(elemento);
    }
    return result;
}

string tirar_chaves(string linha){ 
    int ini = linha.find('{');
    int fim = linha.find('}');

    return linha.substr(ini + 1, fim - ini - 1);
}

void print_automato(Automato automato){
    cout<<"AUTOMATO\n";
    cout<<"Q="<<automato.Q<<endl;
    for (auto estados: automato.estadosFinais){
        cout<<estados<<" ";
    }
    cout<<endl;

    for (auto fita: automato.alfabetoFita){
        cout<<fita<<" ";
    }
    cout<<endl;

    for (auto p: automato.alfabetoPilha){
        cout<<p<<" ";
    }
    cout<<endl;

    for(auto transicao: automato.transicoes){
        cout<<"("<<transicao.estadoAtual<<",";
        cout<<transicao.entrada<<",";
        cout<<transicao.topo<<") = (";
        cout<<transicao.proximoEstado<<",";
        cout<<transicao.operacaoPilha<<")"<<endl;
    }
}