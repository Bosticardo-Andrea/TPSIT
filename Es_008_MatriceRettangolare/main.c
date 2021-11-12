#include <stdio.h>
#include <stdlib.h>

int main() {
    float **mat;
    float r,c;

    printf("Inserisci le righe: ");
    scanf("%f",&r);
    printf("Inserisci le colonne: ");
    scanf("%f",&c);

    mat = (float**) malloc(r*sizeof(float*));

    for(int i = 0; i<r; i++) {
            mat[i] = (float *) malloc(c*sizeof(float));
    }

    for(int i = 0; i < r; i++){
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
    }while(x > r || x < r);
    do{
    printf("y:");
    scanf("%d",&y);
    }while(y > c || y < c);
    printf("inserisci il numero:\nn: ");
    scanf("%d",&n);
    mat[x][y] = n;

    for(int i = 0; i < r; i++){
        for(int k = 0; k < c; k++){
            printf("%.2f ",mat[i][k]);
            }
            printf("\n");
    }

    free(mat);
    printf("\n");
    return 0;
}
