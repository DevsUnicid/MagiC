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

Mcard *listaDeCardsPorRaridade(Mcard *cardColecao, char raridade) {
    int tamanhoLista = 1;
    Mcard *aux, *auxUltimo, *lista = NULL;

    while (cardColecao->proximo != NULL) {
        if (cardColecao->raridade == raridade) {
            aux = deepCopy(cardColecao);

            if (lista == NULL) {
                lista = aux;
                auxUltimo = aux;
            }
            else {
                auxUltimo->proximo = aux;
                auxUltimo = auxUltimo->proximo;
            }
            tamanhoLista++;
        }
        cardColecao = cardColecao->proximo;
    }
    auxUltimo->proximo = NULL;

    return lista;
}

void apresentaInfoCard(struct mCard card) {
    int cont;
    char *materia;

    printf("\n# %d - %s", card.numeroNaColecao, card.nome);
    if (card.poder != -1 && card.resistencia != -1) {
        printf(" %d/%d", card.poder, card.resistencia);
    }

    if (card.raridade == "C" || card.raridade == 'C')
        printf("   {Comum}");
    else if (card.raridade == "U" || card.raridade == 'U')
        printf("   {Incomum}");
    else if (card.raridade == "R" || card.raridade == 'R')
        printf("   {Rara}");
    else
        printf("   {Mítica}");

    printf("\n\tCusto de mana: %s (%d)", card.mana, card.cmc);
    printf("\n\t%s", card.tipo);
    
    if (card.subtipo[0] != NULL && card.subtipo[0] != "")
         printf(" - %s", card.subtipo);
    
    imprimeRaridade(card.raridade);
    printf("\n******************************\n");
}

void apresentaInfoCardSimplificado(struct mCard card) {
    int cont;
    char *materia;

    printf("\n# %d - %s", card.numeroNaColecao, card.nome);
    imprimeRaridade(card.raridade);
}


int imprimeColecao(struct mCard *colecao, bool simplificado) {
    struct mCard *cardAtual = colecao;

    if (colecao == NULL) 
        printf("\n\n\t NENHUMA CARTA FOI CADASTRADA NA COLEÇÃO");
    
    // Imprime primeira carta
    if (simplificado) apresentaInfoCardSimplificado(*cardAtual);
    else apresentaInfoCard(*cardAtual);

    while(cardAtual->proximo != NULL) {
        cardAtual = cardAtual->proximo;
        
        // Imprime demais cartas
        if (simplificado) apresentaInfoCardSimplificado(*cardAtual);
        else apresentaInfoCard(*cardAtual);
    }
}

void escolheCardsAleatorio(Mcard *lista, int qtd, Mcard **booster) {
    int cardEscolhido, contaCards = 1;
    Mcard *auxUltimo, *aux = lista;

    while(contaCards <= qtd){
        srand(time(NULL));
        cardEscolhido = rand() % 10;

        for (int i = 0; i < cardEscolhido ; i++) {
            aux = aux->proximo;
            if (aux == NULL) aux = lista;
        }

        if (*booster == NULL) *booster = deepCopy(aux);
        else {
            auxUltimo = buscaUltimoCard(*booster);
            auxUltimo->proximo = deepCopy(aux);
        }
        contaCards++;
    }
}

#endif