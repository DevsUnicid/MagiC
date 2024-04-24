#ifndef _DRAFT_H
#define _DRAFT_H

#include <stdlib.h>

#include "structCard.h"
#include "structBoosterBox.h"
#include "manipulaLista.h"

void geraUmBooster(Mcard *colecao, Mcard **booster) {
    Mcard *listaComuns = listaDeCardsPorRaridade(colecao, 'C'),
          *listaIncomuns = listaDeCardsPorRaridade(colecao, 'U'),
          *listaRaros = listaDeCardsPorRaridade(colecao, 'R'),
          *listaMiticas = listaDeCardsPorRaridade(colecao, 'M');
    int sorteio = rand() % 10;

    escolheCardsAleatorio(listaComuns, 10, booster);
    escolheCardsAleatorio(listaIncomuns, 3, booster);
    
    // Booster com mítica
    if (sorteio > 7) escolheCardsAleatorio(listaMiticas, 1, booster);
    else escolheCardsAleatorio(listaRaros, 1, booster);
}

Mbox *geraBoosters(Mcard *colecao) {
    Mbox *boosterBox = iniciaBoosterBox();
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 3; i++) {
        geraUmBooster(colecao, &boosterBox->boosters[i]);
    }

    return boosterBox;
}

void iniciaDraft(Mbox *boosterBox) {}

#endif