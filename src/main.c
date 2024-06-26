#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<stdbool.h>

#include "lib/structCard.h"
#include "lib/manipulaLista.h"
#include "lib/menu.h"
#include "lib/draft.h"

char PATH_DB[40] = "../database/dbCards.csv";

Mcard *carregaBancoCsvEmLista() {
    FILE *fArquivoBanco;
    char linhaCsv[1024];
    int qtdCartas = 0;
    Mcard *novoCard, *colecao;

    fArquivoBanco = fopen(PATH_DB, "r");

    while(fgets(linhaCsv, 1024, fArquivoBanco) != NULL) {
        
        // Esse if pula o cabeçalho do arquivo csv (../database/dbCards.csv)
        if (qtdCartas == 0) {
            qtdCartas++;
            continue;
        }

        // 'if' que decide se a coleção já foi iniciada 
        if (qtdCartas == 1) colecao = alocaCardFromChar(linhaCsv, qtdCartas);
        else {
            novoCard = alocaCardFromChar(linhaCsv, qtdCartas);
            adicionaCardNoDeck(novoCard, colecao);
        }

        qtdCartas++;
    }
    fclose(fArquivoBanco);

    return colecao;
}

int main() {
    // Localiza o código no 'Portuguese' para usarmos caracteres especiais
    setlocale(LC_ALL, "Portuguese");

    int cont;
    char escolhaUsuario;
    Mcard *deck, novoCard, *colecao;
    Mbox *boosterBox = NULL;

    colecao = carregaBancoCsvEmLista();

    menuInicial(true, true);
    printf("\n::: ");

    scanf("%c", &escolhaUsuario);
    getchar();
    system("@cls||clear");

    while(true) {
        if (escolhaUsuario == NULL) {
            menuInicial(false, false);
            printf("\n::: ");

            scanf("%c", &escolhaUsuario);
            getchar();
        }

        switch (escolhaUsuario)
        {
            case '1':
                imprimeColecao(colecao, false);
                printf("\n\n\n");
                break;
            
            case '2':
                sistemaBusca(colecao);
                printf("\n\n\n");
                break;

            case '3':
                boosterBox = geraBoosters(colecao);
                iniciaDraft(boosterBox);
                fflush(stdin);
                break;

            case '0':
                printf("\n\n\n\t\tObrigado por usar o MagiC. Seu simulador de draft de código aberto!\n\n\n\n\n\n\n");
                exit(0);
            
            default:
                break;
        }

        escolhaUsuario = NULL;
    }


    return 0;
}