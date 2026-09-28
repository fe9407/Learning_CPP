#include "DoubleStack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// ===== CONSTRUTOR =====
DoubleStack::DoubleStack() {
    // Inicializar os dois topos com valores-sentinela
    top1 = -1;           // Antes da primeira posição (pilha 1 vazia)
    top2 = MaxEntry;     // Depois da última posição (pilha 2 vazia)
}

// ===== DESTRUTOR =====
DoubleStack::~DoubleStack() {
    cout << "DoubleStack desalocada!" << endl;
}

// ===== CONSULTA GERAL =====
bool DoubleStack::full() {
    // Estrutura cheia quando os topos ficam adjacentes
    // Significa que não há espaço livre entre eles
    return (top2 - top1 == 1);
}

// ===== OPERAÇÕES PILHA 1 =====

bool DoubleStack::stack1_empty() {
    return (top1 == -1);
}

void DoubleStack::stack1_push(StackEntry x) {
    // Verificar pré-condição
    if (full()) {
        cerr << "Erro: Pilha dupla cheia! Nao eh possivel inserir." << endl;
        abort();
    }
    
    // Incrementar top1 e depois inserir
    top1++;
    entry[top1] = x;
}

void DoubleStack::stack1_pop(StackEntry &x) {
    // Verificar pré-condição
    if (stack1_empty()) {
        cerr << "Erro: Pilha 1 vazia! Nao eh possivel remover." << endl;
        abort();
    }
    
    // Copiar valor antes de mover o topo
    x = entry[top1];
    top1--;
}

void DoubleStack::stack1_clear() {
    top1 = -1;  // Voltar ao valor-sentinela
}

int DoubleStack::stack1_size() {
    // Como os índices começam em 0, um topo em posição i tem i+1 elementos
    return (top1 + 1);
}

void DoubleStack::stack1_getTop(StackEntry &x) {
    // Verificar pré-condição
    if (stack1_empty()) {
        cerr << "Erro: Pilha 1 vazia! Nao eh possivel consultar topo." << endl;
        abort();
    }
    
    // Copiar sem remover
    x = entry[top1];
}

// ===== OPERAÇÕES PILHA 2 =====

bool DoubleStack::stack2_empty() {
    return (top2 == MaxEntry);
}

void DoubleStack::stack2_push(StackEntry x) {
    // Verificar pré-condição
    if (full()) {
        cerr << "Erro: Pilha dupla cheia! Nao eh possivel inserir." << endl;
        abort();
    }
    
    // Decrementar top2 e depois inserir
    top2--;
    entry[top2] = x;
}

void DoubleStack::stack2_pop(StackEntry &x) {
    // Verificar pré-condição
    if (stack2_empty()) {
        cerr << "Erro: Pilha 2 vazia! Nao eh possivel remover." << endl;
        abort();
    }
    
    // Copiar valor antes de mover o topo
    x = entry[top2];
    top2++;
}

void DoubleStack::stack2_clear() {
    top2 = MaxEntry;  // Voltar ao valor-sentinela
}

int DoubleStack::stack2_size() {
    // Um topo em posição 7, com MaxEntry=100, significa 100-7 = 93 elementos
    return (MaxEntry - top2);
}

void DoubleStack::stack2_getTop(StackEntry &x) {
    // Verificar pré-condição
    if (stack2_empty()) {
        cerr << "Erro: Pilha 2 vazia! Nao eh possivel consultar topo." << endl;
        abort();
    }
    
    // Copiar sem remover
    x = entry[top2];
}
