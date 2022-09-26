//Es03
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20
typedef struct
{
    char nome[256] ;
    char cognome[256] ;
    int matricola;
    int pressione[2]; // minima e massima
    int temperature[3]; // temperature della mattina e pomeriggio e sera
    float parcella; // in euro quello che deve al dottore
} Paziente;
void stampa(int n, Paziente clinica[]);
void inserimento(int *num, Paziente clinica[]);
void saldo(int n, Paziente clinica[]);
int main()
{
    int n = 0;
    Paziente rossi;
    Paziente clinica[MAX];
    inserimento(&n,clinica);
    stampa(n,clinica);
    saldo(n,clinica);
    printf("\n");
    return 0;
}
void inserimento(int *num, Paziente clinica[]){
    char nome[256];
    char cognome[256];
    int x = 0;
    do{
        printf("Inserisci il numero di pazienti che vuoi inserire: ");
        scanf("%d",&x);
    }while(x <= 0 | x > MAX);
    for(int i = 0; i < x; i++){
        fflush(stdin);
        printf("inserisci il nome: ");
        scanf("%s",&nome);
        strcpy(clinica[i].nome,nome);
        fflush(stdin);
        printf("inserisci il cognome: ");
        scanf("%s",&cognome);
        strcpy(clinica[i].cognome,cognome);
        fflush(stdin);
        printf("inserisci numero matricola: ");
        scanf("%d",&clinica[i].matricola);
        printf("Inserisci la pressione minima:");
        scanf("%d",&clinica[i].pressione[0]);
        printf("Inserisci la pressione massima:");
        scanf("%d",&clinica[i].pressione[1]);
        printf("Inserisci la temperatura del mattino:");
        scanf("%d",&clinica[i].temperature[0]);
        printf("Inserisci la temperatura del pomeriggio:");
        scanf("%d",&clinica[i].temperature[1]);
        printf("Inserisci la temperatura del sera:");
        scanf("%d",&clinica[i].temperature[2]);
        printf("Inserisci la parcella:");
        scanf("%f",&clinica[i].parcella);
    }
    *num = x;
}
void saldo(int n, Paziente clinica[]){
    float guadagno = 0;
    for(int i = 0; i < n; i++){
        guadagno += clinica[i].parcella;
    }
    printf("Guadagno totale della clinica: %.2f",guadagno);
}
void stampa(int n, Paziente clinica[]){
    for(int i = 0; i < n; i++){
        printf("Valori del signor %s %s:\n",clinica[i].cognome,clinica[i].nome);
        printf("Temperatura: \n  -mattino:%d\n  -pomeriggio:%d\n  -sera:%d",clinica[i].temperature[0],clinica[i].temperature[1],clinica[i].temperature[2]);
        printf("\nPressione: \n  -minima:%d\n  -massima:%d\n",clinica[i].pressione[0],clinica[i].pressione[1]);
    }
}
