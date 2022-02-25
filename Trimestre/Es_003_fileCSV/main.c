#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 200

typedef struct {
    char nome[LUNG];
    char numero[LUNG];
    char tipo[LUNG];
    char anno[LUNG];
    char stato[LUNG];
} Film;
void leggi(char nome[], Film f[],int max, int *n) {
    //leggo il file e lo leggo
    //apertura in read
    int num = 0;
    FILE *fp;
    char riga[max];
    fp = fopen(nome,"r");
    if(fp == NULL) {
        printf("ERROR 404");
        *n = 0;
    } else {
        while(fgets(riga,max,fp) != NULL) { //leggo le rghe finché ce ne sono
            num = 0;
            spezza(riga, &num, f);//spezzo ogni riga
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
    //usando la funzione strtok spezzo la stringa
    token = strtok(riga, s);
    while( token != NULL ) {
        //printf( " %s\n", token );

        //strtok la prima volta gli passo la riga poi la seconda volta gli passo NULL cosí
        //conotinua a spezzettarla
        //se usassi i numeri e non tutte le strighe dovrei usare una stringa in intero
        //usando atoi(stringa con un  numero presente);
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
                strcpy(f[i].stato, token);
                printf("%s\n\n",f[i].stato);
            }
        i++;
        token = strtok(NULL, s);
    }

}
int nRighe(char nome[],int max){
    int num = 0;
    FILE *fp;
    char riga[max];
    fp = fopen(nome,"r");
    if(fp == NULL) {
        printf("ERROR 404");
        num = 0;
    } else {
        while(fgets(riga,max,fp)) {
            num++;
        }
        fclose(fp);
    }
    return num;
}
int main() {
    char nome[] = "file.txt";
    Film *f;
    int n = nRighe(nome,LUNG); //ricevo il numero di righe
    f = (Film*) malloc(n* sizeof(Film)); //inizializzo il vettore con la malloc
    //leggo il file
    leggi(nome,f,LUNG,&n);

    free(f);
    system("pause");
}
