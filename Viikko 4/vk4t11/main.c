#include <stdio.h>

int main()
{
    float numbers[5];
    float input;
    for(int i = 0; i < 5; i++) {
        printf("Syötä luku: ");
        scanf("%f", &input);
        numbers[i] = input;
    }
    printf("Syöttämäsi luvut:\n");
    for(int i = 0; i < 5; i++) {
        printf("%.2f\n", numbers[i]);
    }
    return 0;
}
