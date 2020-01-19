#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    float input, sum = 0;
    printf("Kuinka monta lukua haluat syöttää?\n");
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        printf("Syötä luku: ");
        scanf("%f", &input);
        sum += input;
    }
    printf("Lukujen summa on %.2f ja keskiarvo on %.2f\n", sum, sum / num);

    return 0;
}
