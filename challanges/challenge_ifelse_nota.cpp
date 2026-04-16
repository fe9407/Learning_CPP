#include <iostream>

using namespace std;

int main(){
    float nota;

    cout << "Digite a nota do aluno (entre 0 e 10)\n";
    cin >> nota;

    if(nota < 0 || nota > 10){
        cout << "Digite uma nota entre 0 e 10\n";
    } else {

        if(nota < 5){
            cout << "Reprovado\n";
        } 
        else if(nota >= 6 || <= 7){
            cout << "Aprovado\n";
        } 
        else if(nota >= 8 || <= 10){
            cout << "Aprovado com louvor\n";
        }
    }
    
    return 0;
}