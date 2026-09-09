#include "auxiliares.h"

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