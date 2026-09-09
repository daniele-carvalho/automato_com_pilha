#include "automato.h"
#include "aux.h"
#include <bits/stdc++.h>
using namespace std;

void ler_arquivo(string nome, Automato &automato){    
    ifstream arquivo(nome);
    if(!arquivo.is_open()){
        cout<<"Arquivo não encontrado!\n";
    }else{
        string linha;
        while(getline(arquivo, linha)){
            if(linha.empty()){
                continue;
            }
            if(linha[0]=='Q'){ //Q=9
                automato.Q = stoi(linha.substr(2));
            }else if(linha[0]=='F'){
                linha = tirar_chaves(linha);
                automato.estadosFinais = tirar_virgula(linha);
            }else if (linha.find("alfabeto_pilha") != string::npos){
                linha = tirar_chaves(linha);
                automato.alfabetoPilha = tirar_virgula(linha);
            }else if (linha.find("alfabeto_fita")!= string::npos){
                linha = tirar_chaves(linha);
                automato.alfabetoFita = tirar_virgula(linha);
            }
        }
    }

    arquivo.close();
}