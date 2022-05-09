/*programma che chieda all’utente una stringa composta da parentesi aperte e chiuse:
(,),[,],{,} e che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
*/
#include <stdio.h>
#include <string.h>

int MAXSIZE = 50;
int stack[50];
int top = -1;

// Controllo se stack vuoto
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

// Controllo se stack pieno
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

// Prelievo utimo elemento inserito
char peek(){
   return stack[top];
}

// Prelievo dati dallo stack
char pop(char data) {

   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("Impossibile prelevare dato, Stack vuoto.\n");
   }
}

// Inserimento dati nello stack
void push(char data) {

   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("Impossibile inserire dati, Stack Pieno.\n");
   }
}

// Controllo espressione
int checkEspressione(char* espressione){

   char c;

   //Lettura singolo carattere da espressione
   for(int i = 0; espressione[i]!='\0'; i++)
   {
      c = espressione[i];

      //Inserimento dei soli simboli di parentesi nello stack
      if(c == '(')
            push(c);
      else if(c == '[')
            push(c);
      else if(c == '{')
            push(c);
      // Controllo che esista la chiusura per ( se inserito
      else if(c == ')')
         if(isempty())
            return 0;
         else if(peek() == '(')
            pop(c);
         else
            return 0;
      // Controllo che esista la chiusura per [ se inserito
      else if(c == ']')
         if(isempty())
            return 0;
         else if(peek() == '[')
            pop(c);
         else
            return 0;
      // Controllo che esista la chiusura per { se inserito
      else if(c == '}')
         if(isempty())
            return 0;
         else if(peek() == '{')
            pop(c);
         else
            return 0;
   }

   //Se espressione corretta lo stack è vuoto
   return isempty();

}


void main() {

   char espressione[1000]; //stringa da verificare

   printf("Inserire la serie di parentesi:\n");
   scanf("%s" , espressione);

   int result = checkEspressione(espressione); // Controllo espressione

   if(result == 0) // Verifica risultato
      printf("Espressione errata");
   else
      printf("Espressione corretta");

   return;
}
