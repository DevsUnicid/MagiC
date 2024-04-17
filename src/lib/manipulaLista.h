#ifndef MANIPULALISTA_H
#define MANIPULALISTA_H

#include<stdlib.h>
#include<stdio.h>

#include "structCard.h"
#include "util.h"

struct mCard *buscaUltimoCard(struct mCard *deck) {
    struct mCard *cardAux;
    
    cardAux = deck;
    while (cardAux->proximo != NULL) {
        cardAux = cardAux->proximo;
    }

    return cardAux;
}

void adicionaCardNoDeck(struct mCard *novoCard, struct mCard *deck) {
    struct mCard *ultimo = buscaUltimoCard(deck);

    ultimo->proximo = novoCard;
}

struct mCard *alocaCardFromChar(char infoCard[], int numeroCarta) {
    struct mCard *pNovoCard;

    char *nome, *mana, *tipo, *subtipo, *temp, *raridade;
    int cmc, poder, resistencia, numeroColecao;

    temp = strdup(infoCard);
    nome = trim(buscaCampo(temp, 1));

    temp = strdup(infoCard);
    mana = trim(buscaCampo(temp, 2));

    temp = strdup(infoCard);
    cmc = calculaCMC(trim(buscaCampo(temp, 2)));

    temp = strdup(infoCard);
    tipo = trim(buscaCampo(temp, 3));

    temp = strdup(infoCard);
    subtipo = trim(buscaCampo(temp, 4));

    temp = strdup(infoCard);
    poder = atoi(buscaCampo(temp, 5));

    temp = strdup(infoCard);
    resistencia = atoi(buscaCampo(temp, 6));

    temp = strdup(infoCard);
    raridade = trim(buscaCampo(temp, 7));

    temp = strdup(infoCard);
    numeroColecao = numeroCarta;

    pNovoCard = (struct mCard *)malloc(sizeof(struct mCard));
    strcpy(pNovoCard->nome, nome);
    strcpy(pNovoCard->mana, mana);
    pNovoCard->cmc = cmc;
    strcpy(pNovoCard->tipo, tipo);
    strcpy(pNovoCard->subtipo, subtipo);
    pNovoCard->poder = poder;
    pNovoCard->resistencia = resistencia;
    pNovoCard->raridade = raridade[0];
    pNovoCard->numeroNaColecao = numeroColecao;
    pNovoCard->proximo = NULL;

    
    return pNovoCard;
}

struct mCard *listaDeCards(struct mCard *cardColecao, char raridade) {
    int tamanhoLista = 1;
    struct mCard *lista, *aux;

    while (cardColecao->proximo != NULL) {
        if (cardColecao->raridade == raridade) {
            aux = deepCopy(cardColecao);

            printf("\n\t%s", aux->nome);

            if (lista == NULL) lista = aux;
            else lista->proximo = aux;
        }
        cardColecao = cardColecao->proximo;
    }

    return lista;
}

void apresentaInfoCard(struct mCard card) {
    int cont;
    char *materia;

    printf("\n# %d - %s", card.numeroNaColecao, card.nome);
    if (card.poder != -1 && card.resistencia != -1) {
        printf(" %d/%d", card.poder, card.resistencia);
    }

    printf("\n\tCusto de mana: %s (%d)", card.mana, card.cmc);
    printf("\n\t%s", card.tipo);
    
    if (card.subtipo[0] != NULL && card.subtipo[0] != "")
         printf(" - %s", card.subtipo);
    
    imprimeRaridade(card.raridade);
    printf("\n******************************\n");
}

int imprimeColecao(struct mCard *colecao) {
    struct mCard *cardAtual = colecao;

    if (colecao == NULL) 
        printf("\n\n\t NENHUMA CARTA FOI CADASTRADA NA COLEÇÃO");
    
    apresentaInfoCard(*colecao);
    while(cardAtual->proximo != NULL) {
        cardAtual = cardAtual->proximo;
        apresentaInfoCard(*cardAtual);
    }
}

#endif