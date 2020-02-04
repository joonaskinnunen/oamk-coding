#include <stdio.h>

int main()
{
    float x;
    float y;
    printf("Syötä ensimmäinen luku: ");
    scanf("%f", &x);
    printf("Syötä toinen luku: ");
    scanf("%f", &y);
    printf("Yhteensä: %f\n", x + y);
    return 0;
}
