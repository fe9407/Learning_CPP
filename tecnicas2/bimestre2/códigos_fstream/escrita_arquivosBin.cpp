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
    Aluno turma[3];

    turma[0].nro_matricula = 1;
    turma[0].nome = "Ana";

    turma[1].nro_matricula = 2;
    turma[1].nome = "Luis";

    turma[2].nro_matricula = 3;
    turma[2].nome = "Bia";

    // Escrita de arquivos binários
    ofstream wf("alunos.dat", ios::binary);
    for(int i = 0; i < 3; i++)
    {
        wf.write((char *) &turma[i], sizeof(Aluno));
    }
    wf.close();

    return 0;
}
