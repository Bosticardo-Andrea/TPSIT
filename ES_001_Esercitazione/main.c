#include <stdio.h>
#include <stdlib.h>
#define DIM 20
#define MAX_STD 10
/*
si scriva un programma che definisca un tipo studente. Ogni studente ha un nome un cognome e una matricola
il programma deve aquisire i dati di 10 studenti e per ognuno deve fare un inserimento ordinato.
(lo scopo e quello di ordinare gli studenti durante il processo di inserimento e non dopo)
*/
typedef struct{
    char nome[DIM];
    char cognome[DIM];
    int matricola;
} Studente;
void leggi(Studente s[], int n){
    for(int i = 0; i < n; i++){
        printf("Inserisci il nome: ");
        scanf("%s",s[i].nome);
        printf("Inserisci il cognome: ");
        scanf("%s",s[i].cognome);
        do{
        printf("Inserisci il numero di matricola: ");
        scanf("%d",&s[i].matricola);
        }while(s[i].matricola < 0);
    }
}
int dimensione(int max){
    int n = 0;
    do{
        printf("quanti studenti vuoi inserire? ");
        scanf("%d", &n);
    }while(n < 0 && n > max);
    return n;
}
void stampa(Studente s[], int n){
    for(int i = 0; i < n; i++){
        printf("%s %s %d\n",s[i].cognome,s[i].nome,s[i].matricola);

    }
}
int main()
{
    int n = 0;
    Studente s[DIM/2];
    n = dimensione(MAX_STD);
    leggi(s,n);
    stampa(s,n);

    printf("\n");
    system("PAUSE");
    return 0;
}
