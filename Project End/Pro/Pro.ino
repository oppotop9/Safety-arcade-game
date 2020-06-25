#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define Red 9
#define Green 10
#define Blue 11

int Adapt =0;
void setup() {
pinMode(Red, OUTPUT);
pinMode(Green, OUTPUT);
pinMode(Blue, OUTPUT);
Serial.begin(9600);
//analogWrite(Red, 0); 
analogWrite(Green, 255); // Green
//analogWrite(Blue, 0); 

  lcd.init();
  lcd.backlight();

  lcd.setCursor(1, 0);
  lcd.print("Welcome To");
  
  lcd.setCursor(3, 1);
  lcd.print("Arcade Game");

}

void loop() {
  Adapt=analogRead(A2);
  Adapt=Adapt/4;
  analogWrite(Green, Adapt);
  
  
  /* lcd.setCursor(0, 0);
  lcd.print("Hello, world!");

  lcd.setCursor(0, 1);
  lcd.print(millis());*/
}
