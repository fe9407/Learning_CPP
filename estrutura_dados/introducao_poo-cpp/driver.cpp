//arquivo que contem a logica da função principal para resolver o problema
#include <iostream>
#include "ThinkingCap.h"

int main()
{
    ThinkingCap c1;

    int op = -1;
    std::string fraseL, fraseR;

    do {
        std::cout << "\n Escolha uma opcao" << std::endl;
        std::cout << "(1) Armazenar frases" << std::endl;
        std::cout << "(2) Pressionar botao esquerdo" << std::endl;
        std::cout << "(3) Pressionar botao direito" << std::endl;
        std::cout << "(4) Mostrar quantidade total(l+r) de acionamentos" << std::endl;
        std::cout << "(5) Reinicia capacete" << std::endl;
        std::cout << "(0) Sair" << std::endl;

        std::cin >> op;
        std::cin.ignore();

        switch (op)
        {
            case 1:{
                std::cout << "\nInforme a frase da Esquerda: ";
                getline(std::cin, fraseL);
                std::cout << "\nInforme a frase da Direita: ";
                getline(std::cin, fraseR);
                c1.slots(fraseL, fraseR);
                break;
            }
            case 2:{
                c1.pressLeft();
                break;
            }
            case 3:{
                c1.pressRight();
                break;
            }
            case 4:{
                std::cout << "Total de acionamentos: " << c1.totalAcionamentos() << std::endl;
                break;
            }
            case 5:{
                c1.reinicia();
                std::cout << "Capacete reiniciado!" << std::endl;
                break;
            }
            default:{
                std::cout << "Opcao invalida! Escolha novamente!" << std::endl;
                break;
            }
        }
    } while (op!=0);

    return 0;
}
