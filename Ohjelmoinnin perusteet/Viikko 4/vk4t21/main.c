#include <stdio.h>

int main()
{
    int taulukko[2][3] = {{100, 200, 300}, {1000, 2000, 3000}};

    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d\n", taulukko[i][j]);
        }
    }

    return 0;
}
