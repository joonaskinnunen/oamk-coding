#include <stdio.h>

#define TAULUKON_KOKO 5     	//määritetään vakio

int taulukko[TAULUKON_KOKO]; 	//määritellään GLOBAALI MUUTTUJA taulukko
int kertoja=2; 			//määritellään GLOBAALI MUUTTUJA kertoja

void tulostaTaulukko(); //Funktion esittely

int main()
{
    int i=0;  //määritellään paikallinen muuttuja
    while (i<TAULUKON_KOKO)
    {
        printf("Anna kokonaisluku:\n");
        scanf("%d",&taulukko[i]);
        i++;
    }
    tulostaTaulukko();
    return 0;
}

void tulostaTaulukko()  //Funktion määrittely eli toteutus
{
  int k=0;  //määritellään paikallinen muuttuja
  while (k<TAULUKON_KOKO)
  {
    printf("Luku %d = %d\n",k+1,taulukko[k]*kertoja);
    k++;
  }
}
