#include <iostream>
#include "fila.h"

int main() {
    Fila f;
    int valor;

    std::cout << "--- TESTANDO ESTADO INICIAL ---" << std::endl;
    std::cout << "Fila vazia? " << (f.vazia() ? "Sim" : "Nao") << std::endl;
    std::cout << "Tamanho inicial: " << f.tamanho() << std::endl;

    std::cout << "\n--- TESTANDO ENFILEIRAR (PUSH) ---" << std::endl;
    for (int i = 10; i <= 50; i += 10) {
        if (f.enfileirar(i)) {
            std::cout << "Enfileirado com sucesso: " << i << std::endl;
        }
    }
    std::cout << "Tamanho apos insercoes: " << f.tamanho() << std::endl;

    std::cout << "\n--- TESTANDO CONSULTAR FRENTE ---" << std::endl;
    if (f.consultarFrente(valor)) {
        std::cout << "Item da frente da fila: " << valor << std::endl;
    }

    std::cout << "\n--- TESTANDO DESENFILEIRAR (POP) ---" << std::endl;
    if (f.desenfileirar(valor)) {
        std::cout << "Desenfileirado: " << valor << std::endl;
    }
    std::cout << "Tamanho apos remocao: " << f.tamanho() << std::endl;

    if (f.consultarFrente(valor)) {
        std::cout << "Novo item da frente: " << valor << std::endl;
    }

    std::cout << "\n--- TESTANDO ESVAZIAR ---" << std::endl;
    f.esvaziar();
    std::cout << "Fila vazia apos esvaziar? " << (f.vazia() ? "Sim" : "Nao") << std::endl;
    std::cout << "Tamanho final: " << f.tamanho() << std::endl;

    std::cout << "\n--- TESTANDO DESENFILEIRAR EM FILA VAZIA ---" << std::endl;
    if (!f.desenfileirar(valor)) {
        std::cout << "Operacao negada corretamente." << std::endl;
    }

    return 0;
}
