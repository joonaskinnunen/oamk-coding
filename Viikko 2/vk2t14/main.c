#include <stdio.h>

int main()
{
    char name[] = "";
    printf("Mikä nimesi on?\n");
    scanf("%[^\n]s", name);
    printf("Hei %s!\n", name);
    return 0;
}
