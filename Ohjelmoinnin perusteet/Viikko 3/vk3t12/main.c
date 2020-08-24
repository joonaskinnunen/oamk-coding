#include <stdio.h>

int main()
{
    char name[100];
    int num;
    printf("Mikä nimesi on?\n");
    scanf("%[^\n]s", name);
    printf("Kuinka monta kertaa haluat tulostaa nimen?\n");
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        printf("%s\n", name);
    }
    return 0;
}
