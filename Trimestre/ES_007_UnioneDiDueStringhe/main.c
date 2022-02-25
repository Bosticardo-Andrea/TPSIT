#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 100
int main()
{
    char str1[LUNG];
    char str2[LUNG];
    int n =7 0;

    printf("inserisci la prima stringa: ");
    gets(str1);
    printf("inserisci la seconda stringa: ");
    gets(str2);

    n = strlen(str1) + strlen(str2) + 2;
    char *str3 = (char*) malloc(n+sizeof(char));
    strcpy(str3,str1);





    int j = strlen(str3);
    int i = 0;
    n = strlen(str2);
    *(str3 + j++) = ' ';
    for(i = 0; i < n; i++){
        * (str3 + j++) = *(str2 +i);
     }
     *(str3 +j) = '\0';
     puts(str3);
     free(str3);

    printf("\n");
    return 0;
}
