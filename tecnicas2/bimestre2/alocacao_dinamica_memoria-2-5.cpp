#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    int matricula;
    string nome;
    float media;
};
typedef struct Aluno Aluno;

int main()
{
    Aluno *p;
    int n;
    float soma=0;

    cout << "Informe a quantidade de alunos: ";
    cin >> n;

    p = new Aluno[n];//Alocação dinamica

    if(p == NULL)
    {
        cout << "Não ha espaço na memoria! Saindo..." << endl;
        return 333;
    }

    for(int i = 0; i < n; i++)
    {
        cout << "Informe o numero de matricula do aluno " << i+1 << ": ";
        cin >> p[i].matricula;

        cout << "Informe o nome do aluno: ";
        cin.ignore(); getline(cin, p[i].nome);

        cout << "Informe a media do aluno: ";
        cin >> p[i].media;
        soma += p[i].media;
    }

    cout << "Media da turma: " << soma/n << endl;

    delete[] p;//devolver o controle do bloco previamente alocado para o SO

    return 0;
}
