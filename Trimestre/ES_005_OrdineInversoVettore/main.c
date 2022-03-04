//made by Andrea Bosticardo
#include <stdio.h>
#include <stdlib.h>
int numero(){
    int n = 0;
    do{
    printf("insersci il numero di numeri:");
    scanf("%d",&n);
    }while(n < 0);
    return n;
}
void inserisci(int vett[],int n){//inserisco i numeri
    for(int i = 0; i < n; i++){
        printf("[%d] -->",i+1);
        scanf("%d",(vett+i));
    }
}
void scambia(int v[],int v1[],int n){//inverto i numeri
    for(int i = 0; i < n; i++){
    *(v1+i) = *(v+(n-i-1));
    }
}
int main()
{
    int n = numero();
    int *vett = (int*) malloc(n* sizeof(int));
    int *vett1 = (int*) malloc(n* sizeof(int));
    inserisci(vett,n);
    scambia(vett,vett1,n);//inverto il vettore

    for(int i = 0; i < n; i++){//stampo il vettore
        printf("%d ",*(vett+i));
    }
    printf("\n");
    for(int i = 0; i < n; i++){//stampo il vettore inverso
        printf("%d ",*(vett1+i));
    }

    printf("\n");
    system("pause");
    return 0;
}
