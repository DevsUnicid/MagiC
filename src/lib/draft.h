#ifndef _DRAFT_H
#define _DRAFT_H

#include <stdlib.h>

#include "structCard.h"
#include "manipulaLista.h"

Mcard *geraUmBooster(Mcard *colecao) {
    srand(time(NULL));

    Mcard *listaComuns = listaDeCardsPorRaridade(colecao, 'C'),
          *listaIncomuns = listaDeCardsPorRaridade(colecao, 'U'),
          *listaRaros = listaDeCardsPorRaridade(colecao, 'R'),
          *listaMiticas = listaDeCardsPorRaridade(colecao, 'M'),
          *booster = NULL;
    int sorteio = rand() % 10;

    escolheCardsAleatorio(listaComuns, 10, &booster);
    escolheCardsAleatorio(listaIncomuns, 3, &booster);
    
    // Booster com mítica
    if (sorteio > 7) escolheCardsAleatorio(listaMiticas, 1, &booster);
    else escolheCardsAleatorio(listaRaros, 1, &booster);

    printf("contaTamanhoLista(booster): %d\n", contaTamanhoLista(booster));
    imprimeColecao(booster, false);
}

Mcard* geraBoosters(Mcard *colecao) {
    Mcard *teste = geraUmBooster(colecao);
}



#endif