#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *car;
    int *x;

    car = (char *) malloc(1*sizeof(char));
    *car = 'a';
    printf("%c\n",*car);

    car = (int *) malloc(1*sizeof(int));
    *x = 5;
    printf("%d",*x);

    printf("\n");
    return 0;
}
