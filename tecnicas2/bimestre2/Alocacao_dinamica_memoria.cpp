#include <iostream>

using namespace std;

int main()
{
    int *ptr, b=5, c;

    ptr = new int;//Retorna um endereço de memoria livre na heap
    *ptr = 20;
    c = *ptr + b;

    cout << *ptr << " + " << b << " = " << c << endl;

    delete ptr;//liberar o ponteiro alocado

    return 0;
}
