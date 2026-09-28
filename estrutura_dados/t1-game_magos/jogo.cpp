#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <chrono>
#include "jogo.h"

using namespace std;

// Leitura do arquivo CSV
void carregarFeiticos(Feitico catalogo[40], const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    string linha;
    getline(arquivo, linha); // Ignora o cabeçalho

    int count = 0;
    while (getline(arquivo, linha) && count < 40) {
        if (linha.empty()) continue;
        stringstream ss(linha);
        string poderStr;

        catalogo[count].id = count;
        getline(ss, catalogo[count].nome, ';');
        getline(ss, catalogo[count].elemento, ';');
        getline(ss, poderStr, ';');
        getline(ss, catalogo[count].tipo, '\r');

        if (!catalogo[count].tipo.empty() && catalogo[count].tipo.back() == '\r') {
            catalogo[count].tipo.pop_back();
        }

        try {
            catalogo[count].poder = stoi(poderStr);
        } catch (...) {
            catalogo[count].poder = 0;
        }

        count++;
    }
    arquivo.close();
}

// Inicializa o Grimório embaralhando 40 IDs
void inicializarGrimorio(Pilha& grimorio) {
    grimorio.esvaziar();
    int ids[40];
    for (int i = 0; i < 40; i++) ids[i] = i;

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(ids, ids + 40, default_random_engine(seed));

    for (int i = 0; i < 40; i++) {
        grimorio.empilhar(ids[i]);
    }
}

// Operação E7: Reembaralhamento do Cemitério para o Grimório
void reembaralharCemiterio(Pilha& cemiterio, Pilha& grimorio) {
    int topoGuardado;
    cemiterio.desempilhar(topoGuardado); // 1. Retira o topo do cemitério e guarda[cite: 5]

    int temp[40];
    int qtd = 0;
    int item;

    // 2. Desempilha os demais para um vetor temporário[cite: 5]
    while (cemiterio.desempilhar(item)) {
        temp[qtd++] = item;
    }

    // Embaralha[cite: 5]
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(temp, temp + qtd, default_random_engine(seed));

    // Empilha no grimório[cite: 5]
    for (int i = 0; i < qtd; i++) {
        grimorio.empilhar(temp[i]);
    }

    // 3. Devolve o feitiço guardado ao cemitério[cite: 5]
    cemiterio.empilhar(topoGuardado);
}

// Operação E9 & Exibição: Usa APENAS operações dos TADs sem destruir estruturas[cite: 5, 6]
void exibirEstadoJogo(Mago magos[], Fila ordemTurnos, Pilha cemiterio, const Pilha& grimorio, const Feitico catalogo[40]) {
    cout << "\n==================== ESTADO DO JOGO ====================\n";

    // 1. Ordem de turnos, começando pelo mago da vez[cite: 5]
    cout << "Ordem de turnos: ";
    int tamanhoFila = ordemTurnos.tamanho();
    int idMagoDaVez = -1;

    for (int i = 0; i < tamanhoFila; i++) {
        int idMago;
        ordemTurnos.desenfileirar(idMago);
        if (i == 0) idMagoDaVez = idMago;
        cout << magos[idMago].nome << (i < tamanhoFila - 1 ? " -> " : "");
        ordemTurnos.enfileirar(idMago);
    }
    cout << "\n--------------------------------------------------------\n";

    // 2. PV e quantidade de feitiços preparados de cada mago[cite: 5]
    for (int i = 0; i < tamanhoFila; i++) {
        int idMago;
        ordemTurnos.desenfileirar(idMago);
        cout << magos[idMago].nome << " - PV: " << magos[idMago].pv
             << " | Feitiços na Fila: " << magos[idMago].filaPreparo.tamanho() << endl;
        ordemTurnos.enfileirar(idMago);
    }
    cout << "--------------------------------------------------------\n";

    // 3. Fila de preparo completa do mago da vez[cite: 5]
    if (idMagoDaVez != -1) {
        cout << "Fila de Preparo do Mago da Vez (" << magos[idMagoDaVez].nome << "):\n";
        Fila auxFila = magos[idMagoDaVez].filaPreparo;
        int tamFilaMago = auxFila.tamanho();

        if (tamFilaMago == 0) {
            cout << "  (Fila vazia)\n";
        } else {
            for (int i = 0; i < tamFilaMago; i++) {
                int idFeitico;
                auxFila.desenfileirar(idFeitico);
                const Feitico& f = catalogo[idFeitico];
                cout << "  [" << (i + 1) << "] " << f.nome << " | Elemento: " << f.elemento
                     << " | Poder: " << f.poder << " | Tipo: " << f.tipo << "\n";
            }
        }
    }
    cout << "--------------------------------------------------------\n";

    // 4. Os 3 feitiços do topo do cemitério[cite: 5]
    cout << "Topo do Cemitério (até 3 feitiços):\n";
    Pilha auxCemiterio;
    int qtdCemiterio = 0;
    int topoId;

    while (cemiterio.desempilhar(topoId) && qtdCemiterio < 3) {
        const Feitico& f = catalogo[topoId];
        cout << "  - " << f.nome << " (" << f.tipo << ", " << f.elemento << ")\n";
        auxCemiterio.empilhar(topoId);
        qtdCemiterio++;
    }
    if (qtdCemiterio == 0) cout << "  (Cemitério vazio)\n";

    // Restaura a pilha do cemitério[cite: 6]
    while (auxCemiterio.desempilhar(topoId)) {
        cemiterio.empilhar(topoId);
    }
    cout << "--------------------------------------------------------\n";

    // 5. Quantidade de feitiços no grimório[cite: 5]
    cout << "Feitiços restantes no Grimório: " << grimorio.tamanho() << endl;
    cout << "========================================================\n\n";
}

// Operação E8: Eliminação de um mago e esvaziamento de sua fila[cite: 5, 6]
void eliminarMagoSeNecessario(int idProximoMago, Mago magos[], Fila& ordemTurnos, Pilha& cemiterio) {
    if (magos[idProximoMago].pv <= 0) {
        cout << "\n*** O mago " << magos[idProximoMago].nome << " foi ELIMINADO! ***\n";

        // Remove o mago da ordem de turnos[cite: 5]
        Fila auxTurnos;
        int idMago;
        while (ordemTurnos.desenfileirar(idMago)) {
            if (idMago != idProximoMago) {
                auxTurnos.enfileirar(idMago);
            }
        }
        ordemTurnos = auxTurnos;

        // Esvazia a fila de preparo para o cemitério (da frente para o fim)[cite: 5]
        int idFeitico;
        while (magos[idProximoMago].filaPreparo.desenfileirar(idFeitico)) {
            cemiterio.empilhar(idFeitico);
        }
    }
}

// Lógica de Execução Completa do Turno (Passos 1 a 4)[cite: 3]
void executarTurno(Mago magos[], Fila& ordemTurnos, Pilha& grimorio, Pilha& cemiterio, const Feitico catalogo[40], bool& partidaEncerrada) {
    // Retira o mago da vez da frente da fila de turnos[cite: 3]
    int idMagoDaVez;
    ordemTurnos.desenfileirar(idMagoDaVez);

    // O próximo mago é quem está agora na frente[cite: 3]
    int idProximoMago;
    ordemTurnos.consultarFrente(idProximoMago);

    // Passo 1: Exibição[cite: 3]
    // Recria temporariamente a ordem para visualização
    Fila ordemVisualizacao;
    ordemVisualizacao.enfileirar(idMagoDaVez);
    Fila temp = ordemTurnos;
    int m;
    while (temp.desenfileirar(m)) ordemVisualizacao.enfileirar(m);

    exibirEstadoJogo(magos, ordemVisualizacao, cemiterio, grimorio, catalogo);

    // Passo 2: Compra (Operação E1)[cite: 3, 6]
    if (grimorio.vazia()) {
        reembaralharCemiterio(cemiterio, grimorio); // Operação E7[cite: 3, 6]
    }

    int idComprado;
    grimorio.desempilhar(idComprado);
    cout << "Mago " << magos[idMagoDaVez].nome << " comprou o feitiço: "
         << catalogo[idComprado].nome << " (" << catalogo[idComprado].tipo << ")\n";

    if (magos[idMagoDaVez].filaPreparo.tamanho() >= 5) {
        cout << "Fila de preparo cheia (5 feitiços)! O feitiço foi enviado direto ao cemitério.\n";
        cemiterio.empilhar(idComprado);
    } else {
        int opcao = 0;
        while (opcao != 1 && opcao != 2) {
            cout << "Escolha uma ação para o feitiço comprado:\n";
            cout << "1. Preparar (enfileirar na sua fila)\n";
            cout << "2. Descartar (empilhar no cemitério)\n";
            cout << "Opção: ";
            cin >> opcao;
            if (cin.fail() || (opcao != 1 && opcao != 2)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada inválida! Digite 1 ou 2.\n";
            }
        }

        if (opcao == 1) {
            magos[idMagoDaVez].filaPreparo.enfileirar(idComprado);
        } else {
            cemiterio.empilhar(idComprado);
        }
    }

    // Passo 3: Ação[cite: 3]
    if (magos[idMagoDaVez].filaPreparo.vazia()) {
        cout << "Fila de preparo vazia. O turno foi passado automaticamente.\n";
    } else {
        int acao = 0;
        while (acao < 1 || acao > 3) {
            cout << "\nEscolha a AÇÃO do seu turno:\n";
            cout << "1. Conjurar (usar o feitiço da frente)\n";
            cout << "2. Adiar (mover o feitiço da frente para o fim da fila)\n";
            cout << "3. Encerrar a partida (voltar ao menu principal)\n";
            cout << "Opção: ";
            cin >> acao;
            if (cin.fail() || acao < 1 || acao > 3) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Entrada inválida!\n";
            }
        }

        if (acao == 3) {
            partidaEncerrada = true;
            return;
        }

        if (acao == 2) { // Adiar (Operação E3)[cite: 3, 6]
            int idFeitico;
            magos[idMagoDaVez].filaPreparo.desenfileirar(idFeitico);
            magos[idMagoDaVez].filaPreparo.enfileirar(idFeitico);
            cout << "Feitiço adiado para o fim da fila de preparo.\n";
        }
        else if (acao == 1) { // Conjurar[cite: 3]
            int idConjurado;
            magos[idMagoDaVez].filaPreparo.desenfileirar(idConjurado);
            const Feitico& f = catalogo[idConjurado];
            cout << "\n>>> CONJURANDO: " << f.nome << " (" << f.tipo << ") <<<\n";

            // --- APLICAÇÃO DOS EFEITOS (Tabela de Efeitos) ---[cite: 4]
            if (f.tipo == "ATAQUE") { // Operação E2[cite: 4, 6]
                int dano = f.poder;

                // Bônus do Cemitério[cite: 4]
                int topoCemiterio;
                if (cemiterio.consultarTopo(topoCemiterio)) {
                    if (catalogo[topoCemiterio].elemento == f.elemento) {
                        dano += 2;
                        cout << "Bônus de Elemento ativado! (+2 de dano)\n";
                    }
                }

                magos[idProximoMago].pv -= dano;
                cout << magos[idProximoMago].nome << " recebeu " << dano << " de dano! PV restante: " << magos[idProximoMago].pv << endl;

                // Envia feitiço conjurado ao cemitério[cite: 4]
                cemiterio.empilhar(idConjurado);

                // Verifica eliminação do próximo mago (Operação E8)[cite: 5, 6]
                eliminarMagoSeNecessario(idProximoMago, magos, ordemTurnos, cemiterio);
            }
            else if (f.tipo == "REVERSO") { // Operação E4[cite: 4, 6]
                cemiterio.empilhar(idConjurado);

                if (ordemTurnos.tamanho() > 1) { // Com 2 magos totais não altera o fluxo prático[cite: 4]
                    Pilha auxInversao;
                    int idTemp;
                    while (ordemTurnos.desenfileirar(idTemp)) {
                        auxInversao.empilhar(idTemp);
                    }
                    while (auxInversao.desempilhar(idTemp)) {
                        ordemTurnos.enfileirar(idTemp);
                    }
                    cout << "Ordem de turnos dos demais magos invertida!\n";
                }
            }
            else if (f.tipo == "CONTRA") { // Operação E5[cite: 4, 6]
                if (!magos[idProximoMago].filaPreparo.vazia()) {
                    int idAnulado;
                    magos[idProximoMago].filaPreparo.desenfileirar(idAnulado);
                    cemiterio.empilhar(idAnulado); // Vai para o cemitério antes do CONTRA[cite: 4]
                    cout << "O feitiço " << catalogo[idAnulado].nome << " do mago " << magos[idProximoMago].nome << " foi destruído!\n";
                }
                cemiterio.empilhar(idConjurado);
            }
            else if (f.tipo == "RESSURREICAO") { // Operação E6[cite: 4, 6]
                int idRessuscitado;
                if (cemiterio.desempilhar(idRessuscitado)) {
                    magos[idMagoDaVez].filaPreparo.enfileirar(idRessuscitado);
                    cout << "Feitiço " << catalogo[idRessuscitado].nome << " resgatado do cemitério!\n";
                }
                cemiterio.empilhar(idConjurado);
            }
        }
    }

    // Passo 4: Fim do Turno[cite: 3]
    // Reenfileira o mago da vez ao fim da fila (se ele ainda estiver no jogo)[cite: 3]
    ordemTurnos.enfileirar(idMagoDaVez);

    // Condição de vitória[cite: 5]
    if (ordemTurnos.tamanho() == 1) {
        int idVencedor;
        ordemTurnos.consultarFrente(idVencedor);
        cout << "\n============================================\n";
        cout << " PARABÉNS! O Mago " << magos[idVencedor].nome << " É O VENCEDOR!\n";
        cout << "============================================\n\n";
        partidaEncerrada = true;
    }
}

int lerOpcaoValida(int min, int max) {
    int valor;
    while (true) {
        cin >> valor;
        if (!cin.fail() && valor >= min && valor <= max) {
            return valor;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida! Escolha um valor entre " << min << " e " << max << ": ";
    }
}

int main() {
    Feitico catalogo[40];

    // 1. Carrega o catálogo de feitiços uma única vez ao iniciar o programa
    carregarFeiticos(catalogo, "feiticos.csv");

    int opcaoMenu = 0;

    while (opcaoMenu != 2) {
        cout << "========================================\n";
        cout << "            DUELO DE MAGOS              \n";
        cout << "========================================\n";
        cout << "1. Nova Partida\n";
        cout << "2. Sair\n";
        cout << "Escolha uma opção: ";

        opcaoMenu = lerOpcaoValida(1, 2);

        if (opcaoMenu == 2) {
            cout << "\nSaindo do jogo... Até logo, Mestre!\n";
            break;
        }

        // --- INÍCIO DE UMA NOVA PARTIDA ---
        Pilha grimorio;
        Pilha cemiterio;
        Fila ordemTurnos;
        Mago magos[4];

        // 2. Pedir o número de magos (2 a 4) e o nome de cada um
        cout << "\nDigite o número de magos (2 a 4): ";
        int numMagos = lerOpcaoValida(2, 4);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer do cin

        for (int i = 0; i < numMagos; i++) {
            magos[i].id = i;
            magos[i].pv = 20; // PV inicial igual a 20
            magos[i].filaPreparo.esvaziar();

            cout << "Digite o nome do Mago " << (i + 1) << ": ";
            getline(cin, magos[i].nome);

            // Adiciona na fila da ordem dos turnos (ordem de cadastro)
            ordemTurnos.enfileirar(magos[i].id);
        }

        // 3. Embaralhar os 40 IDs e empilhá-los no grimório
        inicializarGrimorio(grimorio);

        // 4. Cada mago recebe 3 feitiços iniciais na ordem de cadastro
        Fila auxTurnos = ordemTurnos;
        int idMago;
        while (auxTurnos.desenfileirar(idMago)) {
            for (int f = 0; f < 3; f++) {
                int idFeitico;
                if (grimorio.desempilhar(idFeitico)) {
                    magos[idMago].filaPreparo.enfileirar(idFeitico);
                }
            }
        }

        // 5. Loop do Jogo / Turnos
        bool partidaEncerrada = false;
        cout << "\n--- A PARTIDA COMEÇOU! ---\n";

        while (!partidaEncerrada) {
            executarTurno(magos, ordemTurnos, grimorio, cemiterio, catalogo, partidaEncerrada);
        }
    }

    return 0;
}
