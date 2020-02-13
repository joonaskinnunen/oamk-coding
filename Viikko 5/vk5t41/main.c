#include <stdio.h>
#include <stdlib.h>

int main()
{
    char doubleArr[10], intArr[10];
    int i;
    double d;

    printf("Syota kokonaisluku: ");
    scanf("%d", &i);
    printf("Syota desimaaliluku: ");
    scanf("%lf", &d);
    sprintf(doubleArr, "%0.2lf", d);
    sprintf(intArr, "%d", i);

    i = atoi(intArr);
    d = atof(doubleArr);

    printf("Lukujen summa on %.2lf", i + d);
    return 0;
}
