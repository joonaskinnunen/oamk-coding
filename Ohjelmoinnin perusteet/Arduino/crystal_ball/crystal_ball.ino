#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
void setup() {
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  lcd.print("Kysy");
  lcd.setCursor(0, 1);
  lcd.print("jotain!");
}
void loop() {
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(7);
      lcd.clear();
      lcd.setCursor(0, 0);
      switch (reply) {
        case 0:
          lcd.print("Kylla! :)");
          lcd.setCursor(0, 1);
          lcd.print("No mietippa ite");
          lcd.setCursor(0, 0);
          break;
        case 1:
          lcd.print("Ehka joo...");
          break;
        case 2:
          lcd.print("Tyhma kysymys!");
          lcd.setCursor(0, 1);
          lcd.print("Tiiat kyllä");
          lcd.setCursor(0, 0);
          break;
        case 3:
          lcd.print("Tottakai <3");
          break;
        case 4:
          lcd.print("En ois varma");
          lcd.setCursor(0, 1);
          lcd.print("Kysy viisaammilta");
          lcd.setCursor(0, 0);
          break;
        case 5:
          lcd.print("Kysyppa uusiksi");
          break;
        case 6:
          lcd.print("Hmm...");
          lcd.setCursor(0, 1);
          lcd.print("Enpa kerro ;)");
          lcd.setCursor(0, 0);
          break;
      }
    }
  }
  prevSwitchState = switchState;
}
