int x;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("No format");
  Serial.print("\t");
  
  Serial.print("DEX");
  Serial.print("\t");
  
  Serial.print("HEX");
  Serial.print("\t");
  
  Serial.print("OCT");
  Serial.print("\t");
  
  Serial.print("BIN");
  Serial.println("\t");

  for(x = 0; x < 64; x++) {
    Serial.print(x);
    Serial.print("\t");
    Serial.print("\t");

    Serial.print(x, DEC);
    Serial.print("\t");

    Serial.print(x, HEX);
    Serial.print("\t");

    Serial.print(x, OCT);
    Serial.print("\t");

    Serial.println(x, BIN);

    delay(500);
  }
  Serial.println("");
}
