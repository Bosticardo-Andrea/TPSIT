//Es02
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>
#define MAX 100
typedef struct
{
    int dim;
    char parola[MAX];
} Stack;

Stack CreaStack()
{
    Stack pila;
    pila.dim = 0;
    return pila;
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
    stack->parola[stack->dim] = x;
    stack->dim++;
}
int pop(Stack *stack)
{
    int k = stack->parola[stack->dim-1];
    stack->dim--;
    return k;
}
Stack inverti(Stack pila){
    int n = pila.dim;
    Stack pilaA = CreaStack();
    for(int i = 0; i < n; i++){
        push(&pilaA,pop(&pila));
    }
    return pilaA;
}
int main()
{
    Stack frase = CreaStack();
    char parola[100];
    printf("Inserisci una Stringa: ");
    gets(parola);

    for(int i = 0; i < strlen(parola); i++){
            push(&frase,parola[i]);
    }
    frase = inverti(frase);
    puts(frase.parola);

    return 0;
}
