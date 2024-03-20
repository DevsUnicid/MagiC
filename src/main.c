#include<stdio.h>
#include<string.h>
#include<locale.h>

#include "lib/structCard.h"
#include "lib/manipulaLista.h"

char PATH_DB[40] = "../database/dbCards.csv";

struct mCard *carregaBancoCsvEmLista() {
    FILE *fArquivoBanco;
    char linhaCsv[1024];
    int qtdCartas = 0;
    struct mCard *novoCard, *colecao;

    fArquivoBanco = fopen(PATH_DB, "r");

    while(fgets(linhaCsv, 1024, fArquivoBanco) != NULL) {
        
        // Esse if pula o cabeçalho do arquivo csv (../database/dbCards.csv)
        if (qtdCartas == 0) {
            qtdCartas++;
            continue;
        }

        // 'if' que decide se a coleção já foi iniciada 
        if (qtdCartas == 1) colecao = alocaCardFromChar(linhaCsv);
        else {
            novoCard = alocaCardFromChar(linhaCsv);
            adicionaCardNoDeck(novoCard, colecao);
        }

        qtdCartas++;
    }

    imprimeColecao(colecao);

    fclose(fArquivoBanco);

    return novoCard;
}

int main() {

    // Localiza o código no 'Portuguese' para usarmos caracteres especiais
    setlocale(LC_ALL, "Portuguese");

    int cont;
    struct mCard *deck, novoCard, colecao;

    deck = carregaBancoCsvEmLista();


    return 0;
}