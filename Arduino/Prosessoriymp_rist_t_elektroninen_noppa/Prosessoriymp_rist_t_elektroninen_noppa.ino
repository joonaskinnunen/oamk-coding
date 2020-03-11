
int satunnaisluku(void);
bool nappiOnPainettu(void);
void kirjoitaLukuSevenSegmentille(int);
const int nappi = 2;
const int G = 3;
const int F = 4;
const int E = 5;
const int D = 6;
const int C = 7;
const int B = 8;
const int A = 9;
/*****************************************
   Seven segmentti numerot esitetään alla olevassa
   taulukossa (kukin bitti vastaa yhden
   ledin arvoa). Siten 8-bittisen sanan 7 alinta bittiä
   sisältävät lediohjaustiedot seuravasti:
   0x0ABC DEFG
   Esimerkiksi numeron 2 toteuttamiseksi on sytytettävä
   ledit A,B,C,D,E,F,G eli 8-bittinen sana siis
   0x0110 1101 ja kaikki luvut 1- 6 siis esitetään
   1 = 0x0011 0000 => ledit B,C palaa
   2 = 0x0110 1101 => ledit A,B,D,E,G palaa
   3 = 0x0111 1001 => ledit A,B,C,D,G palaa
   4 = 0x0011 0011 => ledit B,C,F,G palaa
   5 = 0x0101 1011 => ledit A,C,D,F,G palaa
   6 = 0x0101 1111 => ledit A,C,D,E,F,G palaa
*/
/*
    Tähän numerot taulukkoon on sitten kerätty numerojen 1-6 ledien arvot 7-bittisinä
    lukuina. Saatte itse muodostaa arvot 2-6 tuohon taulukkoon (binääri/heksalukujen
    kertauksena)
*/
const uint8_t numerot[6] = {0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F}; // HUOM! korvaa luvut 2-6
int buttonPreviousState = 0;

void setup() {
  Serial.begin(9600); // debuggausta varten
  randomSeed(analogRead(0));     // alustetaan lukugen.
  pinMode(nappi, INPUT_PULLUP);  // 2 pinni kytkimena
  // INPUT_PULLUP vetää
  // pinnin ylös 5V
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {

  /*
      Tähän alle tulee testirakenne, jota voidaan käyttää yksittäisten
      aliohjelmien testaamiseen kätevästi.
  */
  /* while(1)
    {
      if(Serial.available() > 0)
      {
         //int arvo = Serial.read()-48;
         //Serial.println(arvo);
         int arvo = Serial.parseInt();
         Serial.println(arvo);
         kirjoitaLukuSevenSegmentille(arvo);
      }

    }

  */

  /*
     Tähän teidän pitää sitten, kun kaikki aliohjelmat on ensin yksittäin
     testattu yllä olevan kaltaisella testirakenteella, toteuttaa sen
     elektronisen nopan toiminta käyttäen tehtyjä aliohjelmia.
     - Tarkistetaan onko nappia painettu, jos on
        - niin sitten arvotaan satunnainen luku
        - ja tuo satunnainen luku kirjoitetaan 7-segmenttinäytölle
     - Nopan tulee toimia niin, että kytkimen painallus tuottaa
       vain yhden arpomistuloksen ja tuon arpomistuloksen jälkeen
       tulos jää näytölle, kunnes seuraava tulos arvotaan.
  */

  if (buttonPreviousState == 0 && nappiOnPainettu()) {
    kirjoitaLukuSevenSegmentille(satunnaisluku());
    buttonPreviousState = 1;
  } else if (buttonPreviousState == 1 && !nappiOnPainettu()) {
    buttonPreviousState = 0;
  }
}

int satunnaisluku(void)
{

  return random(1, 7);

  /*
      Tähän teidän pitäisi kehittää aliohjelma, joka palauttaa
      satunnaisluvun väliltä 1-6. Tämäkin kannattaa sitten
      ensin testat, että se varmasti toimii oletetulla tavalla
  */
}
bool nappiOnPainettu(void)
{
  /*
     Tähän teidän pitäisi kehittää aliohjelma, joka lukee
     bool tyyppiseen muuttujaan kytkin pinnin (pinni 2) tilan
     ja palauttaa sen sitten kutsuvalle ohjelmalle. Ja tämäkin
     kannattaa testata yksittäisenä aliohjelmana ja varmistua siitä,
     että pinnin 2 maadottaminen antaa true arvon ja jos pinniä ei
     maadoiteta, niin arvo = false.
  */
  int val = digitalRead(nappi);

  if (val == HIGH) {
    return false;
  }

  return true;
}
void kirjoitaLukuSevenSegmentille(int luku)
{
  int bitit = numerot[luku - 1]; // luku on välillä 1-6, siksi -1
  for (int i = 0; i < 7; i++)
  {
    int bitti = (bitit >> i) & 0x01; // siirretään alimmaksi ja otetaan irti
    digitalWrite(i + 3, bitti);
  }
}
