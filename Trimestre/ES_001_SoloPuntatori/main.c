//made by Andrea Bosticardo
#include <stdio.h>
#include <stdlib.h>
#define DIM 5
/*

* == valore
& == indirizzo

*/
void ordinaVettore(int vett[], int n) {//ordino il vettore con un bubblesort
    int sup, i, a;
    for(sup = n - 1; sup > 0; sup--) {
        for(int k = 0; k < sup; k++) {
            if(*(vett+k) > *(vett+ k+1)) {
                a = *(vett+k+1);
                *(vett+k+1) = *(vett+k);
                *(vett+k) = a;
            }
        }
    }
}
void stampaVettore(int c[],int i) {//stampo il vettore
    int k;
    for(k = 0; k < i; k++) {
        printf("[%d] -> %d\n",k,*(c+k));
    }
}
void caricaVettore(int v[],int n) {//carico il vettore
    int k;
    for(k = 0; k < n; k++) {
        printf("inserire nella cella [%d] = ",k);
        scanf("%d",v+k);
    }
}
int main() {
    int v[DIM];
    int n = DIM;

    caricaVettore(v,n);
    ordinaVettore(v,n);//ordino il vettore
    printf("vettore ordinato:\n");
    stampaVettore(v,n);//stampo il vettore

    printf("\n");
    system ("PAUSE");
    return 0;
}
