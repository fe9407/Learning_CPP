//Seção de implementação
#include <iostream>
#include "ThinkingCap.h"

//Construtor
ThinkingCap::ThinkingCap()
{
    //Definir o estado inicial de todos os objetos instaciados a partir desta classe
    contador = 0;
    leftSlot = "(Slot vazio)";
    rightSlot = "(Slot vazio)";
}

int ThinkingCap::totalAcionamentos()
{
    return contador;
}

void ThinkingCap::reinicia()
{
    contador = 0;
    leftSlot = "(Slot vazio)";
    rightSlot = "(Slot vazio)";
}

void ThinkingCap::pressLeft()
{
    contador++;
    std::cout << leftSlot << std::endl;
}

void ThinkingCap::pressRight()
{
    contador++;
    std::cout << rightSlot << std::endl;
}

std::string ThinkingCap::filtro(std::string texto)
{
    if(texto.length() > MAX_TAM) texto = "(Slot vazio)";

    if(texto == " ") texto = "(Slot vazio)";

    return texto;
}

void ThinkingCap::slots(std::string newLeft, std::string newRight)
{
    leftSlot = filtro(newLeft);
    rightSlot = filtro(newRight);
}
