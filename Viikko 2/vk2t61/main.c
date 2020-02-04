#include <stdio.h>

int main()
{
    int num = 1, sum = 0;
    printf("Ohjelma laskee syötettyjen lukujen summan. Voit lopettaa syöttämällä 0\n");
    while(num != 0) {
        printf("Syötä luku: ");
        scanf("%d", &num);
        sum += num;
    }
    printf("Syötetyt luvut yhteensä: %d\n", + sum);
    return 0;
}
