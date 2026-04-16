/*
Exemplo: Cálculo de Valor de Venda com Desconto

O código a seguir calcula o valor final de um produto após aplicar um desconto e exibe o resultado com uma precisão específica

Explicação do Código
    1. Declaração das Variáveis:
        ◦ precoOriginal: Armazena o preço original do produto.
        ◦ percentualDesconto: Armazena o percentual de desconto aplicado.
        ◦ valorDesconto: Calcula o valor do desconto em reais.
        ◦ precoFinal: Calcula o preço final após aplicar o desconto.
    2. Entrada de Dados:
        ◦ O u
suário insere o preço original do produto e o percentual de desconto.
3. Cálculos:
◦ O valor do desconto é calculado multiplicando o percentual de desconto (dividido por 100) pelo preço original.
◦ O preço final é obtido subtraindo o valor do desconto do preço original.
4. Exibição dos Resultados:
◦ fixed é usado para garantir que os números de ponto flutuante sejam exibidos em notação decimal fixa.
◦ setprecision(2) define a precisão para 2 casas decimais, adequada para exibir valores monetários.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    float preco;
    float desconto;w
    float precofinal;
    float porcento;

    cout << "Digite o preco do produto: ";
    cin >> preco;

    cout << "Digite o desconto em %: ";
    cin >> desconto;

    porcento = (desconto/100) * preco;
    precofinal = preco - desconto;

    cout << "O preco total apos o desconto e: " << precofinal << endl;
    cout << "Preco final arredondado: " << fixed << setprecision(2) << precofinal << endl;

    return 0;
}