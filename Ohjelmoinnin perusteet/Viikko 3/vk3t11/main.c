#include <stdio.h>

int main()
{
    int num = 0;
    do {
        printf("Syötä salanumero: ");
        scanf("%d", &num);
    } while (num != 17);
    printf("Tiesit oikean salanumeron. Onnea!\n");
    return 0;
}
