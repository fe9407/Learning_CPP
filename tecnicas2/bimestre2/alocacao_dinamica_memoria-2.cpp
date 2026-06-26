#include <iostream>
using namespace std;

int main()
{
    int *p = NULL;//0 ou nullptr

    //Alocação dinamica de um bloco de memoria - Referente a um número inteiro (4bytes)
    p = new int;//Se a alocação for bem sucedida, é retornado o endereço na heap onde o bloco foi alocado, caso falhe aalocação, é retornado null

    if(p == NULL)
    {
        //alocação de memoria falhou...
        abort();//encerrando o programa (De forma abrupta)
    }
    *p = 20;

    cout << "*p: " << *p << endl;//Exibe no terminal o conteudo da variavel referenciada por p
    cout << "p: " << p << endl;//exibe o endereço inical do bloco alocado na heap

    delete p;//devolve o controle de uso do bloco alocado ao SO

    return 0;
}
