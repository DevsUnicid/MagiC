#ifndef __PILHA_H
#define __PILHA_H
/* Código copiado do conteúdo visto em aula.
   A implementação foi copiada, porém, muitos 
   ajustes precisaram ser feitos.
*/

#include <stdio.h>
#include <stdlib.h>

#include "structCard.h"

typedef struct objPilha {
  int topo;
  Mcard *deck;
} Pilha;

void pilhaInicializar(Pilha *pilha) {
    pilha->deck = (Mcard *) malloc(sizeof(Mcard));
    pilha->topo = -1;
}

int pilhaEstaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void pilhaPush(Pilha *pilha, Mcard *novoCard) {
    pilha->topo++;
    pilha->deck = (Mcard *) realloc(pilha->deck, (pilha->topo + 1) * sizeof(Mcard));
    pilha->deck[pilha->topo] = *novoCard;
}

Mcard *pilhaPop(Pilha *pilha) {
    if (pilhaEstaVazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        return NULL;
    }

    Mcard *cardExcluir = deepCopyCard(&pilha->deck[pilha->topo]);
    pilha->topo--;
    pilha->deck = (Mcard *) realloc(pilha->deck, (pilha->topo + 1) * sizeof(Mcard));
    return cardExcluir;
}

Mcard *pilhaTopo(Pilha *pilha) {
    if (pilhaEstaVazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        return NULL;
    }
    return &pilha->deck[pilha->topo];
}

int pilhaTamanho(Pilha *pilha) {
    return pilha->topo + 1;
}


#endif