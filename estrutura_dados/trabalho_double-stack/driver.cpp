#include <iostream>
#include "DoubleStack.h"

using namespace std;

int main() {
    DoubleStack historico;           // Estrutura de pilha dupla
    int paginaAtual = -1;            // -1 = nenhuma página visitada
    int opcao;
    
    while (true) {
        // Exibir menu
        cout << "O que deseja fazer?" << endl;
        cout << "[1] Visitar pagina" << endl;
        cout << "[2] Voltar" << endl;
        cout << "[3] Avancar" << endl;
        cout << "[4] Pagina atual" << endl;
        cout << "[0] Sair" << endl;
        
        cin >> opcao;
        
        switch (opcao) {
            case 1: {
                // Visitar pagina
                int novaPagina;
                cout << "Digite o ID da pagina: ";
                cin >> novaPagina;
                
                // Se houver página atual, empilhar na pilha 1 (passado)
                if (paginaAtual != -1) {
                    historico.stack1_push(paginaAtual);
                }
                
                // CRUCIAL: Limpar pilha 2 (descarta o "futuro")
                historico.stack2_clear();
                
                // Atualizar página atual
                paginaAtual = novaPagina;
                
                // Exibir status
                cout << "********************" << endl;
                cout << "Pagina atual: " << paginaAtual << endl;
                cout << "Voltar: " << historico.stack1_size() 
                     << " | Avancar: " << historico.stack2_size() << endl;
                cout << "********************" << endl;
                break;
            }
            
            case 2: {
                // Voltar
                if (historico.stack1_empty()) {
                    cout << "Nao ha pagina anterior no historico!" << endl;
                } else {
                    // Página atual vira futuro (vai para pilha 2)
                    historico.stack2_push(paginaAtual);
                    
                    // Desempilhar da pilha 1 (passado vira atual)
                    historico.stack1_pop(paginaAtual);
                    
                    // Exibir status
                    cout << "********************" << endl;
                    cout << "Pagina atual: " << paginaAtual << endl;
                    cout << "Voltar: " << historico.stack1_size() 
                         << " | Avancar: " << historico.stack2_size() << endl;
                    cout << "********************" << endl;
                }
                break;
            }
            
            case 3: {
                // Avancar
                if (historico.stack2_empty()) {
                    cout << "Nao ha pagina seguinte no historico!" << endl;
                } else {
                    // Página atual vira passado (vai para pilha 1)
                    historico.stack1_push(paginaAtual);
                    
                    // Desempilhar da pilha 2 (futuro vira atual)
                    historico.stack2_pop(paginaAtual);
                    
                    // Exibir status
                    cout << "********************" << endl;
                    cout << "Pagina atual: " << paginaAtual << endl;
                    cout << "Voltar: " << historico.stack1_size() 
                         << " | Avancar: " << historico.stack2_size() << endl;
                    cout << "********************" << endl;
                }
                break;
            }
            
            case 4: {
                // Pagina atual
                if (paginaAtual == -1) {
                    cout << "********************" << endl;
                    cout << "Nenhuma pagina visitada ainda." << endl;
                    cout << "********************" << endl;
                } else {
                    cout << "********************" << endl;
                    cout << "Pagina atual: " << paginaAtual << endl;
                    cout << "********************" << endl;
                }
                break;
            }
            
            case 0: {
                // Sair
                return 0;
            }
            
            default: {
                // Opção inválida: ignorar
                break;
            }
        }
        
        cout << endl;  // Linha em branco para legibilidade
    }
    
    return 0;
}
