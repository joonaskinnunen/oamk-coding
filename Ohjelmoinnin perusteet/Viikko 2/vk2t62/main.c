#include <stdio.h>

int main()
{
    int sum = 0;
    int number = 0;
    for(int i = 0; i < 5; i++) {
        printf("Syötä luku: ");
        scanf("%d", &number);
        if(number % 2 != 0) {
            sum += number;
        }
    }
    printf("Parittomien lukujen summa: %d\n", sum);
    return 0;
}
