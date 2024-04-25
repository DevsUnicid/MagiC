#ifndef _MENU_H
#define _MENU_H

#include<stdlib.h>
#include<stdio.h>

#include "buscaSequencial.h"

TAMANHO_PADRAO=80;

void imprimeRepeticao(char padrao, int qtd) {
    for (int cont = 0; cont < qtd; cont++) {
        printf("%c", padrao);
    }
}

void espacamentoVertical(int tamanhoPadrao) {
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("                                                        ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
}

void menuInicial(bool comCabecalho, bool apagaTudo) {
    int tamanhoPadrao = TAMANHO_PADRAO;

    if (apagaTudo) system("@cls||clear");

    imprimeRepeticao('*', tamanhoPadrao);
    printf("\n");
    imprimeRepeticao('*', tamanhoPadrao);

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical(tamanhoPadrao);

    // Cabeçalho
    if (comCabecalho) {    
        printf("\n");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
        printf("     Seja muito bem vindo(a) ao simulador de Draft!     ");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

        printf("\n");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
        printf("   O simulador te auxiliará nas picks durante o draft   ");
        imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    }

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical(tamanhoPadrao);
    espacamentoVertical(tamanhoPadrao);

    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("              O que deseja fazer agora?                 ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("   (Digite o número correspondente à ação que deseja)   ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Pula linha no menu (espaçamento vertical)
    espacamentoVertical(tamanhoPadrao);
    espacamentoVertical(tamanhoPadrao);

    // Opção 1 - Mostrar Coleção
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          1 - Apresentar coleção                        ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 2 - Iniciar Draft
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          2 - Buscar cards                              ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 3 - Iniciar Draft
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          3 - Iniciar Draft                             ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Opção 0 - Sair do programa
    printf("\n");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);
    printf("          0 - Sair do programa                          ");
    imprimeRepeticao('*', (tamanhoPadrao - 56)/2);

    // Pula linha no menu (espaçamento vert ical)
    espacamentoVertical(tamanhoPadrao);
    espacamentoVertical(tamanhoPadrao);

    // Rodapé
    printf("\n");
    imprimeRepeticao('*', tamanhoPadrao);
    printf("\n");
}

void imprimePick(Mcard *cardAtual) {
    printf("|| # %d\n", cardAtual->numeroNaColecao);
    printf("|\t%s - %s", cardAtual->mana, cardAtual->tipo);
    if (cardAtual->subtipo[0] != NULL && cardAtual->subtipo[0] != "")
        printf(" - %s", cardAtual->subtipo);
    
    printf("\n|");
    strRaridade(*cardAtual);
    printf(" - %s", cardAtual->nome);

    if(isCriatura(*cardAtual)) printf("\t%d/%d\t", cardAtual->poder, cardAtual->resistencia);
    else printf("\t   \t");    
}

Mcard *menuPick(Mcard *boosterAtual, int numBooster) {
    Mcard *cardAtual = boosterAtual;
    int escolhaUsuario;

    printf("\n");
    printf("# Booster: %d ", numBooster + 1);
    imprimeRepeticao('-', 40);
    printf("\n");

    while(cardAtual != NULL) {
        printf("\n");
        imprimePick(cardAtual);
        cardAtual = cardAtual->proximo;
        printf("\n");
    }

    printf("\n");
    imprimeRepeticao('*', TAMANHO_PADRAO);
    printf("\n\tQual carta você deseja escolher, como pick?\n");
    printf("\n\t(Digite o número da carta)\n");
    imprimeRepeticao('*', TAMANHO_PADRAO);
    printf("\n");
    
    printf("::: ");
    scanf("%d", &escolhaUsuario);

    return buscaCardPorId(boosterAtual, escolhaUsuario);
}

void menuDeck() {}

void menuMao() {}
#endif