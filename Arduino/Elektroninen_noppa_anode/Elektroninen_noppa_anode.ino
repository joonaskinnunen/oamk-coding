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

const uint8_t numerot[6] = {0x4F, 0x12, 0x6, 0x4C, 0x24, 0x20}; // HUOM! korvaa luvut 2-6
void setup() {
  Serial.begin(9600); // debuggausta varten
  randomSeed(analogRead(1));     // alustetaan lukugen.
  pinMode(nappi, INPUT_PULLUP);  // 2 pinni kytkimena
  // INPUT_PULLUP vetää
  // pinnin ylös 5V
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
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
      Testit
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

         Serial.println(satunnaisluku());

  */

  Serial.println(nappiOnPainettu());


  static int buttonPreviousState = 0;
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
}

bool nappiOnPainettu(void)
{
  bool val = digitalRead(nappi);

  if (val == true) {
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
