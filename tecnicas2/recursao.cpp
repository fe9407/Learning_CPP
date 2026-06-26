#include <iostream>

using namespace std;
//recursão

void printInterativo(int num){
  for(int i = num; i>= 0; i--){
    cout << i << '\n';
  }
}

//Versão recursiva
/*
1 - Algoritimos recursivos chamam a si mesmo para resolver o problema
1.1 -> A chamada deve ser para im problema do mesmo tipo, só que menor
2 -> Deve haver pelo menos UMA condição de parada (caso base)
3 -> Deve haver uma maneira de unir o resultado dos subproblemas para compor a solução do problema original
*/

void printRecursivo(int n){
  cout << n << '\n';
  if(n > 0){
    printRecursivo(n-1);
  }
}

void printReverso(int n){
  if(n>0) printReverso(n-1);
  cout << n << '\n';
}

//se vc faz uma recursão de cauda, então provavelmente um "For" é melhor
//se vc faz uma recursão de mola, então provavelmente essa é a melhor escolha

//if(n>0) printRecursivo(n-1)
//cout << n << '\n';

int main (int argc, char *argv[]) {

  int n;
  if(argc == 2){
    n = atoi(argv[1]);
  }

  //printInterativo(n);
  printRecursivo(n);
  cout << '\n';
  printReverso(n);

  return 0;
}
