#ifndef MANIPULALISTA_H
#define MANIPULALISTA_H

#include<stdlib.h>
#include<stdio.h>

#include "structCard.h"
#include "util.h"

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
            aux = deepCopyCard(cardColecao);

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

    while(contaCards <= qtd) {
        cardEscolhido = rand() % 10 + 1;

        for (int i = 0; i < cardEscolhido ; i++) {
            aux = aux->proximo;
            if (aux == NULL) aux = lista;
        }

        if (*booster == NULL) *booster = deepCopyCard(aux);
        else {
            auxUltimo = buscaUltimoCard(*booster);
            auxUltimo->proximo = deepCopyCard(aux);
        }
        contaCards++;
    }
}

#endif