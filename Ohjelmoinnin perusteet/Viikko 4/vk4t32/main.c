#include <stdio.h>

float calcSquareCirc();

int main()
{
    printf("Kehän pituus on %.2f\n", calcSquareCirc());
    return 0;
}

float calcSquareCirc() {
    float length;
    printf("Tämä ohjelma laskee neliön kehän pituuden.\nSyötä neliön sivun pituus: ");
    scanf("%f", &length);
    return length * 4;
}
