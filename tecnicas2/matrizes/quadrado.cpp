#include <iostream>

using namespace std;

int main(){

    int lado = 0;

    while(lado < 1 or lado > 20){
        cout << "Informe o lado do quadrado: ";
        cin >> lado;
    }

    //desenhando o quadrado
    for(int i=0;i<lado;i++){
    //inicialização, teste, passo: ++ | -- | / | *
        for(int j=0;j<lado;j++){
            if(j == 0 or j == lado-1 or i == 0 or i == lado-1){
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}