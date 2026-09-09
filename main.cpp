#include "automato.h"
#include "aux.h"
#include <bits/stdc++.h>
using namespace std; 

int main(){

    Automato automato{};
    string nome;
    cout<<"Digite o nome do arquivo txt\n"; //exemplo: file.txt
    cin>>nome;

    ler_arquivo(nome, automato);
    print_automato(automato);
}