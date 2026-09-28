#include <iostream>
#include "pilha.h"

int main() {
    Pilha p;
    int valorAux;

    std::cout << "=== TESTANDO ESTRUTURA DE PILHA ===" << std::endl;

    // 1. Teste de pilha inicial
    std::cout << "\n--- Estado Inicial ---" << std::endl;
    std::cout << "Pilha vazia? " << (p.vazia() ? "Sim" : "Nao") << std::endl;
    std::cout << "Tamanho atual: " << p.tamanho() << std::endl;

    // 2. Teste de Empilhar (Push)
    std::cout << "\n--- Empilhando Elementos ---" << std::endl;
    p.empilhar(10);
    p.empilhar(20);
    p.empilhar(30);

    std::cout << "Pilha vazia? " << (p.vazia() ? "Sim" : "Nao") << std::endl;
    std::cout << "Tamanho atual: " << p.tamanho() << " (Esperado: 3)" << std::endl;

    // 3. Teste de Consultar Topo
    std::cout << "\n--- Consultando Topo ---" << std::endl;
    if (p.consultarTopo(valorAux)) {
        std::cout << "Item no topo: " << valorAux << " (Esperado: 30)" << std::endl;
    }

    // 4. Teste de Desempilhar (Pop)
    std::cout << "\n--- Desempilhando Elementos ---" << std::endl;
    while (!p.vazia()) {
        if (p.desempilhar(valorAux)) {
            std::cout << "Desempilhado: " << valorAux << std::endl;
        }
    }

    // 5. Teste de Underflow (tentar desempilhar pilha vazia)
    std::cout << "\n--- Teste de Subfluxo (Underflow) ---" << std::endl;
    if (!p.desempilhar(valorAux)) {
        std::cout << "Retorno correto ao tentar desempilhar pilha vazia." << std::endl;
    }

    // 6. Teste de Limite / Pilha Cheia (Overflow)
    std::cout << "\n--- Teste de Capacidade Maxima (" << Pilha::CAPACIDADE << " itens) ---" << std::endl;
    for (int i = 0; i < Pilha::CAPACIDADE; i++) {
        p.empilhar(i + 1);
    }

    std::cout << "Pilha cheia? " << (p.cheia() ? "Sim" : "Nao") << std::endl;
    std::cout << "Tamanho atual: " << p.tamanho() << " (Esperado: " << Pilha::CAPACIDADE << ")" << std::endl;

    std::cout << "Tentando empilhar alem do limite:" << std::endl;
    p.empilhar(999); // Deve exibir mensagem de erro

    // 7. Teste do Esvaziar
    std::cout << "\n--- Testando esvaziar() ---" << std::endl;
    p.esvaziar();
    std::cout << "Pilha vazia apos esvaziar()? " << (p.vazia() ? "Sim" : "Nao") << std::endl;

    return 0;
}
