#include <stdio.h>

#define FIRST_NAME_SIZE 20
#define LAST_NAME_SIZE 20

int main()
{
    struct person {
        char firstName[FIRST_NAME_SIZE];
        char lastName[LAST_NAME_SIZE];
        int age;
    };
    struct person p;
    printf("Etunimi: ");
    scanf("%s", p.firstName);
    printf("Sukunimi: ");
    scanf("%s", p.lastName);
    printf("Ika: ");
    scanf("%d", &p.age);
    printf("Etunimi: %s\n", p.firstName);
    printf("Sukunimi: %s\n", p.lastName);
    printf("Ika: %d\n", p.age);
    return 0;
}
