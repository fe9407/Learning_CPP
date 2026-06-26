#include <iostream>

using namespace std;

const int n = 5; //qtd de linhas e colunas das matrizes

void printaMatriz(const int matriz[][n]){//Por que preencher somente o segundo "[]" funciona?
    for (int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            cout << matriz[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){

  int matrizA[n][n];
  int matrizB[n][n];

  int matrizC[n][n];

  for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
          matrizA[i][j] = rand() % 100;
          matrizB[i][j] = rand() % 100;
      }
  }

  int maiorValorA=matrizA[0][0], menorValorA=matrizA[0][0], linhaMaiorA, linhaMenorA, colunaMaiorA, colunaMenorA;
  int maiorValorB=matrizB[0][0], menorValorB=matrizB[0][0], linhaMaiorB, linhaMenorB, colunaMaiorB, colunaMenorB;

  for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          /*
          if(matrizA[i][j]>matrizB[i][j]){
              matrizC[i][j] = matrizA[i][j];
          } else {
              matrizC[i][j] = matrizB[i][j];
          }
          */
          matrizC[i][j] = (matrizA[i][j] > matrizB[i][j]) ? matrizA[i][j] : matrizB[i][j];

          if(matrizA[i][j]>maiorValorA){
              maiorValorA = matrizA[i][j];
              linhaMaiorA = i+1;
              colunaMaiorA = j+1;
          }
          if(matrizB[i][j]>maiorValorB){
              maiorValorB = matrizB[i][j];
              linhaMaiorB = i+1;
              colunaMaiorB = j+1;
          }
      }
  }

  cout << "Matriz A: \n\n";
  for (int i=0;i<n;i++) {
      for(int j=0;j<n;j++){
          cout << matrizA[i][j] << ' ';
      }
      cout << '\n';
  }
  cout << "\nMaior valor A: " << maiorValorA;
  cout << "\nLinha maior A: " << linhaMaiorA;
  cout << "\nColuna maior A: " << colunaMaiorA;

  cout << "\n\nMatriz B: \n\n";
  for (int i=0;i<n;i++) {
      for(int j=0;j<n;j++){
          cout << matrizB[i][j] << ' ';
      }
      cout << '\n';
  }

  cout << "\nMaior valor B: " << maiorValorB;
  cout << "\nLinha maior B: " << linhaMaiorB;
  cout << "\nColuna maior B: " << colunaMaiorB;

  cout << "\n\nMatriz C: \n\n";
  for (int i=0;i<n;i++) {
      for(int j=0;j<n;j++){
          cout << matrizC[i][j] << ' ';
      }
      cout << '\n';
  }

  return 0;
}
