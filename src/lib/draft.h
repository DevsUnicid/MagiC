#ifndef _DRAFT_H
#define _DRAFT_H

#include <stdlib.h>

#include "structCard.h"
#include "manipulaLista.h"

Mcard *geraUmBooster(Mcard *colecao) {
    Mcard *listaComuns = listaDeCardsPorRaridade(colecao, 'C');
    escolheCardsAleatorio(listaComuns, 10);

    // imprimeColecao(listaComuns);
}

Mcard* geraBoosters(Mcard *colecao) {
    Mcard *teste = geraUmBooster(colecao);
}



#endif