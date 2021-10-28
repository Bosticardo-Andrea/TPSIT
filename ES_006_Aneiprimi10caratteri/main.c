#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 100
bool trova(char str[],int n,char c){
    int k = 0;
    bool ok = false;
    while(k < n && ok == false){
            if(*(str + k)== 'A'){
                ok = true;
            }
                k++;

    }
    return ok;
}
int main()
{
    char str[LUNG];
    printf("Inserisci la stringa: ");
    gets(str);

    if(trova(str,10,'A')){
        printf("E' presente una A");
    }else{
        printf("Non e' presente una A");
    }
    printf("\n");
    system("pause");
    return 0;
}
