#include "fila.h"
#include <iostream>

//Construtor
Fila::Fila()
{
    quantidade = 0;
    inicio = 1;
    fim = CAPACIDADE;
}

//Destrutor
// ..
//

bool Fila::enfileirar(int item)
{
    if(cheia())
    {
        std::cout << "Fila cheia" << std::endl;
        return false;
    }
    quantidade++;
    fim = (fim % CAPACIDADE)+1;
    itens[fim] = item;
    return true;
}

bool Fila::desenfileirar(int &item)
{
    if(vazia())
    {
        std::cout << "Fila vazia" << std::endl;
        return false;
    }
    quantidade--;
    item = itens[inicio];
    inicio = (inicio % CAPACIDADE)+1;
    return true;
}

bool Fila::consultarFrente(int &item) const
{
    if(vazia())
    {
        std::cout << "Fila vazia" << std::endl;
        return false;
    }
    item = itens[inicio];
    return true;
}

bool Fila::vazia() const
{
    return(quantidade == 0);
}

bool Fila::cheia() const
{
    return(quantidade == CAPACIDADE);
}

int Fila::tamanho() const
{
    return quantidade;
}

void Fila::esvaziar()
{
    quantidade = 0;
    inicio = 1;
    fim = CAPACIDADE;
}
