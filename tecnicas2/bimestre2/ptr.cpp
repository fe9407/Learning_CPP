#include <iostream>

using namespace std;

int main()
{
    int c = 10;
    int *p;

    //p = &c;

    cout << "valor de  c: " << c << endl;
    //cout << "valor de *p: " << *p << endl;

    int vet[5];

    for(int i=4; i >=0; i--){
        vet[i] = i-5;
        cout << "\nvet[" << i << "]: " << vet[i];
    }
    //p++ = p + 4 bytes
    p = vet; //vet = valor hexadecimal de onde começa o vetor na memoria
    cout << "\nvalor de  p[0]: " << p[0] << endl;

    return 0;
}
