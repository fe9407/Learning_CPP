#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iterator>
using namespace std;

const int numero_quartos = 100;

const char *nome_arquivo = "reservas.bin";

struct quarto
{
    int numero;
    char hospede[50];
    bool ocupado;
};
typedef struct quarto quarto;

// 1 - inicializar o arquivo com os quartos;
void iniciaArquivo()
{
    quarto tmp{};// <- zera a struct
    ofstream arq(nome_arquivo, ios::out | ios::binary);

    if(!arq)
    {
        cerr << "Falha na criacao do arquivo!" << endl;
        abort();
    }

    for(int i = 0; i < numero_quartos; i++)
    {
        //Escrevendo no arquivo os valores dos quartos
        tmp.numero = i + 1;
        arq.write(reinterpret_cast<char*>(&tmp), sizeof(quarto));
    }
    arq.close();
}

// 2 - criar um procedimento para alterar os dados de um unico quarto;
void checkIn(const char* hospede, int nro_quarto)
{
    quarto tmp;
    tmp.numero = nro_quarto;
    strcpy(tmp.hospede, hospede);
    tmp.ocupado = true;

    fstream arq(nome_arquivo, ios::out | ios::in | ios::binary);
    if(!arq)
    {
        cerr << "Nao foi possivel colocar o arquivo!" << endl;
        abort();
    }
    arq.seekp((nro_quarto - 1) * sizeof(quarto));
    arq.write(reinterpret_cast<char*>(&tmp), sizeof(quarto));
    arq.close();
}

// 3 - imprimir as informações de um determinado quarto;
void printInfo(int nro_quarto)
{
    quarto tmp;
    ifstream arq(nome_arquivo, ios::in | ios::binary);

    if(!arq.is_open())
    {
        cerr << "Falha na abertura do arquivo!" << endl;
        abort();
    }
    //reposicionar o ponteiro de leitura;
    arq.seekg((nro_quarto - 1) * sizeof(quarto));
    arq.read(reinterpret_cast<char*>(&tmp), sizeof(quarto));
    if(arq.bad())// <- bad file = falha fisica (hardware)
    {
        cerr << "Falha na leitura dos dados!" << endl;
        abort();
    }
    cout << "Quarto: " << tmp.numero << endl;
    cout << "Hospede: " << tmp.hospede << endl;
    if(tmp.ocupado) cout << "OCUPADO" << endl;
    else cout << "DISPONIVEL" << endl;
}

int main()
{
    //iniciaArquivo();
    int nro_quarto;

    cout << "informe o numero do quarto para exibir as informacoes: ";
    cin >> nro_quarto;

    printInfo(nro_quarto);

    char hospede[50];
    cout << "Informe o nome do hospede para check in: ";
    cin.ignore();
    cin.getline(hospede, 50);

    checkIn(hospede, nro_quarto);
    printInfo(nro_quarto);

    return 0;
}
