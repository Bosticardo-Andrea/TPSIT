//made by Andrea Bosticardo
#include <stdio.h>
#include <stdlib.h>

int main() {
    float **mat;//inizializzo la matrice
    float r,c;

    printf("Inserisci le righe: ");
    scanf("%f",&r);
    printf("Inserisci le colonne: ");
    scanf("%f",&c);

    mat = (float**) malloc(c*sizeof(float*)); // alloco la matrice (righe)

    for(int i = 0; i<r; i++) {// alloco la matrice (colonne)
            mat[i] = (float *) malloc(r*sizeof(float));
    }

    for(int i = 0; i < r; i++){//stampo la matrice
        for(int k = 0; k < c; k++){
            printf("%.2f ",mat[i][k]);
            }
            printf("\n");
    }

    int x,y;
    int n;
    do{
    printf("inserisci le coordinate:\nx: ");
    scanf("%d",&x);
    }while((x > c) || (x < c));

    do{
    printf("y:");
    scanf("%d",&y);
    }while((y > r) || (y < r));//controllo del numero inserito

    printf("inserisci il numero:\nn: ");
    scanf("%d",&n);
    mat[x][y] = n;//metto il numero

    for(int i = 0; i < r; i++){//stampo la matrice
        for(int k = 0; k < c; k++){
            printf("%.2f ",mat[i][k]);
            }
            printf("\n");
    }

    free(mat);
    printf("\n");
    return 0;
}
