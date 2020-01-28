#include <stdio.h>

int main()
{
    int salanro = 0;
    while (salanro != 17) {
        printf("Syötä salanumero: ");
        scanf("%d",&salanro);
        if(salanro != 17) {
            printf("Väärä salanumero\n");
        }
    }
    printf("Salanumero oikein!\n");
    return 0;
}
