#include <iostream>

using namespace std;

int main(){
    
    float t1, t2, p1, p2, media;

    cout << "Digite sua nota t1: " << endl;
    cin >> t1;
    cout << "Digite sua nota p1: " << endl;
    cin >> p1;
    cout << "Digite sua nota t2: " << endl;
    cin >> t2;
    cout << "Digite sua nota p2: " << endl;
    cin >> p2;

    media = ((t1 + p1)/3) + ((t2 + p2)/3);

    if (media >= 7){
        cout << "Voce foi aprovado" << endl;
    } else { 
        cout << "Voce esta de DP, pague agora ou tranque para sempre" << endl;
    }

    return 0;
}