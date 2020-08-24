#include <stdio.h>

int main()
{
    int i, x;
    printf("Syötä ensimmäinen luku:\n");
    scanf("%d", &i);
    printf("Syötä toinen luku:\n");
    scanf("%d", &x);
    int remainder = i % x;

    (remainder == 0) ? printf("Jakojäännös on 0\n") : printf("Jakojäännös on %d\n", remainder);
    return 0;
}
