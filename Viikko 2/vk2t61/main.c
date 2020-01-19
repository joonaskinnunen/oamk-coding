#include <stdio.h>

int main()
{
    int number = 1;
    int sum = 0;
    printf("Ohjelma laskee syötettyjen lukujen summan. Voit lopettaa syöttämällä 0\n");
    while(number != 0) {
        printf("Syötä luku: ");
        scanf("%d", &number);
        sum += number;
    }
    printf("Syötetyt luvut yhteensä: %d\n", + sum);
    return 0;
}
