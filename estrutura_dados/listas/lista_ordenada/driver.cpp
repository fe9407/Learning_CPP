#include <iostream>
#include "lista-ordenada.h"

// Função auxiliar para imprimir o estado da lista
void testarBuscaEImprimir(OrderedList &lista, int valor) {
    int pos = lista.search(valor);
    if (pos > 0) {
        std::cout << "  Valor " << valor << " encontrado na posicao: " << pos << std::endl;
    } else {
        std::cout << "  Valor " << valor << " NAO encontrado." << std::endl;
    }
}

int main() {
    OrderedList lista;

    std::cout << "=== TESTE DA LISTA ENCADEADA ORDENADA ===" << std::endl << std::endl;

    // 1. Teste de lista vazia
    std::cout << "1. Verificando estado inicial:" << std::endl;
    std::cout << "  A lista esta vazia? " << (lista.empty() ? "Sim" : "Nao") << std::endl;
    std::cout << "  Tamanho inicial: " << lista.size() << std::endl;
    std::cout << "  A lista esta cheia? " << (lista.full() ? "Sim" : "Nao") << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // 2. Inserção de elementos fora de ordem para testar a ordenação
    std::cout << "2. Inserindo elementos (40, 10, 30, 20, 50)..." << std::endl;
    lista.insert(40);
    lista.insert(10);
    lista.insert(30);
    lista.insert(20);
    lista.insert(50);

    std::cout << "  Tamanho apos insercoes: " << lista.size() << std::endl;
    std::cout << "  A lista esta vazia? " << (lista.empty() ? "Sim" : "Nao") << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // 3. Teste de Busca (verificando a ordem relativa das posições)
    std::cout << "3. Buscando elementos inseridos:" << std::endl;
    testarBuscaEImprimir(lista, 10); // Esperado: Posição 1
    testarBuscaEImprimir(lista, 20); // Esperado: Posição 2
    testarBuscaEImprimir(lista, 30); // Esperado: Posição 3
    testarBuscaEImprimir(lista, 40); // Esperado: Posição 4
    testarBuscaEImprimir(lista, 50); // Esperado: Posição 5
    testarBuscaEImprimir(lista, 25); // Esperado: Não encontrado (0)
    std::cout << "------------------------------------------" << std::endl;

    // 4. Teste de Remoção
    std::cout << "4. Removendo elementos:" << std::endl;
    std::cout << "  Removendo o elemento 30 (meio)..." << std::endl;
    lista.remove(30);
    std::cout << "  Tamanho atual: " << lista.size() << std::endl;
    testarBuscaEImprimir(lista, 30);

    std::cout << "  Removendo o elemento 10 (primeiro elemento)..." << std::endl;
    lista.remove(10);
    std::cout << "  Tamanho atual: " << lista.size() << std::endl;
    testarBuscaEImprimir(lista, 10);

    std::cout << "  Removendo o elemento 50 (ultimo elemento)..." << std::endl;
    lista.remove(50);
    std::cout << "  Tamanho atual: " << lista.size() << std::endl;
    testarBuscaEImprimir(lista, 50);

    std::cout << "  Tentando remover um elemento inexistente (99)..." << std::endl;
    lista.remove(99);
    std::cout << "  Tamanho atual: " << lista.size() << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // 5. Teste de Limpeza da Lista
    std::cout << "5. Testando o metodo clear()..." << std::endl;
    lista.clear();
    std::cout << "  Tamanho apos clear(): " << lista.size() << std::endl;
    std::cout << "  A lista esta vazia? " << (lista.empty() ? "Sim" : "Nao") << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // 6. Teste de Reutilização após Clear
    std::cout << "6. Re-inserindo dados apos o clear (15, 5)..." << std::endl;
    lista.insert(15);
    lista.insert(5);
    std::cout << "  Tamanho atual: " << lista.size() << std::endl;
    testarBuscaEImprimir(lista, 5);  // Esperado: Posição 1
    testarBuscaEImprimir(lista, 15); // Esperado: Posição 2

    std::cout << "\n=== FIM DOS TESTES ===" << std::endl;

    return 0;
}
