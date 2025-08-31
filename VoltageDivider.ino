#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int analogPin = A0;
const float R1 = 30000.0; // 30k
const float R2 = 10000.0; // 10k
const float Vref = 5.0;   // Arduino reference voltage

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Voltage: ");
}

void loop() {
  int raw = analogRead(analogPin);
  float vout = (raw * Vref) / 1023.0;
  float vin = vout * (R1 + R2) / R2;

  Serial.print("Battery Voltage: ");
  Serial.println(vin);
  delay(1500);
  lcd.setCursor(0,1);
  lcd.print(vin);
  lcd.print("V");

}