#ifndef __BUSCASEQUENCIAL_H
#define __BUSCASEQUENCIAL_H

#include<stdlib.h>

#include "structCard.h"
#include "util.h"

Mcard *buscaCardPorId(Mcard *booster, int numeroColecao) {
    while (booster != NULL) {
        if (booster->numeroNaColecao == numeroColecao)
            return deepCopyCard(booster);
        booster = booster->proximo;
    }
    return NULL;
}

Mcard *buscaCardPorNome(Mcard *booster, char nomeCard[]) {
    Mcard *cardAux = booster;

    while (cardAux != NULL) {
        if (strcmp(cardAux->nome, nomeCard) == 0) 
            return deepCopyCard(cardAux);
        cardAux = cardAux->proximo;
    }
    return NULL;
}

Mcard *buscaCardPorCMC(Mcard *booster, int cmcBuscado) {
    Mcard *cardAux = booster;

    while (cardAux != NULL) {
        if (cardAux->cmc == cmcBuscado) 
            return deepCopyCard(cardAux);
        cardAux = cardAux->proximo;
    }
    return NULL;
}



#endif