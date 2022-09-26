//made by Andrea Bosticardo
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{
    int dim;
    int head;
    int num[MAX];
}Coda;
Coda CreaCoda(){//creo la cosa
    Coda coda;
    coda.dim = 0;
    coda.head = 0;
    return coda;
}
void enqueue(Coda *coda, int x){//funzione enqueue
    coda->num[coda->dim] = x;
    coda->dim++;
}
int dequeue(Coda *coda){//funzoine dequeue
    int num[MAX];
    int k = NULL;
    if (coda->dim == coda->head && coda->dim == 0){
        printf("Errore coda vuota");
    }else{
        k = coda->num[coda->head];
        coda->dim--;
        coda->head++;
    }
    return k;
}
Coda inverti(Coda coda){//inverto la coda
    Coda coda1 = CreaCoda();
    int n = coda.dim;
    int vettore[coda.dim];//uso un vettore di appoggio
    for(int i = 0; i < n; i++){
            if( i >= coda.head){
                vettore[i] = dequeue(&coda);
            }
    }
    for(int i = n-1; i >= 0; i--){//inserisco tutto dentro il vettore
        enqueue(&coda1,vettore[i]);
    }
    return coda1;
}
void stampaCoda(Coda coda){//stampo la coda
    int n = coda.dim;
    for (int i = 0; i < n ; i ++){
            if( i >= coda.head){
                printf("%d-",coda.num[i]);
            }
    }
    printf("\n");
}
int main()
{
    Coda coda = CreaCoda();

    int n = 0;
    int num = 0;
    do{
        printf("inserici il numero di numeri: ");
        scanf("%d",&n);
    }while(n < 0 || n > MAX);

    for(int i = 0; i < n; i++){
        printf("Inserisci il %d numero: ", i+1);
        scanf("%d",&num);
        enqueue(&coda,num);
    }
    stampaCoda(coda);
    coda = inverti(coda);//inverto la coda
    int x = dequeue(&coda); // salvo l'ultimo numero
    stampaCoda(coda);//stampo la coda
    coda = inverti(coda);//inverto nuovamente la coda
    int y = dequeue(&coda);//salvo l'ultimo numero
    stampaCoda(coda);//stampo la cosa
    printf("\nElemento rimosso come se fosse una pila: %d",x);//mostro gli elementi rimossi
    printf("\nElemento rimosso come un normale coda: %d",y);
    return 0;
}
