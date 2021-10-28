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
        if(*(str+i ) != ' ') {
                if(*(str+i ) != *(str + (n-i-1))){
                    ver = true;
                }
        }
        i++;
    }
    return ver;
}
void togliSpazio(char str[],char str1[],int *n,int m){
    for(int i = 0; i < m; i++){
       if(*(str+i) != ' '){
        *(str1+*n) = *(str+i);
        *n = *n+1;
     }
    }
}
int main() {
    char str[LUNG];
    char str1[LUNG];
    int n = 0;

    printf("Inserisci la stringa: ");
    gets(str);

    strlwr(str);
    togliSpazio(str,str1,&n,strlen(str));

    if(verifica(str1,n) == true) {
            printf("Non e' palindroma");
    }else{
        printf("E' palindroma");
    }

    printf("\n");
    return 0;
}
