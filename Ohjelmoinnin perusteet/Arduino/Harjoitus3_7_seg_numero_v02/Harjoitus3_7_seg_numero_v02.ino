/*

Digitaalitekniikka / Labraharjoitus 3
7-segmentti -näyttöpalikan, eli yhden numeron ohjaus pelkästään Arduinolla.

Tarkoitus on syöttää SerialMonitorilla luku 0 - 9 ja havaita sen piirtyvän 7-segmentti -numeronäytölle jos olet sen oikein kytkenyt...
paitsi että tasan yksi numeroista on tahalleen jätetty väärin koodatuksi. Selvitä mikä numero ei toimi ja korjaa ohjelmakoodi.

1. Selvitä ensiksi näyttöpalikan kytkentälogiikka. Etsi webistä pin-konfiguraatio ja katso siitä GND-kytkentänapa.

2. Jos liität GND-johtimeen 500 ohmin vastuksen niin se toimii virran rajoittimena samalla kertaa kaikille ledeille.
Tällöin kuitenkin ledien kirkkaus muuttuu riippuen palavien ledien lukumäärästä.
Jos tämä ei HIGHttaa, niin selvitään pienemmällä komponenttimäärällä. Parhaan ja tasaisen kirkkauden saat 7-näytölle jos kytket kullekin 
ledille oman sarjavastuksensa.

3. Käytä kytkennässäsi seuraavaa numerointia. Keskellä oleva viiva olkoon pin nro 8. Piste kytketään suoraan 5V-napaan tai 9-napaan,
koska se saa olla koko ajan päällä.
Ohjelmalogiikan mukainen Arduinon digitaalipuolen pinnien numerointi suhteessa 7-segmenttinäytön ledien sijaintiin:

    6
    _
 7 | | 5
    -
 4 | | 2
    -
    3
 


4. Jos haluat kikkailla ohjelmalla, voit koodata sellaisen toiminnon että ei-hyväksyttävä syöttö tuottaa E:n numeronäytölle.
Tällöin kaikki käyttäjälle mahdolliset toiminnot on huomioitu ohjelmassa.

 */


// Määritellään Output-pinnit:
const int OutPin2 = 2;
const int OutPin3 = 3;
const int OutPin4 = 4;
const int OutPin5 = 5;
const int OutPin6 = 6;
const int OutPin7 = 7;
const int OutPin8 = 8;
const int OutPin9 = 9;

int readValue = 0;    // Sarjamonitorin avulla syötettävä jännitettä kuvaava kokonaisluku välillä 0 - 9.
boolean sisaan = true;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(OutPin2, OUTPUT);
  pinMode(OutPin3, OUTPUT);
  pinMode(OutPin4, OUTPUT);
  pinMode(OutPin5, OUTPUT);
  pinMode(OutPin6, OUTPUT);
  pinMode(OutPin7, OUTPUT);
  pinMode(OutPin8, OUTPUT);
  pinMode(OutPin9, OUTPUT);
}

void loop() {

  //Vain alkuun tulostetaan tekstit, joka vaatii Genuinolla sarjamonitori-yhteyden tarkkailua
  while (!Serial) sisaan = true;  //  wait for the serial monitor to open
  if (sisaan) {
    Serial.println("Anna jokin kokonaisluku valilla 0 - 9 ja paina Enter");
    sisaan = false;
  }

  
  // if there's any serial available, read it:  
  if (Serial.available() > 0) {
    
    // look for the next valid integer in the incoming serial stream:
    readValue = Serial.parseInt();              //Luetaan käyttäjän syöttämä luku
    
    //readValue = constrain(readValue,0,9);         //Pakotetaan syötetty arvo vaaditulle välille.

    if(readValue == 0)                              //Jos annettiin nolla:
    {
      digitalWrite(OutPin2, LOW);
      digitalWrite(OutPin3, LOW);
      digitalWrite(OutPin4, LOW);
      digitalWrite(OutPin5, LOW);
      digitalWrite(OutPin6, LOW);
      digitalWrite(OutPin7, LOW);
      digitalWrite(OutPin8, HIGH);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    if(readValue == 1)                              //Jos annettiin yksi jne...
    {
      digitalWrite(OutPin2, LOW);
      digitalWrite(OutPin3, HIGH);
      digitalWrite(OutPin4, HIGH);
      digitalWrite(OutPin5, LOW);
      digitalWrite(OutPin6, HIGH);
      digitalWrite(OutPin7, HIGH);
      digitalWrite(OutPin8, HIGH);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    if(readValue == 2)                          
    {
      digitalWrite(OutPin2, HIGH);
      digitalWrite(OutPin3, LOW);
      digitalWrite(OutPin4, LOW);
      digitalWrite(OutPin5, LOW);
      digitalWrite(OutPin6, LOW);
      digitalWrite(OutPin7, HIGH);
      digitalWrite(OutPin8, LOW);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    if(readValue == 3)                          
    {
      digitalWrite(OutPin2, LOW);
      digitalWrite(OutPin3, LOW);
      digitalWrite(OutPin4, HIGH);
      digitalWrite(OutPin5, LOW);
      digitalWrite(OutPin6, LOW);
      digitalWrite(OutPin7, HIGH);
      digitalWrite(OutPin8, LOW);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    if(readValue == 4)                              
    {
      digitalWrite(OutPin2, LOW);
      digitalWrite(OutPin3, HIGH);
      digitalWrite(OutPin4, HIGH);
      digitalWrite(OutPin5, LOW);
      digitalWrite(OutPin6, HIGH);
      digitalWrite(OutPin7, LOW);
      digitalWrite(OutPin8, LOW);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    if(readValue == 5)                             
    {
      digitalWrite(OutPin2, LOW);
      digitalWrite(OutPin3, LOW);
      digitalWrite(OutPin4, HIGH);
      digitalWrite(OutPin5, HIGH);
      digitalWrite(OutPin6, LOW);
      digitalWrite(OutPin7, LOW);
      digitalWrite(OutPin8, LOW);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    if(readValue == 6)                
    {
      digitalWrite(OutPin2, LOW);
      digitalWrite(OutPin3, LOW);
      digitalWrite(OutPin4, LOW);
      digitalWrite(OutPin5, HIGH);
      digitalWrite(OutPin6, HIGH);
      digitalWrite(OutPin7, LOW);
      digitalWrite(OutPin8, LOW);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    if(readValue == 7)                       
    {
      digitalWrite(OutPin2, LOW);
      digitalWrite(OutPin3, HIGH);
      digitalWrite(OutPin4, HIGH);
      digitalWrite(OutPin5, LOW);
      digitalWrite(OutPin6, LOW);
      digitalWrite(OutPin7, HIGH);
      digitalWrite(OutPin8, HIGH);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    if(readValue == 8)                     
    {
      digitalWrite(OutPin2, LOW);
      digitalWrite(OutPin3, LOW);
      digitalWrite(OutPin4, LOW);
      digitalWrite(OutPin5, LOW);
      digitalWrite(OutPin6, LOW);
      digitalWrite(OutPin7, LOW);
      digitalWrite(OutPin8, LOW);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    if(readValue == 9)                     
    {
      digitalWrite(OutPin2, LOW);
      digitalWrite(OutPin3, LOW);
      digitalWrite(OutPin4, HIGH);
      digitalWrite(OutPin5, LOW);
      digitalWrite(OutPin6, LOW);
      digitalWrite(OutPin7, LOW);
      digitalWrite(OutPin8, LOW);
      digitalWrite(OutPin9, LOW);
      delay(2);
    }

    //Tulostetaan syöttötietoja ruutuun:
    Serial.print("Syotit luvun ");
    Serial.println(readValue);  
    delay(1000);

  }
    delay(2);                                      //Rauhoitetaan silmukkaa hieman
}
