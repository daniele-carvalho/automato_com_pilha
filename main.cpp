#include "automato.h"
#include "aux.h"
#include <bits/stdc++.h>
using namespace std; 

int main(){

    Automato automato{};
    string nome;

    cout << "Digite o nome do arquivo txt\n";
    cin >> nome;

    ler_arquivo(nome, automato);

    string cadeia;
    cout << "Digite a cadeia: ";
    cin >> cadeia;

    if(simular(automato, cadeia)){
        cout << "ACEITA" << endl;
    }else{
        cout << "REJEITA" << endl;
    }
}