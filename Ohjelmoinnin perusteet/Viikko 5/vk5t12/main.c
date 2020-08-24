#include <stdio.h>

#define ARRAY_SIZE 7
float arr[ARRAY_SIZE];

void askNumbers();
void printArr();


int main()
{
    askNumbers();
    printArr();
    return 0;
}

void askNumbers() {
    for(int i = 0; i < 7; i++) {
        printf("Syötä luku: ");
        scanf("%f", &arr[i]);
    }
}

void printArr() {
    printf("Syöttämäsi luvut päinvastaisessa järjestyksessä:\n");
    for(int i = 6; i >= 0; i--) {
        printf("%.2f\n", arr[i]);
    }
}
