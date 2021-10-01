#include <stdio.h>
#include <stdlib.h>
#define DIM 20
#define MAX_STD 10
/*
Definire una struttura per memorizzare i dati degli studenti di una calsse e dei voti nelle varie discipline:
Italiano, Matematica, e Informatica.
Si scriva una funzione in C che, a partire da un vettore di studenti fornito come argomento,
 determina la disciplina che ha la media piu alta.
*/
typedef struct {
    char nome [DIM];
    int ita[MAX_STD/5];
    int mate[MAX_STD/5];
    int info[MAX_STD/5];
} Studente;

void leggi(Studente s[], int n, int *it, int *inf, int *m) {
    int num = 0;
    for(int i = 0; i < n; i++) {
        printf("Inserisci il nome: ");
        scanf("%s",s[i].nome);

        printf("Inserisci quanti voti per ita: ");
        scanf("%d",&num);
        for(int k = 0; k < num; k++) {
        do {
            printf("Inserisci il voto: ");
            scanf("%d",&s[i].ita[k]);
        } while(s[i].ita[k] < 0);
    }
    *it = num;
    printf("Inserisci quanti voti per mate: ");
        scanf("%d",&num);
        for(int k = 0; k < num; k++) {
        do {
            printf("Inserisci il voto: ");
            scanf("%d",&s[i].ita[k]);
        } while(s[i].ita[k] < 0);
    }
    *m = num;
    printf("Inserisci quanti voti per info: ");
        scanf("%d",&num);
        for(int k = 0; k < num; k++) {
        do {
            printf("Inserisci il voto: ");
            scanf("%d",&s[i].ita[k]);
        } while(s[i].ita[k] < 0);
    }
    }
    *inf = num;
}
int dimensione(int max) {
    int n = 0;
    do {
        printf("quanti studenti vuoi inserire? ");
        scanf("%d", &n);
    } while(n < 0 && n > max);
    return n;
}
void media(int *mi, int *minf, int *mm,Studente s[], int ni, int inf, int m,int n){
    int sm,si,sinf;
    sm = 0;
    si = 0;
    sinf = 0;
}

int main() {
    int n = 0;
    int ni,ninf,nm;
    int mi,minf,mm;
    ni = 0;
    ninf = 0;
    nm = 0;
    mi = 1;
    minf = 1;
    mm = 1;
    Studente s[DIM/2];
    n = dimensione(MAX_STD);
    leggi(s,n,&ni,&ninf,&nm);
    media(&mi,&minf,&mm,s,ni,ninf,nm,n);
    //stampa(s,n);

    printf("\n");
    system("PAUSE");
    return 0;
}
