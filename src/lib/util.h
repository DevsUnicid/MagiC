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

#endif