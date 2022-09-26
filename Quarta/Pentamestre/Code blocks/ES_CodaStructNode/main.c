#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct coda //creo una struttura coda
{
    int el;
    struct coda*next;
} Coda;
bool is_empty(Coda **head){//funzione che controlla se la coda é vuota
    return head==NULL;
}
void enqueue(Coda ** tail,Coda** head, int num) {
    Coda * h= *head;
    Coda * t= *tail;
    if(t!=NULL && h!=NULL) {
        t->next=(Coda*)malloc(sizeof(Coda));
        t=t->next;
        t->el=num;
        t->next=NULL;
    } else {
        t=(Coda*)malloc(sizeof(Coda));
        h=t;
        t->el=num;
        t->next=NULL;
    }
    *head=h;
    *tail=t;
}
int dequeue(Coda**head,Coda**tail){//toglie il primo elemento della che si é inserito (la head)
    int dato = NULL;
    if(is_empty(*head)){//controllo che la coda non sia vuota
         printf("Coda vuota\n");
    }else{
        dato = (*head)->el;//salvo il dato della head
        *head= (*head)->next;//sposto la head al elemento successivo
    }
     return dato;//restituisco il dato
}
void stampaCoda(Coda *h) {
    if(h!=NULL) {
        printf("%d\n",h->el);
        stampaCoda(h->next);
    }
}
Coda * CreaCoda(Coda** tail) {
    int n;
    printf("inserisci il numero di numeri ");
    scanf("%d", &n);
    int num;
    Coda * head=NULL;
    Coda *r=(Coda*)malloc(sizeof(Coda));
    Coda * cur=head;
    for(int k=0; k< n; k++) {
        printf("inserisci un numero:  ");
        scanf("%d", &num);
        if(r==NULL)
            r=(Coda*)malloc(sizeof(Coda));
        r->el=num;
        if(head==NULL) {
            head= r;
            cur=r;
        }
        cur->next=r;
        cur=r;
        cur->next=NULL;
        r=NULL;
    }
    *tail=cur;
    return head;
}
int main()
{
    Coda*head=NULL;//istanzio una struttura denominata testa
    Coda*tail=NULL;//istanzio una coda denominata coda (fine della coda)
    Coda*dato=NULL;//istanzio una coda denominata coda (fine della coda)
    //int dato=0;
    bool ok = true;
    int scelta=0;
    while(ok)
    {
        printf("\nMENU'\n-scegli '1' per inserire elementi nella coda\n-scegli '2' togliere un elemento dalla coda\n-scegli '3' per uscire dal programma\nInserire numero:");
        scanf("%d",&scelta);

    switch(scelta)

    {
    case 1:
        head=CreaCoda(&tail);
        break;

    case 2:
        printf("Elemento tolto:\t %d",dequeue(&head,&tail));
        //stampaCoda(head);
        printf("\n");
        break;

    case 3:
        printf("EXIT..");
        ok=false;
        break;

    default:
        printf("[carattere inserito non valido]\n");
        break;
    }

}
return 0;
}
