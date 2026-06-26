#include <iostream>
#include <fstream>
#include <iomanip>
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
    ifstream rf("alunos.dat", ios::binary);// ou (ifstream rf("alunos.dat", ios::in | ios::binary);)

    if(!rf)
    {
        cerr << "Arquivo não encontrado ou inacessivel!" << endl;
        return 2;
    }

    Aluno a;

    cout << left << setw(12) << "Matricula" << setw(25) << "nome" << "Media" << endl;

    while(rf.read(reinterpret_cast<char *>(&a) ,sizeof(Aluno)))
    {
        cout << left << setw(12) << a.matricula << setw(25) << a.nome << fixed << setprecision(2) << a.media << endl;
    }

    if(rf.eof()){
        cout << "\nFim do arquivo alcançado normalmente!" << endl;
        rf.close();
        return 0;
    } else if(rf.bad()){
        //verifica falha de hardware durante a leitura;
        cerr << "Erro do dispositivo durante a leitura" << endl;
        rf.close();
        return 3;
    }

    return 0;
}
