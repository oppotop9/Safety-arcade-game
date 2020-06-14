#include "LiquidCrystal_I2C.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");
  
  lcd.setCursor(0, 1);
  lcd.print("Hi");

  delay(2000);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");

  lcd.setCursor(0, 1);
  lcd.print(millis());
}
