#include <stdio.h>

int main()
{
    int i = 0;
    while(i != 17) {
        printf("Syötä salanumero: ");
        scanf("%d", &i);
        if(i == 17) {
           break;
        }
        printf("Salanumero väärin\n");
    }
    printf("Onneksi olkoon. Tiesit oikean salanumeron!\n");
    return 0;
}
