#include <iostream>

using namespace std;

int main(){
    
    int numeros[10];
    int maior;
    int menor;

    cout << "size of numeros: " << sizeof(numeros) << endl;

    for(int i=0; i<10; i++){
        cout << "Digite o numero para a posicao " << i << ": ";
        cin >> numeros[i];
    }

    for(int i=0; i<10;i++){
        maior = numeros[0];
        menor = numeros[0];
        if(numeros[i] > maior){
            maior = numeros[i];
        }
        if(numeros[i] < menor){
            menor = numeros[i];
        }
    }
    cout << "O maior numero e: " << maior << endl;
    cout << "O menor numero e: " << menor << endl;

    return 0;
}