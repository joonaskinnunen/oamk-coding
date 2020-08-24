#include <stdio.h>

int main()
{
    printf("Syötä kirjain a, b tai c:\n");
    char letter;
    scanf("%c", &letter);
    switch (letter) {
        case 'a':
            printf("Painoit aan\n");
            break;
        case 'b':
            printf("Painoit been\n");
            break;
        case 'c':
            printf("Painoit ceen\n");
            break;
        default:
            printf("Väärä merkki\n");

    }
    return 0;
}
