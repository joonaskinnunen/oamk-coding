/*
  Blink

Turns on and off red, yellow and green led traffic lights style

*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins 13, 11 and 9 as an outputs.
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the red LED on (HIGH is the voltage level)
  delay(3000);                       // wait for 3 seconds
  digitalWrite(11, HIGH);   // turn the yellow LED on (HIGH is the voltage level)
  delay(2000);                       // wait for 2 seconds
  digitalWrite(13, LOW);    // turn the  red LED off by making the voltage LOW
  delay(2000);                       // wait for 2 seconds
  digitalWrite(9, HIGH);    // turn the LED on (HIGH is the voltage level)
  delay(2000);                       // wait for two seconds
  digitalWrite(11, LOW);    // turn the yellow LED off by making the voltage LOW
  delay(5000);                       // wait for 5 seconds
  digitalWrite(9, LOW);     // turn the green LED off by making the voltage LOW
  digitalWrite(11, HIGH);   // turn the yellow LED on (HIGH is the voltage level)
  delay(2000);                       // wait for 2 seconds
  digitalWrite(11, LOW);    // turn the yellow LED off by making the voltage LOW

}
