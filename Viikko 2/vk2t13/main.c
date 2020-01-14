#include <stdio.h>

int main()
{
    int i = 0;
    while(i != 17) {
        printf("Syötä salanumero: ");
        scanf("%d", &i);
        (i == 17) ? printf("Onneksi olkoon. Tiesit oikean salanumeron!\n") : printf("Salanumero väärin\n");
    }
    return 0;
}
