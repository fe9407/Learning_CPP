#include <cctype>
#include <cmath>
#include <iostream>

using namespace std;

/*
 Pequeno analizador de frases
a) Usando somente char (String classica/C)
b) Usando somente a classe std::string (C++)

1) O programa deve ler uma frase do usuário
2) Exibir o tamanho da frase (QTD caracteres)
3) Contar e exibir o numero de vogais na frase
4) Ler uma palavra de busca e informar se ela aparece na frase (Informar somente a primeira ocorrencia)
5) Ler uma palavra de substituição e gerar uma nova frase em que a primeria ocorrencia da palavra buscada seja substituida
    pela palavra de substituição
*/
int comprimento(const char frase[]){
    int i = 0;
    while(frase[i] != '\0') i++;
    return i;
}

bool ehVogal(char c){
    c = (char) tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int buscaSubString(const char frase[], const char palavra[]){
    //Busca simples de substring
    //Retorna o indice ou -1 se não encontrar

    int comprimento_frase = comprimento(frase);
    int comprimento_palavra = comprimento(palavra);

    if(comprimento_palavra == 0 || comprimento_palavra > comprimento_frase) return -1;

    for(int i = 0; i <= comprimento_frase - comprimento_palavra; i++){
        int j=0;
        while(j < comprimento_palavra && frase[i+j] == palavra[j]) j++;
        if(j == comprimento_palavra) return i;
    }
    return -1;
}

void copiaString(const char origem[], char destino[], int tamDestino){
    //semelhante ao strcpy(c);
    int i = 0;
    while(origem[i] != '\0' && i < (tamDestino-1)){
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0';
}

void substituirPrimeiraOcorrencia(const char frase[], const char palavraBusca[], const char palavraSubst[], char fraseSubs[], int tamanho_maximo){
    int pos = buscaSubString(frase, palavraBusca);
    if(pos == -1){
        //Se não encontrar a palavra de busca na frase
        //Copia a string original para a string "destino"
        copiaString(frase, fraseSubs, tamanho_maximo);
        return;
    }

    //Para substituir a palavra:
        //Comprimento da frase original
        int n = comprimento(frase);
        //Comprimento da palavra de busca
        int mb = comprimento(palavraBusca);
        //Comprimento da palavra de substituição
        int ms = comprimento(palavraSubst);

        int k = 0;

    //Copia a frase antes da palavra para destino
    for(int i = 0; i < pos && k < (tamanho_maximo-1); i++){
        fraseSubs[k++] = frase[i];
    }
    //Copio a palavra de substituição para destino
    for(int i = 0; i < ms && k < (tamanho_maximo-1); i++){
        fraseSubs[k++] = palavraSubst[i];
    }
    //Copiar o resto da frase após a palavra buscada
    for(int i = pos + mb; i < n && (tamanho_maximo-1); i++){
        fraseSubs[k++] = frase[i];
    }
    fraseSubs[k] = '\0';
}

const int tamanho_max = 200;

int main(){

    char str[tamanho_max];//Declaração estatica de um vetor de char

    //1)
    cout << "Digite uma frase: ";
    cin.getline(str, tamanho_max);

    //2)
    int comprimento_frase = comprimento(str);
    cout << "\nTamanho da frase (Em caracteres): " << comprimento_frase;

    //3)
    int qtdVogais = 0;
    for(int i = 0; i < tamanho_max; i++){
        if(ehVogal(str[i])) qtdVogais++;
    }
    cout << "\nQuantidade de vogais na frase: " << qtdVogais;

    char palavraBusca[50];
    cout << "\nInforme a palavra para buscar: ";
    cin.getline(palavraBusca, 50);

    int pos = buscaSubString(str, palavraBusca);
    if(pos == -1) cout << "\nPalavra nao encontrada na frase!";
    cout << "\nPalavra encontrada no indice: " << pos;

    char fraseSubst[tamanho_max];
    //substituirPrimeiraOcorrencia(str, palavraBusca, const char *palavraSubst, char *fraseSubs, int tamanho_maximo)
    return 0;
}
