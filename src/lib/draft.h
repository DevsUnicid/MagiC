#ifndef _DRAFT_H
#define _DRAFT_H

#include <stdlib.h>

#include "structCard.h"
#include "manipulaLista.h"

struct mCard *geraUmBooster(struct mCard *colecao) {
    struct mCard *booster = listaDeCards(colecao, 'R');

    imprimeColecao(booster);
}

struct mCard* geraBoosters(struct mCard *colecao) {
    struct mCard *teste = geraUmBooster(colecao);
}



#endif