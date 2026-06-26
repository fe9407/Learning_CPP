#include <iostream>
#include <fstream> //file stream
#include <string>
#include <iomanip> //imput and output manipulation
#include <sstream> //String stream
using namespace std;

// primeiro linha, depois campo
// tudo é char (Uma cadeia de caracteres) -> vetor string (string campos[5])
// quando precisar de um dado que não seja string só transforma ele, mas usa tudo como string;

// Faça um programa que leia o arquivo "cadastro.txt" e exiba no terminal;
// 1 - quantidade de registros lidos
// 2 - A média da idade (com 2 casas decimais)
// 3 - o maior salario encontrado
// 4 - o nome do maior salário

int main(int argc, char *argv[])
{
    ifstream arquivo("cadastro.txt", ios::in);
    if(!arquivo.is_open())
    {
        cerr << "Não foi possivel abrir o arquivo cadastro.txt" << endl;
        return 1;
    }

    int qtd = 0;
    long somaIdade = 0;
    double maiorSalario = -1.0;
    string maiorNome;

    string linha;

    while(getline(arquivo, linha, '\n'))//Toda a linha estará dentro da variavel "linha";
    {
        if(linha.empty()) continue; // Se a linha estiver "Vazia" ele pula para a próxima;

        //Separar o campos da variavel "linha" usando o getline com 3 parametros em um fluxo (Como se fosse um cin);
        stringstream ss(linha); //ss é só o nome, pode ser qualquer cóisa;
        string *campos = new string[5]; //qtd (Faz isso fora do laço while)

        for(int i = 0; i < 5; i++)
        {
            getline(ss, campos[i], ',');
            // campos[0] -> ID
            // campos[1] -> nome
            // campos[2] -> idade
            // campos[3] -> cidade
            // campos[4] -> salario
        }
        int idade = stoi(campos[2]);
        double sal = stod(campos[4]);
        qtd++;
        somaIdade += idade;
        if(sal > maiorSalario)
        {
            maiorSalario = sal;
            maiorNome = campos[1];
        }
        delete[] campos;
    }
    arquivo.close();
    if(qtd == 0)
    {
        cout << "Arquivo vazio!" << endl;
        return 0;
    }

    cout << "Registros lidos: " << qtd << endl;
    cout << "Media de idade: " << fixed << setprecision(2) << (double) somaIdade/qtd << endl;
    cout << "Maior salario: " << fixed << setprecision(2) << maiorSalario << endl;
    cout << "Nome maior salario: " << maiorNome << endl;

    return 0;
}
