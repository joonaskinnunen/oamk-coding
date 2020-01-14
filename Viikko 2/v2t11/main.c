#include <stdio.h>

int main()
{
    int i;
    printf("Syötä kokonaisluku\n");
    scanf("%d", &i);
    (i == 0) ? printf("Luku on nolla\n") : (i > 0) ? printf("Luku on positiivinen\n") : printf("Luku on negatiivinen\n");
    return 0;
}
