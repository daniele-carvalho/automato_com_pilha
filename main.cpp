#include <bits/stdc++.h>
using namespace std; 

int main(){

    string nome;
    cout<<"Digite o nome do arquivo txt\n"; //exemplo: file.txt
    cin>>nome;

    ifstream arquivo (nome);

    if (!arquivo.is_open()){
        cout<<"arquivo nao encontrado\n";
    }else{
        string linha;
        while (getline(arquivo, linha)){
            cout<<linha<<endl;
        }
    }
    arquivo.close();
}