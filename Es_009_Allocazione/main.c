#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *car;
    int *x;

    car = (char *) malloc(sizeof(char));
    *car = 'a';
    printf("%c\n",*car);

    x = (int *) malloc(sizeof(int));
    *x = 5;
    printf("%d",*x);

    printf("\n");
    return 0;
}
