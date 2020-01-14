#include <stdio.h>

int main()
{
    int points;
    printf("Anna opiskelijan pistemäärä: ");
    scanf("%d", &points);
    if(points > 21) {
        printf("Pistemäärällä %d saa arvosanan 5\n", points);
    } else if (points > 20) {
        printf("Pistemäärällä %d saa arvosanan 4\n", points);
    } else if (points > 14) {
        printf("Pistemäärällä %d saa arvosanan 3\n", points);
    } else if (points > 11) {
        printf("Pistemäärällä %d saa arvosanan 2\n", points);
    } else if (points > 7) {
        printf("Pistemäärällä %d saa arvosanan 1\n", points);
    } else {
        printf("Pistemäärällä %d saa arvosanan hylätty\n", points);
    }
    return 0;
}
