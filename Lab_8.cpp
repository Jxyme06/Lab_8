#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensePin = A0;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(sensePin, INPUT);
}

void loop() {
  int rawValue = analogRead(sensePin);
  float voltage = rawValue * (5.0 / 1023.0);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voltage: ");

  lcd.setCursor(0, 1);
  lcd.print(voltage, 2);
  lcd.print(" V");

  delay(500);
}