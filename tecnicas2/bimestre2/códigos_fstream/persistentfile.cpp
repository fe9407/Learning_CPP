#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //ofstream -> variavel de ESCRITA em arquivos; ios::out -> truca o arquivo e escreve de posição 0;
    //ofstream abre arquivos (nome do arquivo, modo de "file open");
    ofstream arquivo("arquivo.csv", ios::out);
    /*
        ios::app -> escreve sempre no final do arquivo
        ios::ate
        ios::in
        ios::out -> trunca o arquivo, cria um novo do 0
        ios::trunc
        ios::binary
    */

    //dica trabalho2
    //getline(arquivo, variavel, ',');

    cout << "Enter the account name and balance." << endl << "Enter end-of-file to end input.\n? ";

    int account;
    char name[30];
    double balance;

    //lê conta, nome e saldo a partir de "cin"
    while ( cin >> account >> name >> balance )
    {
        arquivo << account << ' ' << name << ' ' << balance << '\n';
        cout << "? ";
    }//fim do while

    return 0;
}
