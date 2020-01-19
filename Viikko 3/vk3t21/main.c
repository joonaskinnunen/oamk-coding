#include <stdio.h>

int main()
{
    printf("Syötä luku 1, 2 tai 3:\n");
    int num;
    scanf("%d", &num);
    switch (num) {
        case 1:
            printf("Painoit ykkösen\n");
            break;
        case 2:
            printf("Painoit kakkosen\n");
            break;
        case 3:
            printf("Painoit kolmosen\n");
            break;
        default:
            printf("Väärä kokonaisluku\n");

    }
    return 0;
}
