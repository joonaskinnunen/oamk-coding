#include <stdio.h>
#include "uusi.h" //Huomaa, että oma otsikkotiedosto on lainausmerkkien
//sisällä
int main()
{
    printf("Talletan globaaliin muutujaan x luvun 50\n");
    x=50;
    laske();
    tulosta();
    return 0;
}
