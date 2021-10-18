#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 50
/*
Scrivere un programma che verifichi se la stringa data in input è palindroma o no.
Scrivere un programma che chieda n valori interi (massimo 100, li collochi in un vettore e inverta il vettore (scambiando il primo elemento con l’ultimo il secondo con il penultimo…). Si usino i puntatori
Scrivere un programma che data una stringa in input dica se la stessa contiene almeno una ‘A’ tra i primi 10 caratteri.
*/
bool verifica(char str[], int n) {
    bool ver = false;
    int i = 0;
    while(i < n && ver == false){
        if(str[i] != ' ') {
                if(str[i] != str[n-i-1]){
                    ver = true;
                }
        }
        i++;
    }
    return ver;
}
int main() {
    char str[LUNG];

    printf("Inserisci la stringa: ");
    scanf("%s",&str);
    if(verifica(str,strlen(puts)) == true) {
            printf("Non e' palindroma");
    }else{
        printf("E' palindroma");
    }

    printf("\n");
    return 0;
}
