#include <stdio.h>

void multiplyArr(int arr[]);
void printArr(int arr[]);

int main()
{
    int arr[5];
    int *ptr = arr;
    for(int i = 0; i < 5; i++) {
        printf("Syötä luku: ");
        scanf("%d", &ptr[i]);
    }
    multiplyArr(ptr);
    return 0;
}

void multiplyArr(int arr[]) {
    for(int i = 0; i < 5; i++) {
        arr[i] = arr[i] * 5;
    }
    printArr(arr);
}

void printArr(int arr[]) {
    for(int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }
}
