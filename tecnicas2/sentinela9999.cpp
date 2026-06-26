#include <iostream>

using namespace std;

int main(){

  int qtd, valorDigitado;  
  cout << "Digite a quantidade de numeros em que se deseja calcular a media: ";
  cin >> qtd;
  
  for(int i=0;i<qtd;i++){
    cout << "Digite o numero " << i+1;
    cin >> valorDigitado;
    total+= valorDigitado;
  }


  return 0;
}