#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "pilha.h"
#include "fila.h"

using namespace std;

// Estrutura para armazenar cada feitiço
struct Feitico {
    int id;          // Posição no vetor (0 a 39)
    string nome;     // Pode conter espaços
    string elemento; // fogo, agua, terra ou ar
    int poder;       // 1 a 6 para ATAQUE; 0 para especiais
    string tipo;     // ATAQUE, REVERSO, CONTRA, RESSURREICAO
};
typedef struct Feitico Feitico;

struct Mago {
    string nome;
    int pv = 20;               // Começa com 20 Pontos de Vida
    Fila filaPreparo;          // Fila do mago (capacidade máxima 5)
};
typedef struct Mago Mago;

void inicializarGrimorioManual(Pilha& grimorio) {
    int ids[40];

    for (int i = 0; i < 40; i++) {
        ids[i] = i;
    }

    // Semente do rand
    srand(time(NULL));

    // Algoritmo Fisher-Yates
    for (int i = 39; i > 0; i--) {
        int j = rand() % (i + 1);

        // Troca ids[i] por ids[j]
        int temp = ids[i];
        ids[i] = ids[j];
        ids[j] = temp;
    }

    // Empilha no Grimório
    for (int i = 0; i < 40; i++) {
        grimorio.empilhar(ids[i]);
    }
}

// Função para ler o arquivo e preencher o vetor
int carregarFeiticos(Feitico catalogo[40], const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return 0; // Retorna 0 feitiços lidos
    }

    string linha;

    // Ignorar a linha de cabeçalho
    getline(arquivo, linha);

    int totalLidos = 0;

    while (getline(arquivo, linha) && totalLidos < 40) {
        if (linha.empty()) continue;

        stringstream ss(linha);
        string poderStr;

        // Atribui a posição no vetor como ID (0 a 39)
        catalogo[totalLidos].id = totalLidos;

        // Leitura dos campos separados por ponto e vírgula (;)
        getline(ss, catalogo[totalLidos].nome, ';');
        getline(ss, catalogo[totalLidos].elemento, ';');
        getline(ss, poderStr, ';');
        getline(ss, catalogo[totalLidos].tipo, '\r'); // Trata possíveis finais de linha CRLF/LF

        // Remove eventual '\r' remanescente do tipo
        if (!catalogo[totalLidos].tipo.empty() && catalogo[totalLidos].tipo.back() == '\r') {
            catalogo[totalLidos].tipo.pop_back();
        }

        // Converte o poder de string para inteiro
        try {
            catalogo[totalLidos].poder = stoi(poderStr);
        } catch (...) {
            catalogo[totalLidos].poder = 0;
        }

        totalLidos++;
    }

    arquivo.close();
    return totalLidos;
}

// --- PASSO 4: Distribuição Inicial de Feitiços ---
void distribuirFeiticosIniciais(Mago magos[], int numMagos, Pilha& grimorio) {
    // Para cada mago registrado (na ordem de cadastro)
    for (int i = 0; i < numMagos; i++) {
        // Cada mago recebe 3 feitiços desempilhados do Grimório
        for (int f = 0; f < 3; f++) {
            if (!grimorio.vazia()) {
                // Desempilha o ID do feitiço do Grimório
                int idFeitico = grimorio.desempilhar(idFeitico);

                // Enfileira na fila de preparo do mago
                magos[i].filaPreparo.enfileirar(idFeitico);
            }
        }
    }
}

int main() {
    Feitico catalogo[40];
    Pilha grimorio;

    // 1. Carrega o arquivo no catálogo
    carregarFeiticos(catalogo, "feiticos.csv");

    // 2. Pedir número de magos (2 a 4) e nomes
    int numMagos = 0;
    while (numMagos < 2 || numMagos > 4) {
        cout << "Digite a quantidade de magos (2 a 4): ";
        cin >> numMagos;
    }
    cin.ignore(); // Limpa o buffer do teclado

    Mago magos[4]; // Suporta até 4 magos

    for (int i = 0; i < numMagos; i++) {
        cout << "Nome do Mago " << (i + 1) << ": ";
        getline(cin, magos[i].nome);
    }

    // 3. Embaralhar os 40 IDs e empilhar no Grimório
    inicializarGrimorioManual(grimorio);

    // 4. Distribuir 3 feitiços para a fila de preparo de cada mago
    distribuirFeiticosIniciais(magos, numMagos, grimorio);

    // --- Exibição de confirmação para o Mestre ---
    cout << "\n=== Distribuição Concluída ===\n";
    for (int i = 0; i < numMagos; i++) {
        cout << "\nMago: " << magos[i].nome << " (PV: " << magos[i].pv << ")\n";
        cout << "Feitiços na Fila de Preparo:\n";

        // Exemplo visual acessando o catálogo pelo ID contido na fila
        // (Sem destruir a fila original se tiver um método de listagem/imprimir)
        magos[i].filaPreparo.imprimirComCatalogo(catalogo);
    }

    return 0;
}
