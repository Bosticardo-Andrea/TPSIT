#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 200

typedef struct {
    char nome[LUNG];
    char numero[LUNG];
    char tipo[LUNG];
    char anno[LUNG];
    char presente[LUNG];
} Film;
void leggi(char nome[], Film f[],int max, int *n) {
    int num = 0;
    FILE *fp;
    char riga[max];
    fp = fopen(nome,"r");
    if(fp == NULL) {
        printf("ERROR 404");
        *n = 0;
    } else {
        while(fgets(riga,max,fp) != NULL) {
            num = 0;
            spezza(riga, &num, f);
            *n = *n + 1;
        }
        fclose(fp);
    }
}
void spezza(char riga[LUNG], int *num, Film f[]) {
    int n = *num;
    int i = 0;
    char s[2] = ",";
    char *token;
    token = strtok(riga, s);
    while( token != NULL ) {
        //printf( " %s\n", token );
            if(i == 0) {
                strcpy(f[i].numero,token);
                printf("%s. ",f[i].numero);
            } else if (i == 1) {
                strcpy(f[i].nome,token);
                printf("%s\n",f[i].nome);
            } else if (i == 2) {
                strcpy(f[i].tipo,token);
                printf("%s\n",f[i].tipo);
            } else if (i == 3) {
                strcpy(f[i].anno,token);
               printf("%s\n",f[i].anno);
            } else if (i == 4) {
                strcpy(f[i].presente, token);
                printf("%s\n\n",f[i].presente);
            }
        i++;
        token = strtok(NULL, s);
    }

}
int main() {
    Film f[LUNG];
    int n = 0;
    char nome[] = "file.txt";
    leggi(nome,f,LUNG,&n);
    system("pause");
}
