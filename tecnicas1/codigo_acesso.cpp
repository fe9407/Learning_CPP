#include <iostream>
#include <chrono>

using namespace std;

int main(){
    
    int codigofuncionario, nivelacesso, hora, min, nivel;

    auto agora = chrono::system_clock::now();
    time_t tempo = chrono::system_clock::to_time_t(agora);
    tm* horarioLocal = localtime(&tempo);

    hora = horarioLocal->tm_hour;
    min = horarioLocal->tm_min;
    nivelacesso = 3;

    cout << "Digite seu codigo de acesso: ";
    cin >> codigofuncionario;
    //cout << "\nDigite o seu nivel de acesso: ";
    //cin >> nivelacesso;
    cout << "Digite a camada em que se dejesa acessar: ";
    cin >> nivel;
    cout << "Horario atual: " << hora << ":" << min << endl;
    
    if(codigofuncionario < 1000 || codigofuncionario > 9999){
        cout << "Codigo invalido";
    } else if(nivel > nivelacesso){
        cout << "Nivel de acesso invalido";
    } else if(hora < 8 || hora > 18){
        cout << "Horario restrito";
    } else {
        cout << "Acess granted";
    }

    return 0;
}