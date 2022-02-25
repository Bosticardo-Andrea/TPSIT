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
    int mi,minf,mm;
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
void media(Studente s[], int ni, int inf, int mat,int n) {
    int sm,si,sinf;
    sm = 0;
    si = 0;
    sinf = 0;
    for(int k = 0; k < 0; k++) {
        s[k].mi = 1;
        s[k].minf = 1;
        s[k].mm = 1;
        for(int i = 0; i < ni; i ++) {
            si = si + s[k].ita;
        }
        for(int j = 0; j < inf; j ++) {
            sinf = sinf + s[k].info;
        }
        for(int f = 0; f < mat; f ++) {
            sm = sm + s[k].mate;
        }
        s[k].mi = sm/mat;
        s[k].minf = sm/inf;
        s[k].mm = sm/ni;
    }
}
void stampa(Studente s[], int n) {
    for(int i = 0; i < n; i++) {
        if(s[i].mi > s[i].minf) {
            if(s[i].mi > s[i].mm){
            printf("Lo studente %s ha la media alta in Italiano",s[i].nome);
            }else if(s[i].minf > s[i].mm){
                printf("Lo studente %s ha la media alta in Informatica",s[i].nome);
            }
            }else{
                printf("Lo studente %s ha la media alta in mate",s[i].nome);
            }
    }
}
int main() {
    Studente s[DIM/2];
    int n = 0;
    int ni,ninf,nm;
    ni = 0;
    ninf = 0;
    nm = 0;

    n = dimensione(MAX_STD);
    leggi(s,n,&ni,&ninf,&nm);
    media(s,ni,ninf,nm,n);
    stampa(s,n);

    printf("\n");
    system("PAUSE");
    return 0;
}
