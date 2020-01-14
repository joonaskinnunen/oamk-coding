#include <stdio.h>

int main()
{
    int salanro = 0;
    printf("Syota salanumero\n");
    scanf("%d",&salanro);

    while (salanro != 17) {
        printf("Väärä salanumero, syota uusi\n");
        scanf("%d",&salanro);

    }
    printf("Onnistunut valinta\n");

    return 0;

}
