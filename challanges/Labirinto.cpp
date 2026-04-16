#include <iostream>

using namespace std;

void mostrarlabirinto(){
    int labirinto[5][5]{
        {3, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {2, 1, 0, 0, 0}    
    };

    for(int i=0;i<5;i++){
        cout << "\n";
        for(int j=0;j<5;j++){
            //cout << labirinto[i][j];
            switch(labirinto[i][j]){
                case 0:
                    cout << ". ";
                    break;
                
                case 1:
                    cout << "# ";
                    break;

                case 2:
                    cout << "J ";
                    break;

                case 3:
                    cout << "S ";
                    break;
            }
        }
    }
    cout << "" << endl;
}

int main(){

    int posicao[5][5];
    char opcao;

    cout << "Bem vindo ao labirinto\n";
    //mostrarlabirinto();
    int labirinto[5][5]{
        {3, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {2, 1, 0, 0, 0}    
    };

    for(int i=0;i<5;i++){
        cout << "\n";
        for(int j=0;j<5;j++){
            //cout << labirinto[i][j];
            switch(labirinto[i][j]){
                case 0:
                    cout << ". ";
                    break;
                
                case 1:
                    cout << "# ";
                    break;

                case 2:
                    cout << "J ";
                    break;

                case 3:
                    cout << "S ";
                    break;
            }
            if(labirinto[i][j] == 2){
                posicao[i][j] = 2;
            }
        }
    }
    cout << "" << endl;

    cout << "Faca uma acao: (w - cima | s - baixo | a - esquerda | d - direita)";
    cin >> opcao;

    switch(opcao){
        case 'w':
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(posicao[i][j] == 2){
                        posicao[i+1][j];
                    }
                }
            }
            break;
        case 's':
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(posicao[i][j] == 2){
                        posicao[i-1][j];
                    }
                }
            }
            break;
        case 'a':
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(posicao[i][j] == 2){
                        posicao[i][j-1];
                    }
                }
            }
            break;
        case 'd':
            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++){
                    if(posicao[i][j] == 2){
                        posicao[i][j+1];
                    }
                }
            }
            break;
    }

    for(int i=0;i<5;i++){
        cout << "\n";
        for(int j=0;j<5;j++){
            //cout << labirinto[i][j];
            switch(labirinto[i][j]){
                case 0:
                    cout << ". ";
                    break;
                
                case 1:
                    cout << "# ";
                    break;

                case 2:
                    cout << "J ";
                    break;

                case 3:
                    cout << "S ";
                    break;
            }
            if(labirinto[i][j] == 2){
                posicao[i][j] = 2;
            }
        }
    }

    return 0;
}