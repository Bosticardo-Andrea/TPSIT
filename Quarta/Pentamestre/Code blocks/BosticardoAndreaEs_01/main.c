/*
Bosticardo Andrea 4^Arob

Implementare l’inserimento di numeri interi in una
pila senza duplicati: se un valore è già presente nella pila non deve essere
inserito nuovamente. Stampare la pila al termine degli inserimenti e restituire
la media dei numeri stampati.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct{
    int dim;
    int array[MAX];
} Stack;
Stack CreaStack(){//restituisce uno stack(pila) e inizializza la dimensione della pila a 0 perché non sono presenti numeri
    Stack pila;
    pila.dim = 0;
    return pila;
}
bool IsEmpty(Stack *stack){//controlla se la pila sia vuota
    return stack->dim==0;
}
bool IsFull(Stack *stack){
    return stack->dim==MAX;//controlla se la pila sia vuota
}
void push(Stack *stack, int x){//funzione push = inserimento numeri
    if(IsFull(stack) != true){//controlla se la pila sia piena
    stack ->array[stack->dim] = x;//mette il numero nell;ultima posizione = aggiunge al fondo il numero
    stack->dim++;//aumenta la dimensione
    }else{
        printf("Pila piena");
    }
}
int pop(Stack *stack){//funzione push = rimuove l'ultimo numero
    int k = 0;
    if(IsEmpty(stack) != true){//controlla se la pila sia vuota
    int k = stack->array[stack->dim-1];//toglie l'ultimo elemento della pila
    stack->array[stack->dim-1] = NULL;
    stack->dim--;//diminuiscce la dimensione
    }else{
        printf("Pila vuota");
        k = NULL;
    }
    return k;
}
void stampa(Stack pila){//stampa i numeri
    printf("Numeri pari: ");
    for(int i = 0; i < pila.dim; i++)
    {
        printf("%d ",pila.array[i]);
    }
}
bool giaInserito(Stack pila,int num){
    if(IsEmpty(&pila)){
        return false
    }else{
        int n = 0;
        int tro = -1;
        while(n < pila.dim && tro == -1){
            if(num == pila.array[n]){
                tro == 0
            }
        }
        return (tro == -1)
    }
}
Stack Inserisci(){
    int n = 0;
    int num = 0;
    Stack pila = CreaStack();
    do{//controlla che il numero di numeri che si vuole inserire sia corretto = non negativo
        printf("Inserisci il numero di numeri: ");
        scanf("%d",&n);
    }while(n < 0 | n > MAX);
    for(int i = 0; i < n; i++)//inserisce i numeri
    {
        printf("Inserisci il %d numero: ",i+1);
        scanf("%d",&num);
        if(!giaInserito(pila,num)){
        printf("Numero gia' inserito");
        }
        else{
        push(&pila,num);
        }
    }
    return pila;
}
int main(){
    Stack pila = Inserisci();
    stampa(pila);//stampa la pila
    int k = pop(&pila);
    return 0;
}
