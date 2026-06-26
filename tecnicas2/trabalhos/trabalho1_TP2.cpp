// Trabalho_1_TP2_2026

// Caio Donizete teles - 2351495
// Felipe Ferreira da Silva - 2334035
// Mariana Moura de Carvalho - 2348417

/* Descrição: Cálculo de seno e cosseno utilizando séries de Taylor,
    com comparação com funções da biblioteca cmath e cálculo de erro.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

// Função que calcula o fatorial de um número inteiro não negativo
double calculaFatorial(const int valor){
    double resultado = 1;
    for(int i=1;i<=valor;i++){
        resultado = resultado * i;
    }
    return resultado;
}

// Função que calcula o cosseno de um ângulo (em radianos)
double calculaCosseno(const double radianos, const int qtd){
    double valor=0;
    for(int n = 0; n < qtd; n++){
        int sinal = (n % 2 == 0) ? 1 : -1;
        valor += sinal*(pow(radianos, 2*n))/(calculaFatorial(2*n));
    }
    return valor;
}

// Função que calcula o seno de um ângulo (em radianos)
double calculaSeno(const double radianos, const int qtd){
    double valor=0;
    for(int n = 0; n < qtd; n++){
        int sinal = (n % 2 == 0) ? 1 : -1;
        valor += sinal*(pow(radianos, 2*n+1))/(calculaFatorial(2*n+1));
    }
    return valor;
}

const double pi = 3.14159265358979323846; // Valor de Pi
const int termos_serie = 40; // Quantidade de termos usados para melhor aproximação da série

int main(){
    int graus;

    double coss, seno, coscpp, senocpp, erroCos, erroSen, erroCosPorcentagem, erroSenPorcentagem;

    cout << "Digite um valor em graus: ";
    while(!(cin >> graus)) {
        cout << "Entrada invalida, por favor digite um valor um numero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Converte o ângulo de graus para radianos, pois as funções trigonométricas utilizam radianos
    double rad = graus * (pi / 180);
    cout << "Rad: " << fixed << setprecision(6) << rad << '\n';

    coscpp = cos(rad);
    senocpp = sin(rad);

    for(int n=1;n<=3;n++){
        coss = calculaCosseno(rad, n);
        seno = calculaSeno(rad, n);

        erroCos = coss - coscpp;
        erroSen = seno - senocpp;

        erroCosPorcentagem = (coscpp != 0) ? (fabs(erroCos)/fabs(coscpp))*100 : 0;
        erroSenPorcentagem = (senocpp != 0) ? (fabs(erroSen)/fabs(senocpp))*100 : 0;

        cout << "\nValor do cosseno de " << graus << " graus com " << n << " termos: " << fixed << setprecision(16) << coss;
        cout << "\nDiferenca entre o cosseno da formula para o cosseno da biblioteca do c++ com " << n << " termos: " << fixed << setprecision(16) << fabs(erroCos);
        cout << "\nDiferenca entre o cosseno da formula para o cosseno da biblioteca do c++ com " << n << " termos em porcentagem: " << fixed << setprecision(3) << erroCosPorcentagem << '%';

        cout << '\n';

        cout << "\nValor do seno de " << graus << " graus com " << n << " termos: " << fixed << setprecision(16) << seno;
        cout << "\nDiferenca entre o seno da formula para o seno da biblioteca do c++ com " << n << " termos: " << fixed << setprecision(16) << fabs(erroSen);
        cout << "\nDiferenca entre o seno da formula para o seno da biblioteca do c++ com " << n << " termos em porcentagem: " << fixed << setprecision(3) << erroSenPorcentagem << '%';

        cout << '\n';
    }

    cout << '\n';

    coss = calculaCosseno(rad, termos_serie);
    cout << "\nValor do cosseno de " << graus << " graus com " << termos_serie << " termos: " << fixed << setprecision(16) << coss;

    seno = calculaSeno(rad, termos_serie);
    cout << "\nValor do seno de " << graus << " graus com " << termos_serie << " termos: " << fixed << setprecision(16) << seno;

    cout << '\n';

    erroCos = coss - coscpp;
    erroSen = seno - senocpp;

    erroCosPorcentagem = (coscpp != 0) ? (fabs(erroCos)/fabs(coscpp))*100 : 0;
    erroSenPorcentagem = (senocpp != 0) ? (fabs(erroSen)/fabs(senocpp))*100 : 0;

    cout << "\ncos pessoal: " << fixed << setprecision(16) << coss;
    cout << "\ncos do  c++: " << fixed << setprecision(16) << coscpp;
    cout << "\nDiferenca entre o cosseno da formula para o cosseno da biblioteca do c++: " << fixed << setprecision(16) << fabs(erroCos);
    cout << "\nDiferenca entre o cosseno da formula para o cosseno da biblioteca do c++ em porcentagem: " << fixed << setprecision(3) << erroCosPorcentagem << '%';
    cout << '\n';
    cout << "\nsen pessoal: " << fixed << setprecision(16) << seno;
    cout << "\nsen do  c++: " << fixed << setprecision(16) << senocpp;
    cout << "\nDiferenca entre o seno da formula para o seno da biblioteca do c++: " << fixed << setprecision(16) << fabs(erroSen);
    cout << "\nDiferenca entre o seno da formula para o seno da biblioteca do c++ em porcentagem: " << fixed << setprecision(3) << erroSenPorcentagem << '%';

    return 0;
}
