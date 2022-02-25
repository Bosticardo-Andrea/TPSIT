#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct{//struttura coda
    int dim;
    int head;
    int num[MAX];
}Coda;
typedef struct{////struttura pila
    int dim;
    int num[MAX];
} Stack;

Stack CreaStack(){//creo una pila
    Stack pila;
    pila.dim = 0;
    return pila;
}
Coda CreaCoda(){//creo una coda
    Coda coda;
    coda.dim = 0;
    coda.head = 0;
    return coda;
}
void push(Stack *stack, int x){//funzione push
    stack->num[stack->dim] = x;
    stack->dim++;
}
void enqueue(Coda *coda, int x){//funzoine enqueue
    coda->num[coda->dim] = x;
    coda->dim++;
}
int pop(Stack *stack){//funzione pop
    int k = stack->num[stack->dim-1];
    stack->dim--;
    return k;
}
int dequeue(Coda *coda){//funzione dequeeu
    int num[MAX];
    int k = coda->num[coda->head];
    if (coda->dim == coda->head){
        printf("Errore");
    }else{
        coda->dim--;
        coda->head++;
    }
    return k;
}
int main(){//main
    //creo  la pila e la coda
    Stack stack = CreaStack();
    Coda coda = CreaCoda();
    int n = 0;
    //controllo l'inserimento della grandezza
    do{
        printf("inserici il numero di numeri: ");
        scanf("%d",&n);
    }while(n < 0 || n > MAX);
    int num = 0;
    //faccio inserire i numeri
    for (int i = 0; i < n; i++){
        printf("Inserisci il %d numero: ",i+1);
        scanf("%d",&num);
        enqueue(&coda,num);
    }
    //stampo la coda
    for (int i = 0; i < n; i++){
       printf("%d",coda.num[i]);
    }
    //metto nella pila gli elementi della coda
    printf("\n");
    for (int i = 0; i < n; i++){
       push(&stack,dequeue(&coda));
    }
    //riporto nella coda gli elementi della pila
    for (int i = 0; i < n; i++){
       enqueue(&coda,pop(&stack));
    }
    //stampo la coda
    for (int i = 0; i < n; i++){
       printf("%d",coda.num[i]);
    }
    return 0;
}
