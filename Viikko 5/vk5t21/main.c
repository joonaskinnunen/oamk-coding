#include <stdio.h>

int main()
{
    int points;

    printf("Anna opiskelijan pistemäärä: ");
    scanf("%d", &points);

    // Use all three logical operators
    if(points < 8 || points > 24) {
        printf("Virheellinen pistemäärä\n");
    } else {
        if(!(points > 11)) {
            printf("Pistemaaralla %d saa arvosanan 1\n", points);
        } else if(points > 11 && points < 15) {
            printf("Pistemaaralla %d saa arvosanan 2\n", points);
        } else if(points > 14 && points < 19) {
            printf("Pistemaaralla %d saa arvosanan 3\n", points);
        } else if(points > 18 && points < 22) {
            printf("Pistemaaralla %d saa arvosanan 4\n", points);
        } else {
            printf("Pistemaaralla %d saa arvosanan 5\n", points);
        }
    }

    return 0;
}
