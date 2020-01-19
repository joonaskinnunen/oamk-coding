#include <stdio.h>

int main()
{
    char merkit[100];
    printf("Syötä merkkijono, vähintään 4 merkkiä: ");
    scanf("%100s", merkit);
    for(int i = 0; i < 3; i++) {
        printf("%c", merkit[i]);
    }
    printf("\n");
    return 0;
}
