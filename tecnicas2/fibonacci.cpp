#include <chrono>
#include <iostream>

using namespace std;

long long fibRecursivo(int n){//implementação recursiva naive
    if(n<=1) return n;//if(n == 0 || n == 1) return n;
    return fibRecursivo(n-1) + fibRecursivo(n-2);
}//Isso vira uma arvore binária (O2N) formula:(2H-1 - 1)

long long fibIterativo(int n){
    long long ultimo = 1;
    long long penultimo = 0;
    long long atual = n;

    for(int i = 2; i <= n; i++){
        atual = ultimo + penultimo;
        penultimo = ultimo;
        ultimo = atual;
    }
    return atual;
}

int main(){
    int n;
    cout << "Digite o indice da sequencia: ";
    cin >> n;
    cin.ignore();

    chrono::time_point<chrono::steady_clock> inicio;
    chrono::time_point<chrono::steady_clock> fim;
    chrono::duration<double> duracao_s;
    long long resultado;

    for (int i=0; i<= n; i++) {
        inicio = chrono::steady_clock::now();
        //resultado = fibRecursivo(i);
        resultado = fibIterativo(n);
        fim = chrono::steady_clock::now();
        cout << i << ".o termo da sequencia: " << resultado << " calculado em " << duracao_s.count() << " em segundos\n";
    }

    cout << "Indice: " << fibRecursivo(n);

    return 0;
}
