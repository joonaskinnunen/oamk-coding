// These constants won't change. They're used to give names to the pins used:
const int analogInPin0 = A0;  // input 1A
const int analogInPin1 = A1;  // input 1B
const int analogInPin2 = A2;  // Arduino input to be connected to the gate output 1Y just to show...
const int analogOutPin = 9; // Output pin that the LED is attached to

int sensorValue0 = 0;        // input sensor values...
int sensorValue1 = 0;
int sensorValue2 = 0;
int outputValue = 0;        // value output, joko 0 tai 255 (8bittinen kuvaus)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // Mitataan input-navat:
  sensorValue0 = analogRead(analogInPin0);
  delay(1);
  sensorValue1 = analogRead(analogInPin1);
  delay(1);
  sensorValue2 = analogRead(analogInPin2);

  // Arduino tuottaa OR-toiminnon oman logiikkansa avulla output-navalle:
  if((sensorValue0 > 800) && (sensorValue1 > 800)) //Looginen AND-testi on &&...
  {
    analogWrite(analogOutPin,255);
  }
  else 
  {
    analogWrite(analogOutPin,0);
  }

  // Tulostetaan sarjaportille mitatut tulokset ja myös reunat skaalauksen kiinnittämiseksi:
    
  Serial.print(-1000); //Plotterille alaraja
  Serial.print(" ");
  Serial.print(5000); //Plotterille yläraja
  Serial.print(" ");
  Serial.print(sensorValue0); //input 1A, 0 - 1023
  Serial.print(" ");
  Serial.print(sensorValue1 + 1500); //input 1B, nostetaan 1500 ylös: 1500 - n.2500
  Serial.print(" ");
  Serial.println(sensorValue2 + 3000); //mitattu output 1Y, nostetaan 3000 ylös: 3000 - n. 4000

  // wait 20 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(20);
}
