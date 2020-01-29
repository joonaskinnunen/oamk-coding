/*
  RGB led blinking with metronome style.
*/

// add digital pins numbers to an array
int leds[] = {3, 5, 7};

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins 13, 11 and 9 as an outputs.
  for (int pin = 0; pin < 3; pin++) {
    pinMode(leds[pin], OUTPUT);
  }
}

// the loop function runs over and over again forever
void loop() {
  // loop through digital pins
  for (int i = 0; i < 3; i++) {
    /*
      Blink each led color three times, one at the time.
      Wait 600ms after each time a led is turned on or off
    */
    for (int j = 0; j < 3; j++) {
      digitalWrite(leds[i], HIGH);
      delay(600);
      digitalWrite(leds[i], LOW);
      delay(600);
    }
    // turn on all three leds
    for (int j = 0; j < 3; j++) {
      digitalWrite(leds[j], HIGH);
    }
    // wait for 600ms
    delay(600);
    // turn off all three leds
    for (int j = 0; j < 3; j++) {
      digitalWrite(leds[j], LOW);
    }
    // wait for 600ms
    delay(600);
  }


}
