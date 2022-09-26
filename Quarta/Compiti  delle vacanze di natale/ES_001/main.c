//Es01
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct
{
    int dim;
    int array[MAX];
} Stack;

Stack CreaStack()
{
    Stack pila;
    pila.dim = 0;
    return pila;
}
Stack inverti(Stack pila)
{
    int n = pila.dim;
    Stack pilaA = CreaStack();
    for(int i = 0; i < n; i++){
        push(&pilaA,pop(&pila));
    }
    return pilaA;
}
bool IsEmpty(Stack *stack)
{
    return stack->dim==0;
}

bool IsFull(Stack *stack)
{
    return stack->dim==MAX;
}

void push(Stack *stack, int x)
{
    stack ->array[stack->dim] = x;
    stack->dim++;
}
int pop(Stack *stack)
{
    int k = stack->array[stack->dim-1];
    stack->dim--;
    return k;
}
void stampa(Stack pila)
{
    printf("Risultato:");
    for(int i = 0; i < pila.dim; i++)
    {
        printf("%d ",pila.array[i]);
    }
}
int main()
{
    int n = 0;
    int num = 0;
    Stack pila = CreaStack();
    Stack pilaP = CreaStack();
    Stack pilaD = CreaStack();
    do
    {
        printf("Inserisci il numero di numeri: ");
        scanf("%d",&n);
    }
    while(n < 0 | n > MAX);

    for(int i = 0; i < n; i++)
    {
        printf("Inserisci il %d numero: ",i+1);
        scanf("%d",&num);
        if(num % 2 == 0)
        {
            push(&pilaP,num);
        }
        else
        {
            push(&pilaD,num);
        }
    }
    pilaP = inverti(pilaP);
    //stampa(pilaP);
    pilaD = inverti(pilaD);
    for(int i = 0; i < n; i++)
    {
        if(IsEmpty(&pilaP)== false)
        {
            push(&pila,pop(&pilaP));
        }
        else if(IsEmpty(&pilaD)== false)
        {
            push(&pila,pop(&pilaD));
        }
    }
    stampa(pila);
    return 0;
}
