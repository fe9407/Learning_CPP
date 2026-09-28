#ifndef JOGO_H
#define JOGO_H

#include <string>
#include "fila.h"
#include "pilha.h"

using namespace std;

// Estrutura para os dados dos feitiços do CSV
struct Feitico {
    int id;
    string nome;
    string elemento;
    int poder;
    string tipo;
};

// Estrutura do Mago
struct Mago {
    int id;             // Identificador do jogador (0 a N-1)
    string nome;
    int pv;             // Pontos de vida (inicia em 20)
    Fila filaPreparo;   // Fila de preparo (máximo 5)
};

// Declaração das funções do fluxo do jogo
void carregarFeiticos(Feitico catalogo[40], const string& nomeArquivo);
void inicializarGrimorio(Pilha& grimorio);
void reembaralharCemiterio(Pilha& cemiterio, Pilha& grimorio);
void exibirEstadoJogo(Mago magos[], Fila ordemTurnos, Pilha cemiterio, const Pilha& grimorio, const Feitico catalogo[40]);
void executarTurno(Mago magos[], Fila& ordemTurnos, Pilha& grimorio, Pilha& cemiterio, const Feitico catalogo[40], bool& partidaEncerrada);

#endif
