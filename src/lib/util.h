#ifndef _UTIL_H
#define _UTIL_H

#include<string.h>
#include<ctype.h>

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
#endif