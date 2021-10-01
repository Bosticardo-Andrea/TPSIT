#include <stdio.h>
#include <stdlib.h>
#define DIM 5
void ordinaVettore(int vett[], int n){
    int sup, i, a;
    for(sup = n - 1; sup > 0; sup--){
        for(int k = 0; k < sup; k++){
            if(*(vett+k) > *(vett+ k+1)){
                a = *(vett+ k+1);
                *(vett+ k+1) = *(vett+k);
                *(vett+k) = a;
            }
        }
    }
}
void stampaVettore(int c[],int i) {
    int k;
    for(k = 0; k < i; k++) {
        printf("[%d] -> %d",k,c[k]);
    }
}
void caricaVettore(int v[],int n) {
    int k;
    for(k = 0; k < n; k++) {
        printf("inserire nella cella [%d] = ",k);
        scanf("%d",&v[k]);
    }
}
int main()
{
    int v[DIM];
    int n = DIM;

    caricaVettore(v,n);
    ordinaVettore(v,n);
    stampaVettore(v,n);

    printf("\n");
    system ("PAUSE");
    return 0;
}
