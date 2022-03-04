//made by Andrea Bosticardo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 100
int main()
{
    char str1[LUNG];
    char str2[LUNG];
    int n =0;
    //prendo le due stringhe
    printf("inserisci la prima stringa: ");
    gets(str1);
    printf("inserisci la seconda stringa: ");
    gets(str2);

    //sommo la lughezza e aggiungo 2 (caratteri di fine stringa + spazio)
    n = strlen(str1) + strlen(str2) + 2;
    char *str3 = (char*) malloc(n+sizeof(char)); //alloco la stringa finale
    strcpy(str3,str1);//copo la prima stringa nella seconda
    int j = strlen(str3);
    int i = 0;
    n = strlen(str2);
    *(str3 + j++) = ' '; //aggiungo lo spazio
    for(i = 0; i < n; i++){
        * (str3 + j++) = *(str2 +i);
     }
     *(str3 +j) = '\0';//aggiungo il fine stringa
     puts(str3);
     free(str3);

    printf("\n");
    return 0;
}
