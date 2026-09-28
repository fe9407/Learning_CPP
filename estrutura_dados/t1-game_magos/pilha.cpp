#include "pilha.h"
#include <iostream>

//Construtor
Pilha::Pilha()
{
    topo = -1;
}

//destrutor
// ...
//

//Push
bool Pilha::empilhar(int x)
{
    if(cheia())
    {
        std::cout << "Piha cheia" << std::endl;
        return false;
    }
    topo++;
    itens[topo] = x;
    return true;
}

//Pop
bool Pilha::desempilhar(int &item)
{
    if(vazia())
    {
        std::cout << "Piha vazia" << std::endl;
        return false;
    }
    item = itens[topo];
    topo--;
    return true;
}

bool Pilha::consultarTopo(int &item) const
{
    if(vazia())
    {
        std::cout << "Piha vazia" << std::endl;
        return false;
    }
    item = itens[topo];
    return true;
}

//Empty
bool Pilha::vazia() const
{
    return(topo == -1);
}

//Full
bool Pilha::cheia() const
{
    return (topo == CAPACIDADE-1);
}

//Size
int Pilha::tamanho() const
{
    return topo+1;
}

void Pilha::esvaziar()
{
    topo = -1;
}
