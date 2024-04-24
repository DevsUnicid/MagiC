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
  int *elementos;
  Mcard *deck;
} Pilha;

void inicializar(Pilha *pilha) {
    pilha->topo = -1;
    pilha->deck = (Mcard *) malloc(sizeof(Mcard));
}

int estaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

void push(Pilha *pilha, Mcard *novoCard) {
    pilha->topo++;
    pilha->deck = (Mcard *) realloc(pilha->elementos, (pilha->topo + 1) * sizeof(Mcard));
    pilha->deck[pilha->topo] = *novoCard;
}

Mcard *pop(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        return NULL;
    }

    Mcard cardExcluir = pilha->deck[pilha->topo];
    pilha->topo--;
    pilha->deck = (Mcard *) realloc(pilha->deck, (pilha->topo + 1) * sizeof(Mcard));
    return &cardExcluir;
}

Mcard *topo(Pilha *pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia.\n");
        return NULL;
    }
    return &pilha->deck[pilha->topo];
}

int tamanho(Pilha *pilha) {
    return pilha->topo + 1;
}


#endif