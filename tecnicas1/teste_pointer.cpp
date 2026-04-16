#include <iostream>

using namespace std;

int main(){

    int valor = 2;
    int *ptr;

    ptr = &valor;
    *ptr = 3;

    cout << "Valor: " << &valor << endl;
    cout << "Valor do pointer: " << *ptr;

}