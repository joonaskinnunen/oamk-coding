#include <stdio.h>

int askInt() {
    int num;
    printf("Syötä kokonaisluku: ");
    scanf("%d", &num);
    return num;
}

float askFloat() {
    float num;
    printf("Syötä desimaaliluku: ");
    scanf("%f", &num);
    return num;
}

int main()
{
    int intToPrint = askInt();
    float floatToPrint = askFloat();
    printf("Syötit kokonaisluvun: %d\n", intToPrint);
    printf("Syötit desimaaliluvun: %f\n", floatToPrint);
    return 0;
}
