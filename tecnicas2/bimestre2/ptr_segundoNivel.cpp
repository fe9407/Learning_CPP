#include <iostream>

using namespace std;

int** criarCartela(int linhas, int colunas)
{
    int **cartela = new int*[linhas];
    for(int i = 0; i < linhas; i++)
    {
        cartela[i] = new int[colunas];
    }
    return cartela;
}

void liberarCartela(int **cartela, int linhas)
{
    for(int i = 0; i < linhas; i++)
    {
        delete[] cartela[i];
    }
    delete[] cartela;
}

int main()
{
    int l ,c;
    cout << "Digite a quantidade de linhas e colunas: ";
    cin >> l >> c;

    int **cart;

    cart = criarCartela(l, c);
    cout << "\nCartela criada";

    return 0;
}
