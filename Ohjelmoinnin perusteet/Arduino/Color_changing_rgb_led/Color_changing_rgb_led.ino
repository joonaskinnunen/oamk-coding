// Määritetään globaalit muuttujat, jotka näkyvä koko ohjelmalle (pinnit, joihin
// RGB-ledin eri värit on kytketty)
int ledPun = 3; // muuttujan ledPun arvoksi annetaan 3
int ledSin = 5; // muuttujan ledSin arvoksi annetaan 5
int ledVih = 7; // muuttujan ledVih arvoksi annetaan 7
void setup() {
 pinMode(ledPun, OUTPUT); // asetetaan pinnit OUTPUT-tilaan
 pinMode(ledVih, OUTPUT);
 pinMode(ledSin, OUTPUT);
}
void loop() {
 digitalWrite(ledPun, HIGH); // Sytytä punainen ledi
 delay(1000);
 digitalWrite(ledPun, LOW);  // Sammuta punainen ledi
 digitalWrite(ledVih, HIGH); // Sytytä vihreä ledi
 delay(1000);
 digitalWrite(ledVih, LOW);  // Sammuta vihreä ledi
 digitalWrite(ledSin, HIGH); // Sytytä sininen ledi
 delay(1000);
 digitalWrite(ledSin, LOW);  // Sammuta sininen ledi
}
