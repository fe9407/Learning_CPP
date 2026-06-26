#include <iostream>
#include <fstream>
using namespace std;

bool ehPrimo(long long n)
{
    if(n <= 1) return false;
    for(long long i = 2; i < n; i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cerr << "Uso: " << argv[0] << " <inicio> <fim>" << endl; //c error -> envia erros ao inves de uma saida para o terminal
        return 1;
    }

    //Inicio: argv[1]
    //Fim: argv[2]

    //guardar numeros primos do intervalor no arquivo;
    //abrir o arquivo para escrita
    ofstream result_set("numeros_primos.txt", ios::out);

    //laço de repetção para verificar se os numeros do intervalor são primos
    for(long long i = atoll(argv[1]); i<= atoll(argv[2]); i++)
    {
        //verificar se é primo, se sim, guardar em um arquivo
        if(ehPrimo(i)) result_set << i << '\n';
    }

    result_set.close();//fechar arquivo;

    return 0;
}
