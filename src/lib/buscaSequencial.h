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



#endif