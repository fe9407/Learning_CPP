#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;

int main(){
    
    int temperatura, contador=0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>distrib(1, 30);

    while(contador < 4){
        //system("clear");
        cout << "\nVerificando temperatura\n";
        system("sleep 3");
        temperatura = distrib(gen);
        cout << "temperatura atual: " << temperatura << endl;
        if(temperatura > 25){
            cout << "Ligando ventiladores...";
        } else if(temperatura < 15){
            cout << "Ligando aquecedores...";
        } else {
            cout << "Tudo ok :)";
        }
        system("sleep 3");
        contador++;
        cout << "\nContador: " << contador << endl;
        cout << "\n\n\n\n\n\n\n\n";
    }

    return 0;
}