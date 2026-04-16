/*
if (condição) {
    if(condição){
    
    } else {
    
    }
} else {
  
}
*/
#include <iostream>

using namespace std;

int main(){
    int idade, salario;
    bool estudante;

    cout << " ### IDENTIFICADOR DE PESSOAS ### " << endl;

    cout << "\n Digite sua idade: ";
    cin >> idade;

    cout << "Você é estudante? (1: SIM - 0: NÃO)";
    cin >> estudante;

    cout << "Qual o seu salario? ";
    cin >> salario;

    if (idade < 18){
    
        if (estudante){

            if(salario < 3000){

            } else {
                cout << "Estudante menor de idade e salario baixo" << endl;
            }
            cout << "Estudante menor de idade" << endl;
        } else {
            cout << "Não estuda e menor de idade" << endl;
        }

    } else {
        
        if (estudante){
            cout << "Estudante maior de idade" << endl;
        } else {
            cout << "Maior de idade mas não estuda" << endl;
        }
    }

    return 0;
}
