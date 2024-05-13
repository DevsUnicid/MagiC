#ifndef _UTIL_H
#define _UTIL_H

#include<string.h>
#include<ctype.h>

#include "structBoosterBox.h"

struct mCard *buscaUltimoCard(struct mCard *deck) {
    struct mCard *cardAux;
    
    cardAux = deck;
    while (cardAux->proximo != NULL) {
        cardAux = cardAux->proximo;
    }

    return cardAux;
}

char *buscaCampo(char* line, int num) {
    char* token;

    for (token = strtok(line, ","); token && *token; token = strtok(NULL, ",\n")) {
        if (!--num)
            return token;
    }
    
    return NULL;
}

char *leftTrim(char *s) {
    while(isspace(*s)) s++;
    return s;
}

char *rightTrim(char *s) {
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s) {
    return rightTrim(leftTrim(s)); 
}

void imprimeRaridade(char simbolo) {
    if (simbolo == 'C')
        printf("\n\tCOMUM");
    else if (simbolo == 'U')
        printf("\n\tINCOMUM");
    else if (simbolo == 'R')
        printf("\n\tRARA");
    else
        printf("\n\tMÍTICA");
}

int calculaCMC(char CMC[]) {
    int custo;

    if (isalpha(CMC[0])) { 
        if (CMC[0] == 'X') custo = 0;
        else return 1;
    }
    else custo = CMC[0] - '0';

    if (strlen(CMC) == 2) return custo + 1;
    else if (strlen(CMC) == 3) return custo + 2;
    else if (strlen(CMC) == 4) return custo + 3;
    else if (strlen(CMC) == 5) return custo + 4;
    else if (strlen(CMC) == 6) return custo + 5;
    else return custo + 6;
}

Mcard *deepCopyCard(Mcard *cardAlvo) {
    Mcard *pNovoCard = (Mcard *)malloc(sizeof(Mcard));

    strcpy(pNovoCard->nome, cardAlvo->nome);
    strcpy(pNovoCard->mana, cardAlvo->mana);
    pNovoCard->cmc = cardAlvo->cmc;
    strcpy(pNovoCard->tipo, cardAlvo->tipo);
    strcpy(pNovoCard->subtipo, cardAlvo->subtipo);
    pNovoCard->poder = cardAlvo->poder;
    pNovoCard->resistencia = cardAlvo->resistencia;
    pNovoCard->raridade = cardAlvo->raridade;
    pNovoCard->numeroNaColecao = cardAlvo->numeroNaColecao;
    pNovoCard->proximo = NULL;

    return pNovoCard;
}

Mcard *deepCopyBooster(Mcard *boosterAlvo) {
    Mcard *boosterNovo = boosterNovo = deepCopyCard(boosterAlvo),
          *auxUltimo = boosterAlvo;

    while(boosterAlvo->proximo != NULL) {
        boosterAlvo = boosterAlvo->proximo;
        auxUltimo = buscaUltimoCard(boosterNovo);
        auxUltimo->proximo = deepCopyCard(boosterAlvo);
    }
    return boosterNovo;
}

void randomArrayInt (int qtd, int vetor[]) {
    // Nova semente a cada chamada
    srand( time(NULL) );

    for(int i = 0; i < qtd; i++) vetor[i] = rand() % 10;
}

int contaTamanhoLista(Mcard *lista) {
    Mcard *aux = lista;
    int contador;

    for (contador = 1; aux->proximo != NULL; contador++) {
        aux = aux->proximo;
    }

    return contador;
}

Mbox *iniciaBoosterBox() {
    Mbox *boosterBox = (Mbox *) malloc(sizeof(Mbox));

    for (int i = 0; i < 36; i++) {
        boosterBox->boosters[i] = NULL;
    }
    return boosterBox;
}
// void liberaMemoria(Mcard *lista) {
//     Mcard *cardAtual = buscaUltimoCard(lista);

void strRaridade(Mcard card) {
    if (card.raridade == "C" || card.raridade == 'C')
        printf("   {Comum}");
    else if (card.raridade == "U" || card.raridade == 'U')
        printf("   {Incomum}");
    else if (card.raridade == "R" || card.raridade == 'R')
        printf("   {Rara}");
    else
        printf("   {Mítica}");
}

bool isCriatura(Mcard card) {
    return card.tipo == "Criatura" || card.tipo == 'Criatura';
}

void apresentaInfoCard(Mcard card) {
    int cont;
    char *materia;

    printf("\n# %d - %s", card.numeroNaColecao, card.nome);
    if (card.poder != -1 && card.resistencia != -1) {
        printf(" %d/%d", card.poder, card.resistencia);
    }
    
    // Imprime raridade, dado a carta
    strRaridade(card);

    printf("\n\tCusto de mana: %s (%d)", card.mana, card.cmc);
    printf("\n\t%s", card.tipo);
    
    if (card.subtipo[0] != NULL && card.subtipo[0] != "")
         printf(" - %s", card.subtipo);
    
    imprimeRaridade(card.raridade);
    printf("\n******************************\n");
}


bool ehDaCor(Mcard *card, char cor) {
    char manaAux[6];
    strcpy(manaAux, card->mana);

    for (int i = 0; i < 6; i++) {
        if (manaAux[i] == cor) return true;
    }
    return false;


}

//     while(lista->proximo != NULL) {
//         free(cardAtual);
//         cardAtual = buscaUltimoCard(lista);
//     }
//     free(cardAtual);
// }

#endif