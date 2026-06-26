#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Aluno
{
    int matricula;
    char nome[40];
    double media;
};
typedef struct Aluno Aluno;

int main()
{
    Aluno turma[3];

    turma[0].matricula = 0;
    strcpy(turma[0].nome, "Nome");
    turma[0].media = 8.5;

    turma[1].matricula = 1;
    strcpy(turma[1].nome, "Luiz Souza");
    turma[1].media = 7.2;

    turma[2].matricula = 2;
    strcpy(turma[2].nome, "Bia Costa");
    turma[2].media = 9.1;

    ofstream wf("alunos.dat", ios::binary);

    if(!wf.is_open())
    {
        cerr << "Erro ao criar o arquivo!" << endl;
        return 1;
    }

    /*
    for(int i = 0; i < 3; i++)
    {
        wf.write(reinterpret_cast<char*> (&turma[i]), sizeof(Aluno));
    }
    */
    //ou isso
    wf.write(reinterpret_cast<char *>(turma), sizeof(Aluno)*3);//sizeof(Aluno)*Quantidade de intens na structure;

    wf.close();
    cout << "Gravados 3 alunos em alunos.dat!" << endl;

    return 0;
}
