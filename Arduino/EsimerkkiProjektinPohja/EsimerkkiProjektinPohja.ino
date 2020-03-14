/*
  Projektityöesimerkkitehtävä

  Tässä pohja tehtävää varten.

  Eli kun teette koodausprojektia useamman henkilön toimesta se kannattanee jakaa aluksi aliohjelmiksi,
  joita eri henkilöt pystyät itsenäisesti koodaamaan.

  Tässä esimerkkissä on tarkoitus tehdä Arduinolla ohjelma, joka kysyy kolmion kantasivun ja korkeuden ja sitten
  laskee sen pinta-alan (pinta-ala=kanta*korkeus/2) ja tulostaa pinta-alan.

  Vaiheet:
  1. Mietitään miten ongelma ohjelmallisesi ratkaistaa.
  2. Ratkaisu: kysytään kannan pituus, kysytään korkeus, lasketaan pinta-ala ja tuostetaan pita-ala
  3. Koodataan ratkaisun pohja (Tämä annettu teille valmiina. Kolme aliohjelmaa, jotka jokainen ryhmän jäsen voi
  itse koodata valmiiksi. (lueArvo(), laskeAla(), tulosta())
  4. Koodataan aliohjelmat (jokainen ryhmän jäsen koodaan tässä oman aliohjelma)
  5. Yhdistetään aliohjelmat (joku ryhmän jäsen yhdistää aliohjelmat toimivaksi ohjelmaksi)
  6. Testataan ratkaisua

*/

float kanta, korkeus, pintaAla;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    kanta = lueArvo("Anna kolmion kantasivun pituus (desimaalilukuna)");
    korkeus = lueArvo("Anna kolmion korkeus (desimaalilukuna)");
    pintaAla = laskeAla(kanta, korkeus);
    tulosta(pintaAla);
  delay(3000); //3s viive

}

//Jäsen 1. kirjoita ratkaisun koodi ao. funktioon
//Aliojelma kysyy desimaaliluvun (float) käyttäjältä ja palauttaa sen kutsuvaan ohjelmaan
//Katso mallia Esimerkki1.ino ohjelmasta

float lueArvo(String viesti) {
  Serial.println(viesti);
  while(!Serial.available()) {}
  float arvo = Serial.readString().toFloat();
  return arvo;
}

//Jäsen 2. kirjoita ratkaisun koodi ao. funktioon
//Aliohjelma laskee kolmion pinta-ala (ala=ka*ko/2) ja palauttaa sen kutsuvaan ohjelmaan

float laskeAla(float ka, float ko) {
  return ka*ko/2;
}

//Jäsen 3. kirjoita ratkaisun koodi ao. funktioon
//Aliohjelma tulotaa siihen tuodun kolmion pinta-alan

void tulosta(float tulos) {
  Serial.print("Kolmion pinta-ala on: ");
  Serial.println(tulos);
}
