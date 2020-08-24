#include <stdio.h>

int main()
{
    printf("Syötä kuukauden numero: ");
    int num;
    scanf("%d", &num);
    switch (num) {
        case 1:
            printf("Tammikuu\n");
            break;
        case 2:
            printf("Helmikuu\n");
            break;
        case 3:
            printf("Maaliskuu\n");
            break;
        case 4:
            printf("Huhtikuu\n");
            break;
        case 5:
            printf("Toukokuu\n");
            break;
        case 6:
            printf("Kesäkuu\n");
            break;
        case 7:
            printf("Heinäkuu\n");
            break;
        case 8:
            printf("Elokuu\n");
            break;
        case 9:
            printf("Syyskuu\n");
            break;
        case 10:
            printf("Lokakuu\n");
            break;
        case 11:
            printf("Marraskuu\n");
            break;
        case 12:
            printf("Joulukuu\n");
            break;
        default:
            printf("Tuntematon kuukausi\n");

    }
    return 0;
}
