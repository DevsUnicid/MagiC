#ifndef _DRAFT_H
#define _DRAFT_H

#include <stdlib.h>

#include "structCard.h"
#include "manipulaLista.h"

Mcard *geraUmBooster(Mcard *colecao) {
    Mcard *booster = listaDeCards(colecao, 'R');

    imprimeColecao(booster);
}

Mcard* geraBoosters(Mcard *colecao) {
    Mcard *teste = geraUmBooster(colecao);
}



#endif