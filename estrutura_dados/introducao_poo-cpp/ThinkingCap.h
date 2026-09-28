#ifndef THINKINGCAP_H
#define THINKINGCAP_H
// Seção de interface // Seção de Definição
// Descrevemos quais dados o TAD gerenciar
// Descreve quais funções (ações) ele tera
#include <string>

const int MAX_TAM = 20;// Tamanho maximo da string guardada em um slot

class ThinkingCap{
    public:
        ThinkingCap();
        //Armazena as strings informadas no parametro nos campos de dados
        void slots(std::string newLeft, std::string newRight);
        //Imprime na tela a string guardada em leftSlot
        void pressLeft();
        //Imprime na tela a string guardada em rightSlot
        void pressRight();

        int totalAcionamentos(); //Retorna a quantas vezes os botoes (l+r) foram acionados
        void reinicia(); //Volta o objeto para o estado inicial (construtor)
    private:
        std::string filtro(std::string texto);
        std::string leftSlot;
        std::string rightSlot;
        int contador; // Armazenar a quantidade total de acionamentos dos botões
};
#endif
