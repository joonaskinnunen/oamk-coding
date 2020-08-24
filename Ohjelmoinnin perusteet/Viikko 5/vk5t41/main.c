#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
    char doubleArr[SIZE], intArr[SIZE];
    int i;
    double d;

    printf("Syota kokonaisluku: ");
    scanf("%s", intArr);
    printf("Syota desimaaliluku: ");
    scanf("%s", doubleArr);

    i = atoi(intArr);
    d = atof(doubleArr);

    printf("Lukujen summa on %.2lf\n", i + d);
    return 0;
}

