#include <iostream>

using namespace std;

int main(){
    float temperatura;

    cout << "Digite a temperatura atual (em celcius)\n";
    cin >> temperatura;

    if(temperatura < -50 || temperatura > 60){
        cout << "Digite uma temperatura entre -50° e 60°\n";
    } else {
        if(temperatura < 0){
            cout << "Muito frio\n";
        }
        else if(temperatura >= 0 && temperatura <= 15){
            cout << "Frio\n";
        }
        else if(temperatura >= 16 && temperatura <= 25){
            cout << "Agradavel\n";
        }
        else if(temperatura > 25){
            cout << "Quente\n";
        }
    }

    return 0;
}