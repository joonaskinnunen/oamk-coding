#include <stdio.h>

int main()
{
    int x, y;
    printf("Syötä ensimmäinen luku: ");
    scanf("%d", &x);
    printf("Syötä toinen luku: ");
    scanf("%d", &y);
    (x > y) ? printf("%d\n%d\n", x, y) : printf("%d\n%d\n", y, x);
    return 0;
}
