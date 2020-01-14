#include <stdio.h>

int main()
{
    char merkit[] = "";
    printf("Syötä merkkijono, vähintään 4 merkkiä: ");
    scanf("%s", &merkit);
    for(int i = 0; i < 3; i++) {
        printf("%c", merkit[i]);
    }
    printf("\n");
    return 0;
}
