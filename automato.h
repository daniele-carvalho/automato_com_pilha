#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <string>
#include <vector>
using namespace std;

typedef struct{
    string estadoAtual;
    char entrada;
    char topo;
    string proximoEstado;
    char operacaoPilha;
} Transicao;

typedef struct{
    int Q;
    vector<string>estadosFinais;
    vector<string>alfabetoFita; //{a,b,c,d}
    vector<string>alfabetoPilha; //{X,Y}
    vector<Transicao>transicoes;
    //os vetores sao string e nao char para o aproveitamento de funcoes
    //para mais de um vetor
}Automato;

void ler_arquivo(string nome, Automato &automato);


#endif