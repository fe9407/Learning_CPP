#include <iostream>
using namespace std;

struct Aluno{
    string nome;
    int matricula;
    double coeficiente;//nota do aluno
};
typedef struct Aluno Aluno;

void printaAluno(const Aluno *a)//recebendo a variavel com conteúdo para imprimir por referencia
{
    cout << "Nome: " << a->nome << endl;
    cout << "Matricula: " << a->matricula << endl;
    cout << "Coeficiente: " << a->coeficiente << endl;
}

void aplicaBonus(Aluno *a, double bonus)
{
    a->coeficiente += bonus;
    if(a->coeficiente > 10) a->coeficiente = 10.0;
}

int main()
{
    Aluno a1 = {"Nome aluno1", 100, 0.5};//referencia direta
    Aluno a2 = {"Nome aluno2", 101, 9.0};

    Aluno *p1, *p2;

    p1 = &a1;
    p2 = &a2;

    //Chamando a função para imprimir a struct na tela
    printaAluno(p1);
    cout << '\n';
    printaAluno(p2);


    cout << "\nAplicando o bonus...\n\n";
    //criando um procedimento para aplicar um bonus no coeficiente
    aplicaBonus(p1, 0.8);
    aplicaBonus(p2, 2.0);

    printaAluno(p1);
    cout << '\n';
    printaAluno(p2);

    return 0;
}
