#include "List.h"
#include <iostream>
using namespace std;

// Regra: estas funções só podem usar a parte public de List.h
// (empty, insert, remove, retrieve, replace, clear, size).

// pré: L criada


// pós: escreve L no formato [ a1 , a2 , ... , an ] e o seu tamanho
void imprimir(List &L)
{
    // Parte 1
    ListEntry tmp;
    cout << "[ ";
    for(int p = 1; p <= L.size(); p++)
    {
        L.retrieve(p, tmp);
        cout << tmp << (p < L.size() ? "," : "");
    }
    cout << " ] size = "<< L.size() << endl;
}

// pré: L criada
// pós: retorna a posição em que x se encontra em L; caso exista mais de um x,
//      retorna o primeiro encontrado; caso não encontre, retorna zero
int buscar(List &L, ListEntry x)
{
    // Parte 2
    ListEntry tmp;
    for(int p = 1; p <= L.size(); p++)
    {
        L.retrieve(p, tmp);
        if(tmp == x) return p;
    }
    return 0;
}

// pré: L criada
// pós: p e x recebem a posição e o valor do menor elemento de L
//      (primeiro encontrado); p = 0 se L estiver vazia
void minimo(List &L, int &p, ListEntry &x)
{
    // Parte 3
    if(L.empty())
    {
        p = 0;
        return;
    }
    p = 1;
    L.retrieve(1, x);
    ListEntry tmp;
    for(int i = 2; i <= L.size(); i++)
    {
        L.retrieve(i, tmp);
        if(tmp < x)
        {
            x = tmp;
            p = i;
        }
    }
}

// pré: L criada
// pós: os elementos de L ficam em ordem inversa
void inverter(List &L)
{
    // Parte 3
}

int main()
{
    List L;
    ListEntry x;
    int p;

    // Parte 1: inserir, remover e substituir
    // (antes de executar, desenhe a lista no quadro)
    imprimir(L);
    //L.insert(posicao, elemento);
    L.insert(1, 1);
    L.insert(2, 7);
    L.insert(3, 2);
    imprimir(L);
    L.insert(2, 9);
    imprimir(L);
    L.remove(3, x);
    imprimir(L);
    cout << "x = " << x << endl;
    L.replace(1, 8);
    imprimir(L);

    // Parte 2: busca linear
    L.insert(4, 9);
    imprimir(L);
    cout << "buscar(L, 9) = " << buscar(L, 9) << endl;
    cout << "buscar(L, 8) = " << buscar(L, 8) << endl;
    cout << "buscar(L, 5) = " << buscar(L, 5) << endl;

    // Parte 3: outras operações
    minimo(L, p, x);
    cout << "minimo: p = " << p << ", x = " << x << endl;
    inverter(L);
    imprimir(L);

    // Fechamento
    L.clear();
    imprimir(L);
    minimo(L, p, x);
    cout << "minimo: p = " << p << endl;
    return 0;
}
