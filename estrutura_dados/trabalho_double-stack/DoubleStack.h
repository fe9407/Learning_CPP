#ifndef DOUBLESTACK_H
#define DOUBLESTACK_H

typedef int StackEntry;

class DoubleStack {
public:
    // Construtor e destrutor
    DoubleStack();
    ~DoubleStack();
    
    // Consultas gerais
    bool full();           // Retorna true se a estrutura está cheia
    
    // Operações da pilha 1 (cresce da esquerda para direita)
    bool stack1_empty();   // Retorna true se pilha 1 está vazia
    void stack1_push(StackEntry x);    // Insere x no topo da pilha 1
    void stack1_pop(StackEntry &x);    // Remove e retorna topo da pilha 1
    void stack1_clear();   // Esvazia pilha 1 completamente
    int stack1_size();     // Retorna quantidade de elementos na pilha 1
    void stack1_getTop(StackEntry &x); // Copia topo da pilha 1 sem remover
    
    // Operações da pilha 2 (cresce da direita para esquerda)
    bool stack2_empty();   // Retorna true se pilha 2 está vazia
    void stack2_push(StackEntry x);    // Insere x no topo da pilha 2
    void stack2_pop(StackEntry &x);    // Remove e retorna topo da pilha 2
    void stack2_clear();   // Esvazia pilha 2 completamente
    int stack2_size();     // Retorna quantidade de elementos na pilha 2
    void stack2_getTop(StackEntry &x); // Copia topo da pilha 2 sem remover

private:
    static const int MaxEntry = 100;
    StackEntry entry[MaxEntry];  // Vetor compartilhado pelas duas pilhas
    int top1;                    // Índice do topo da pilha 1 (-1 quando vazia)
    int top2;                    // Índice do topo da pilha 2 (MaxEntry quando vazia)
};

#endif
