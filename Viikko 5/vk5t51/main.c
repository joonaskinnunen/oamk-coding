#include <stdio.h>

#define ARRAY_SIZE 7

void askNumbers();
void printArr();


int main()
{
    float arr[ARRAY_SIZE];
    askNumbers(arr, ARRAY_SIZE);
    printArr(arr, ARRAY_SIZE);
    return 0;
}

void askNumbers(float arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Syötä luku: ");
        scanf("%f", &arr[i]);
    }
}

void printArr(float arr[], int size) {
    printf("Syöttämäsi luvut päinvastaisessa järjestyksessä:\n");
    for(int i = size-1; i >= 0; i--) {
        printf("%.2f\n", arr[i]);
    }
}
