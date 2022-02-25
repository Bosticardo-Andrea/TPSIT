#include <stdio.h>
#include <stdlib.h>

int cercaV(int *v, int x,int n){
    int tro = 0;
    for(int i=0; i < n; i++){
        if(*(v+i) == x){
            tro++;
        }
    }
    return tro;
}
int main()
{
    int n = 0;
    printf("inserisci il numero di numeri: ");
    scanf("%d",&n);
    int *v = (int) malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        printf("%d: ",i+1);
        scanf("%d",(v+i));
    }
    int somma = 0;
    int tro = 0;
    for(int i = 0; i < n; i++){
        tro = cercaV(v,*(v+i),n);
        if(tro <= 1){
            somma += *(v+i);
        }else {
         printf("%d - ",*(v+i));
    }
    }
    printf("\nSomma dei valori non ripetuti: %d",somma);
    printf("\n");
    return 0;
}
