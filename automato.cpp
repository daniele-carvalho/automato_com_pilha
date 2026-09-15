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
            }else if (linha[0]=='('){
                ler_transicoes(arquivo, automato,linha);
                break;
            }
        }
    }
    arquivo.close();
}

void ler_transicoes(ifstream &arquivo, Automato &automato, string linha){
    while (!linha.empty() && linha[0]=='('){

        //(q0,@,$) = (q1,$)
        //pega a posicao dos primeiros e ultimos parenteses
        int ini1 = linha.find('('); //0
        int fim1 = linha.find(')'); //7
        int ini2 = linha.find('(', fim1); //11
        int fim2 = linha.find(')', ini2); //16
        
        string esq = linha.substr(ini1+1, fim1-ini1-1); //q0,@,$
        string dir = linha.substr(ini2+1, fim2-ini2-1); //q1,$

        //parecido com cin, serve para leitura
        stringstream ssEsquerda(esq);
        stringstream ssDireita(dir);

        string estadoAtual, entrada, topo, proximoEstado, operacaoPilha;

        //le ate encontrar a virgula e guarda na variavel correta
        getline(ssEsquerda, estadoAtual, ',');
        getline(ssEsquerda, entrada, ',');
        getline(ssEsquerda, topo, ',');
        getline(ssDireita, proximoEstado, ',');
        getline(ssDireita, operacaoPilha, ',');

        Transicao transicao;
        transicao.estadoAtual = estadoAtual;
        transicao.entrada = entrada[0];
        transicao.topo = topo[0];
        transicao.proximoEstado = proximoEstado;
        transicao.operacaoPilha = operacaoPilha;

        automato.transicoes.push_back(transicao);
        if (!getline(arquivo, linha)){
            break;
        }
    }
}
