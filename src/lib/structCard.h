#ifndef STRUCTCARD_H
#define STRUCTCARD_H

struct mCard {
    char nome[50];
    char mana[15];
    int cmc; // Custo de mana convertido
    char tipo[20];
    char subtipo[30];
    int poder;
    int resistencia;
    char raridade;
    int numeroNaColecao;
    struct mCard *proximo;
};

#endif