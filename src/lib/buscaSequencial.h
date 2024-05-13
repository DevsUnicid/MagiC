#ifndef __BUSCASEQUENCIAL_H
#define __BUSCASEQUENCIAL_H

#include <stdlib.h>

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

Mcard *buscaCardPorCor(Mcard *booster, char corBuscada) {
    Mcard *cardAuxLoop, *cardsEscolhidos, *ultimoCard;

    cardAuxLoop = booster;
    cardsEscolhidos = NULL;
    ultimoCard = NULL;

    while (cardAuxLoop != NULL) {
        printf("\n\t---cardAuxLoop: %s\n", cardAuxLoop->nome);
        if (!ehDaCor(cardAuxLoop, corBuscada)) {
            cardAuxLoop = cardAuxLoop->proximo;
            continue;
            }

        if (cardsEscolhidos == NULL) cardsEscolhidos = deepCopyCard(cardAuxLoop);
        else {
            ultimoCard = buscaUltimoCard(cardsEscolhidos);
            ultimoCard->proximo = deepCopyCard(cardAuxLoop);
        }

        cardAuxLoop = cardAuxLoop->proximo;    
    }

    return cardsEscolhidos;
}



#endif