#include <iostream>

using namespace std;

int main(){

    int idade;

    cout << "Digite sua idade: ";
    cin >> idade;

    if(idade <= 12){
        cout << "Crianca";
    }else if(idade >= 13 && idade <=18){
        cout << "adoslecente";
    }else if(idade >=19 && idade <= 59){
        cout << "adulto";
    }else if(idade > 100){
        cout << "voce ta morto";
    }else{
        cout << "nao e idade";
    }

    return 0;
}