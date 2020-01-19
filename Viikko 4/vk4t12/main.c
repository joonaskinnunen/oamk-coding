#include <stdio.h>

int main()
{
    int numbers[6];
    int input, numOfEven = 0;
    for(int i = 0; i < 6; i++) {
        printf("Syötä luku: ");
        scanf("%d", &input);
        numbers[i] = input;
    }
    for(int i = 0; i < 6; i++) {
        if(numbers[i] % 2 == 0) {
            numOfEven++;
        }
    }
    printf("Parillisia lukuja: %d\n", numOfEven);
    return 0;
}
