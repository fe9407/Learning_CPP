#include <iostream>
#include <iomanip> //necessario para o set precision

using namespace std;

int main(){

    double pi = 3.141592653589793;

    //exibe o valor padão de pi
    cout << "Valor de pi com precisao padrao: " << pi << endl;

    //exibe um valor de pi com 2 casas decimais
    cout << "Valor de pi com 2 casas decimais: " << fixed << setprecision(2) << pi << endl;

    //exibe um valor de pi com 4 casas decimais
    cout << "Valor de pi com 4 casas decimais: " << fixed << setprecision(4) << pi << endl;

    //exibe um valor de pi com 10 casas decimais
    cout << "Valor de pi com 10 casas decimais: " << fixed << setprecision(10) << pi << endl;


    return 0;
}
