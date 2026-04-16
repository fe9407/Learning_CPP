#include <iostream>

using namespace std;

int main(){
    char operacao;
    float num1, num2;

    cout << "### POWER CALCULATOR ###" << endl;
    cout << "Digite a operacao que ira realziar (+, -, *, /): ";
    cin >> operacao;

    cout << "Digite num 1: ";
    cin >> num1;
    cout << "Digite num 2: ";
    cin >> num2;

    switch (operacao){
        case '+': 
            cout << "Resultado: " << (num1 + num2) << endl;
            break;
        
        case '-':
            cout << "Resultado: " << (num1 - num2) << endl;
            break;
    
        case '*':
            cout << "Resultado: " << (num1 * num2) << endl;
            break;

        case '/':
            if (num2 != 0){
                cout << "Resultado: " << (num1 / num2) << endl;
            } else {
                cout << "ERRO: divisão por zero" << endl;
            }
            break;
        
        default:
            break;
    }

    return 0;
}
