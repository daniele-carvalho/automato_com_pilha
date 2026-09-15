#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

typedef struct{
    string estadoAtual;
    char entrada;
    char topo;
    string proximoEstado;
    string operacaoPilha;
} Transicao;

typedef struct{
    int Q;
    vector<string>estadosFinais;
    vector<string>alfabetoFita; //{a,b,c,d}
    vector<string>alfabetoPilha; //{X,Y}
    vector<Transicao>transicoes;
}Automato;

void ler_arquivo(string nome, Automato &automato);
void ler_transicoes(ifstream &arquivo, Automato &automato, string linha);

#endif