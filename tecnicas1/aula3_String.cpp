#include <iostream>
#include <string> //Necessario para se usar "strings"

using namespace std;

int main(){

    int inteiro;
    //double decimal;
    //char caractere;
    //bool logico;
    //string texto;

    //entrada e saida de dados int
    cout << "Digite um numero inteiro: ";
    cin >> inteiro;
    cout << "Voce digitou o numero inteiro: " << inteiro << std::endl;

    cin.ignore();
    getline(cin, texto);
    cout << "voce digitou o texto" << texto;

    return 0;
}