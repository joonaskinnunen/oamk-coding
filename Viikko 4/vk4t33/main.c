#include <stdio.h>

int getMenuChoice();

float getSquareLength();

float getCircleRadius();

void printMenu();

float calcSquare(float length);

float calcCircle(float length);

int main()
{
    int menuChoice = 0;
    while(menuChoice != 9) {
        printMenu();
        menuChoice = getMenuChoice();

        if(menuChoice == 1) {
            float length = getSquareLength();
            printf("Neliön kehän pituus: %f\n", calcSquare(length));
        } else if(menuChoice == 2) {
            float length = getCircleRadius();
            printf("Ympyrän kehän pituus: %f\n", calcCircle(length));
        }
    }
    printf("Kiitos ohjelman käyttämisestä!\n");
    return 0;
}

int getMenuChoice() {
    int input;
    scanf("%d", &input);
    return input;
}

float getSquareLength() {
    printf("Syötä neliön sivun pituus: ");
    float length;
    scanf("%f", &length);
    return length;
}

float getCircleRadius() {
    printf("Syötä ympyrän säde: ");
    float length;
    scanf("%f", &length);
    return length;
}

void printMenu() {
    printf("Mitä haluat tehdä?\n1. Laske neliön kehän pituus\n2. Laske ympyrän kehän pituus\n9. lopeta\n");
}

float calcSquare(float length) {
    return length * 4;
}

float calcCircle(float length) {
    return 2 * 3.14 * length;
}
