#include "L3G4200D.h"
#include "mbed.h"
#include <cstdio>

Timer timer;

L3G4200D gyro(D14, D15);
int g[3] = {0, 0, 0};
float kulma = 0.0;
int tulostusvali = 10;
int sykli = 0;
int skaalauskerroin = 70;
float korkeus = 3000.0;
float ilmanvastusMin = 14.12640004;
float ilmanvastusMax = 156.9600127;
float ilmanvastuskerroin = ilmanvastusMin;
float nopeus = 0.0;
int massa = 80;
float nopeudenmuutos = 0.0;

int main() {

  timer.start();
  timer.reset();
  while (true) {
    sykli = sykli + 1;
    unsigned long aika = timer.read_ms();

    gyro.read(g);

    g[0] = g[0] - 10;
    g[1] = g[1] - 17;
    g[2] = g[2] + 14;

    kulma = kulma + g[1] * skaalauskerroin * 0.001 * aika * 0.001;

    if (sykli == tulostusvali) {
      if (kulma <= 90 && kulma >= 0) {
        ilmanvastuskerroin = ilmanvastusMin + (ilmanvastusMax - ilmanvastusMin) / 90 * kulma;
     }
      nopeudenmuutos = (-9.81 * massa - ilmanvastuskerroin * nopeus) / massa * aika * 0.005;
      nopeus = nopeus + nopeudenmuutos;
      korkeus = korkeus + nopeus * aika * 0.005;
      printf("%i ", (int)nopeus);
      timer.reset();
      sykli = 0;
      printf("\r\n");
    }
  }
}