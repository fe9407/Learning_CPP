#include <iostream>
#include <string>

using namespace std;


bool parimpar(int numero){
    return numero %2 == 0;
}

int main(){
    string nomes[4]={"banana", "pera", "maca", "bau"};
    string nomebusca;
    bool nomeencontrado = false;

    for(int i=0;i<4;i++){
        cout << "\nPalavra " << i+1 << ": " << nomes[i] << endl;
        for(int j=0;j<nomes[i].length();j++){
            cout << "letra "<< j+1 << ": " << nomes[i][j] << endl;
        }
    }

    media(1, 2)
}