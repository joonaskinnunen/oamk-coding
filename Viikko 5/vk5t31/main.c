#include <stdio.h>
#include <string.h>

#define SIZE 100
char input[SIZE];

int main()
{
    int numOfA = 0;
    printf("Syötä merkkijono: ");
    scanf("%[^\n]s", input);
    for(int i = 0; i < SIZE; i++) {
        if(input[i] == 'a' || input[i] == 'A') {
            numOfA++;
        }
    }
    printf("Taulukossa on %d A-kirjainta\n", numOfA);
    return 0;
}
