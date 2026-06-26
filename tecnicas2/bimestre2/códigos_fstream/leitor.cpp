#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream arquivo("numeros_primos.txt", ios::in);

    if(!arquivo.is_open())
    {
        cerr << "Erro ao abrir ao arquivo" << endl;
        return 1;
    }

    long long n;
    long long qtd = 0;
    long long soma = 0;
    long long maior = 0;

    while(arquivo >> n)
    {
        qtd++;
        soma += n;
        if(n > maior) maior = n;
    }

    arquivo.close();

    if(qtd == 0)
    {
        cout << "Nenhum numero primo encontrado no arquivo" << endl;
        return 0;
    }

    cout << "Quantidade de primos: " << qtd << endl;
    cout << "Soma dos primos: " << soma << endl;
    cout << "Media dos primos: " << fixed << setprecision(2) << (double) soma/qtd << endl;
    cout << "Maior primo: " << maior << endl;

    return 0;
}
