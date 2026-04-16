/*
JOGO DA VELHA

Explicação:
1.	Tabuleiro: O tabuleiro é representado por uma matriz 3x3 de caracteres, onde cada célula inicialmente contém um número de acordo com as posições i j da matriz.
2.	Exibir Tabuleiro: A função exibirTabuleiro() exibe o estado atual do jogo, com separadores entre as células.
3.	Verificar Vitória: A função verificarVitoria() verifica se um jogador ganhou, verificando se há três símbolos iguais em uma linha, coluna ou diagonal.
4.	Verificar Empate: A função verificarEmpate() verifica se todas as casas estão preenchidas e não há mais jogadas possíveis.
5.	Fazer Jogada: A função fazerJogada() permite ao jogador escolher uma posição no tabuleiro. Se a jogada for inválida (posição já ocupada ou fora de intervalo), ele tenta novamente.
6.	Alternar Jogador: A função alternarJogador() alterna entre o jogador 'X' e o jogador 'O'.

Como Jogar:
•	Dois jogadores jogam alternadamente.
•	O jogador escolhe uma posição por meio de i e j correspondente à posição no tabuleiro.
•	O programa verifica a vitória ou empate a cada jogada.

*/

#include <iostream>
using namespace std;

const int TAMANHO = 3;
char tabuleiro[TAMANHO][TAMANHO] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '} // geracao do tabuleiro vazio
};
char jogadorAtual = 'X';

// função para exibir o tabuleiro
void exibirTabuleiro(){
    cout << "\n";
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            cout << tabuleiro[i][j];
            if(j < TAMANHO - 1) cout << " | ";
        }
        cout << endl;
        if(i < TAMANHO - 1) cout << "---------\n";
    }
    cout << "\n";
}

// função para verificar a vitoria do jogador atual
bool verificarVitoria(){
    for(int i = 0; i < TAMANHO; i++){
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') return true;
        // verificação da linha
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') return true;
        // verificação da coluna
    }
    // verificação das diagonais
    if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') return true;
    // diagonal principal
    if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') return true;
    // diagonal secundaria ou oposta

    return false;
}

// função para fazer uma jogada baseada nas coordenadas (i j)
void fazerJogada(){
    int i, j;
    cout << "Jogador " << jogadorAtual << " , escolha uma posição (i j): ";
    cin >> i >> j;

    if(i >= 0 && i < TAMANHO && j >= 0 && j < TAMANHO && tabuleiro[i][j] == ' ') {
        tabuleiro[i][j] = jogadorAtual; // faz a jogada
    } else {
        cout << "Jogada invalida. Tente novamente.\n";
        fazerJogada();
    }
}

// função para verificar se todas as casas foram preenchidas (empate)
bool verificarEmpate(){
    for(int i = 0; i < TAMANHO; i++){
        for(int j = 0; j < TAMANHO; j++){
            if(tabuleiro[i][j] == ' '){
                return false;
            }
        }
    } return true; // todas as casas estao preenchidas e deu empate
}

// função para alternar o jogador X e O
void alternarJogador(){
    // jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    if(jogadorAtual == 'X'){
        jogadorAtual = 'O';
    } else {
        jogadorAtual = 'X';
    }
}

int main(){
    cout << " ## Bem-vindo ao Jogo da Velha! ##" << endl;

    exibirTabuleiro();

    while(true){
        fazerJogada();
        exibirTabuleiro();

        // verifica se o jogador atual venceu
        if(verificarVitoria()){
            cout << "Jogador " << jogadorAtual << "venceu!\n";
            break;
        }

        // verifica se houve empate
        if(verificarEmpate()){
            cout << "O jogo terminou empatado!\n";
            break;
        }

        alternarJogador();
    }

    return 0;
}