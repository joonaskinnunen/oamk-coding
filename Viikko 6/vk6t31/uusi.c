#include <stdio.h>
int x;
void laske()
{
    printf("Lisään globaaliin muuttujaan x luvun 10\n");
    x=x+10;
}
void tulosta()
{
    printf("Tulostan globaaalin muuttujan x = %d\n",x);
}
