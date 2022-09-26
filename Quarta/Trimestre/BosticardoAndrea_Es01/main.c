#include <stdio.h>
#include <stdlib.h>
//funzioni per ricevere in input i valori delle righe e dell colonne
int righe(){
    int n = 0;
    //controllo che siano maggiori di 0
    do{
        printf("Inserisci il numero di righe: ");
        scanf("%d",&n);
    }while(n <= 0);
    return n;
}
int colonne(){
    int n = 0;
    //controllo che siano maggiori di 0
    do{
        printf("Inserisci il numero di colonne: ");
        scanf("%d",&n);
    }while(n <= 0);
    return n;
}
int main()
{ //inizializzo le variabili
    float **mat;
    int r = righe(); //prendo le righe e le colonne
    int c = colonne();
    int nmax = 0;
    float *max;
    //alloco il vettore max
    max = (float *) malloc(c*sizeof(float));
    //alloco la matrice
    mat = (float**) malloc(r*sizeof(float*));
    for(int i = 0; i<r; i++) {
            mat[i] = (float *) malloc(c*sizeof(float));
    }
    //prendo i numeri di input
    for(int i = 0; i < r; i++){
        for(int k = 0; k < c; k++){
            printf("cella [%d] [%d] -->",i,k);
            scanf("%f",&mat[i][k]);
        }
    }
    //trovo il massimo con una variabile di appoggio
    for(int i = 0; i < r; i++){
        //metto sempre il primo numero della matrice nel max
            nmax = mat[i][0];
        for(int k = 0; k < c; k++){
            if(mat[i][k] > nmax){
                nmax = mat[i][k];
            }
        }
        *(max+i) = nmax; //lo inserisco nel vettore

    } //stampo la matrice
    printf("Matrice: \n");
    for(int i = 0; i < r; i++){
        for(int k = 0; k < c; k++){
            printf("cella [%d] [%d] --> %.2f",r,c,mat[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    //stampo l'array
    printf("Numeri maggiori per riga: ");
    for(int i = 0; i < r; i++){
        printf("%.2f - ",*(max+i));
    }
    //libero la memoria
    free(mat);
    free(max);
    printf("\n");
    system("pause");
    return 0;
}
