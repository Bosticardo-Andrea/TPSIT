#include <stdio.h>
#include <stdlib.h>

int main() {
    //inizializzo le variabili
    float *vett;
    int n = 0;
    int k = 0;
    //creo una stringa per il nome del file
    char file[] = "verifica.dat";

    //creo un puntatore al file
    FILE *fp;
    //apro il file in lettura
    fp = fopen(file,"r");
    //controllo la sua esistenza
    if(fp == NULL) {
            //se non esiste lo segnalo
        printf("File inesistente: ERROR 404");
    } else {
        //leggo la prima per sapere la sua dimensione
        fscanf(fp,"%d",&n);
    //lo alloco dinamicamente
        vett = (float *) malloc(n*sizeof(float));
        //leggo il resto del file e lo assegno alla cella del vettore corrispondente
        while(k < n && fscanf(fp,"%f",(vett+k)) != NULL) {
            k++;
        }
        //stampo l'array
        printf("Array: \n");
        for(int i = 0; i < n; i++)
            printf("%.2f - ",*(vett+i));
    }

    free(vett);
    fclose(fp);
    printf("\n");
    system("pause");
    return 0;
}
