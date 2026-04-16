#include <iostream>

using namespace std;

void limpatela(){
    cout << "\033[H\033[2J";
}

int main(){
                //L  C
    int labirinto[5][5] = {
        {0, 1, 0, 0, 3},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {2, 0, 0, 0, 0}
    };

    int poslinha, poscoluna;
    char acao;
    int continuar = 1;
    
    do {
        for(int i=0;i<5;i++){
            cout << "| ";
            for(int j=0;j<5;j++){
                //cout << labirinto[i][j] << " ";
                if(labirinto[i][j] == 2){
                    poslinha = i;
                    poscoluna = j;
                }

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
            cout << "|" << endl;
        }

        cout << "\nposlinha: " << poslinha << "\nposcoluna: " << poscoluna << endl;
        cout << "Use W A S D para se mover\n";
        cout << "Digite uma acao: ";
        cin >> acao;
        limpatela();
        switch(acao){
            case 'w':
                poslinha -= 1;
                if(poslinha < 0){
                    cout << "Fora dos limites do labirinto, tente novamente\n";
                    poslinha += 1;
                } else if(labirinto[poslinha][poscoluna]==1){
                    cout << "Nao e possivel se mover nesta posicao\n";
                    poslinha += 1;
                } else {
                    labirinto[poslinha][poscoluna]=2;
                    labirinto[poslinha+1][poscoluna]=0;
                }
                break;
            
            case 's':
                poslinha += 1;
                if(poslinha > 4){
                    cout << "Fora dos limites do labirinto, tente novamente\n";
                    poslinha -= 1;
                } else if(labirinto[poslinha][poscoluna]==1){
                    cout << "Nao e possivel se mover nesta posicao\n";
                    poslinha -= 1;
                } else {
                    labirinto[poslinha][poscoluna]=2;
                    labirinto[poslinha-1][poscoluna]=0;
                }
                break;
            
            case 'a':
                poscoluna -= 1;
                if(poscoluna < 0){
                    cout << "Fora dos limites do labirinto, tente novamente\n";
                    poscoluna += 1;
                } else if(labirinto[poslinha][poscoluna]==1){
                    cout << "Nao e possivel se mover nesta posicao\n";
                    poscoluna += 1;
                } else {
                    labirinto[poslinha][poscoluna]=2;
                    labirinto[poslinha][poscoluna+1]=0;
                }
                break;

            case 'd':
                poscoluna += 1;
                if(poscoluna > 4){
                    cout << "Fora dos limites do labirinto, tente novamente\n";
                    poscoluna -= 1;
                } else if(labirinto[poslinha][poscoluna]==1){
                    cout << "Nao e possivel se mover nesta posicao\n";
                    poscoluna -= 1;
                } else {
                    labirinto[poslinha][poscoluna]=2;
                    labirinto[poslinha][poscoluna-1]=0;
                }
                break;
        }
        labirinto[0][4] = 3;
        if(poslinha == 0 and poscoluna == 4){
            cout << "\nParabens, voce chegou ao fim do labirinto\n";
        }
    } while(continuar != 0);

    return 0;
}