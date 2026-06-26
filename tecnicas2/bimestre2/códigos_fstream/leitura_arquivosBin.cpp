#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Aluno
{
    int nro_matricula;
    string nome;
};
typedef struct Aluno Aluno;

int main()
{
    Aluno raluno[3];

    // Leitura de arquivos binários
    ifstream rf("alunos.dat", ios::binary);
    for(int i = 0; i < 3; i++)
    {
        rf.read((char *) &raluno[i], sizeof(Aluno));
    }
    rf.close();

    cout << "Informacoes do aluno:" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Nro Matricula: " << raluno[i].nro_matricula << endl;
        cout << "Nome: " << raluno[i].nome << endl;
        cout << endl;
    }

    return 0;
}
