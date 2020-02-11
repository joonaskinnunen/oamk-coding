#include <stdio.h>

#define FIRST_NAME_SIZE 20
#define LAST_NAME_SIZE 50

struct person {
    char firstName[FIRST_NAME_SIZE];
    char lastName[LAST_NAME_SIZE];
    int age;
};

void askInfo(struct person p);
void printInfo(struct person p);

int main()
{
    struct person p;
    struct person *personPtr;
    personPtr = &p;
    askInfo(*personPtr);
    return 0;
}

struct point {
   int x;
   int y;
};

void askInfo(struct person p) {
    printf("Etunimi: ");
    scanf("%s", p.firstName);
    printf("Sukunimi: ");
    scanf("%s", p.lastName);
    printf("Ika: ");
    scanf("%d", &p.age);
    printInfo(p);
}
void printInfo(struct person p) {
    printf("Etunimi: %s\n", p.firstName);
    printf("Sukunimi: %s\n", p.lastName);
    printf("Ika: %d\n", p.age);
}
