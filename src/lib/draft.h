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

    for (int i = 0; i < 36; i++) {
        geraUmBooster(colecao, &boosterBox->boosters[i]);
    }

    return boosterBox;
}

void iniciaDraft(Mbox *boosterBox) {
    int rodada = 1, contador = 6, auxCont = 0, iteracao;
    Mbox *packBoosters = (Mbox *) malloc(sizeof(Mbox));
    Mcard *minhasCartas = NULL, 
          *auxUltimo, *auxPick;

    while (rodada <= 3) {
        for (int i = contador; i > auxCont; i--) {
            iteracao = auxCont + contador - i;
            if (iteracao == 36) continue;

            packBoosters->boosters[iteracao] = deepCopyBooster(boosterBox->boosters[iteracao]);
            
            // O código para aqui para perguntar ao usuário a carta escolhida a cada pick
            auxPick = menuPick(packBoosters->boosters[iteracao], iteracao);

            if (minhasCartas == NULL) minhasCartas = deepCopyCard(auxPick);
            else {
                auxUltimo = buscaUltimoCard(minhasCartas);
                auxUltimo->proximo = deepCopyCard(auxPick);
            }
        }

        contador = contador + 6;
        auxCont = auxCont + 6;
        rodada++;
    }
    
    system("@cls||clear");
    imprimeColecao(minhasCartas, true);
    free(packBoosters);
}

#endif