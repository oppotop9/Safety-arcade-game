#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <OneWire.h>
#include <DallasTemperature.h>

#define Temperature 7
#define Red 9
#define Green 10
#define Blue 11
#define laser 13
int color=Green;
int Adapt =0;
int Water =0;
int Trig = 5;
int Echo = 6;
int Flame =12;
OneWire oneWire(Temperature);
DallasTemperature sensors(&oneWire);

void setup() {
pinMode(Red, OUTPUT);
pinMode(Green, OUTPUT);
pinMode(Blue, OUTPUT);
pinMode(Flame, INPUT);
pinMode(laser, OUTPUT);
Serial.begin(9600);
//analogWrite(Red, 0); 
analogWrite(Green, 255); // Green
//analogWrite(Blue, 0); 
sensors.begin();// Temperature
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
  analogWrite(color, Adapt); //ลดเเสง
  Water=analogRead(A0); //น้ำ
  int Fire=digitalRead(Flame); // เปลวเพลิง
  sensors.requestTemperatures(); // อุณหภูมิเรียกใช้งาน
  double Temp =sensors.getTempCByIndex(0);// เเสดงจำนวน
 
  if(Water>10){
      delay(1000);
        lcd.setCursor(0, 0);
        lcd.print("   Alert !!!");

        lcd.setCursor(0, 1);
        lcd.print("Water Detected");

      analogWrite(Green,0);
      analogWrite(Red, Adapt);
      digitalWrite(laser, 1);
      color =analogRead(Red);
      
                }
    else  {
        if (Fire==0) {
        delay(1000);
        lcd.setCursor(0, 0);
        lcd.print("   Alert !!!");
        lcd.setCursor(0, 1);
        lcd.print("Fire Detected");

        analogWrite(Green,0);
        analogWrite(Red, Adapt);
        digitalWrite(laser, 1);
        color =analogRead(Red);
                        }
        else {
            if (Temp>35) {
            analogWrite(Green,Adapt);
            analogWrite(Red, Adapt);
    
                if (Temp>40) {
                delay(1000);
                lcd.setCursor(0, 0);
                lcd.print("   Alert !!!");
                lcd.setCursor(0, 1);
                lcd.print("Hot Detected");

                analogWrite(Green,0);
                analogWrite(Red, Adapt);
                digitalWrite(laser, 1);
                                }
                else {
                
                }
           }
            else {
                
            }
       }
  }
  
}
