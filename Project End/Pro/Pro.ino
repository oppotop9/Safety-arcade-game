#include "LiquidCrystal_I2C.h" //จอ lcd
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <OneWire.h> //อุณหภูมิ
#include <DallasTemperature.h>
#include "CytronMotorDriver.h" //motor

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
long Time;
int Distance;

OneWire oneWire(Temperature); //Temperature
DallasTemperature sensors(&oneWire); 
CytronMD motor(PWM_PWM, 8, 3);   //motor

void setup() {
pinMode(Red, OUTPUT);
pinMode(Green, OUTPUT);
pinMode(Blue, OUTPUT);
pinMode(Flame, INPUT);
pinMode(laser, OUTPUT);
pinMode(Trig, OUTPUT);
pinMode(Echo, INPUT);
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
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    Time = pulseIn(Echo, HIGH);
    Distance = Time * 0.034 / 2; //S=T*0.034
    
  if(Water>10){
      
        lcd.setCursor(0, 0);
        lcd.print("   Alert !!!");

        lcd.setCursor(0, 1);
        lcd.print("Water Detected");
        delay(1000);
        analogWrite(Green,0);
        analogWrite(Red, Adapt);
        digitalWrite(laser, 1);
        color =analogRead(Red);
        
                }
    else  {
        if (Fire==0) {
        
        lcd.setCursor(0, 0);
        lcd.print("   Alert !!!");
        lcd.setCursor(0, 1);
        lcd.print("Fire Detected");
        delay(1000);
        analogWrite(Green,0);
        analogWrite(Red, Adapt);
        digitalWrite(laser, 1);
        color =analogRead(Red);
                        }
        else {
            if (Temp>35) {
            delay(1000);
            analogWrite(Green,Adapt);// Yellow
            analogWrite(Red, Adapt);
            
                if (Fire==0) {
                    
                    lcd.setCursor(0, 0);
                    lcd.print("   Alert !!!");
                    lcd.setCursor(0, 1);
                    lcd.print("Fire Detected");
                    delay(1000);
                    analogWrite(Green,0);
                    analogWrite(Red, Adapt);
                    digitalWrite(laser, 1);
                    color =analogRead(Red);
                
                            }
                else {
                    delay(1000);
                    motor.setSpeed(128);
                    if (Temp>40) {
                        lcd.setCursor(0, 0);
                        lcd.print("   Alert !!!");
                        lcd.setCursor(0, 1);
                        lcd.print("Hot Detected");
                        motor.setSpeed(0);
                        delay(1000);
                        analogWrite(Green,0);
                        analogWrite(Red, Adapt);
                        digitalWrite(laser, 1);
                        color =analogRead(Red);
                                }
                    else {
                        if (Distance<15) {
                        lcd.setCursor(0, 0);
                        lcd.print("Status < warning >");
                        lcd.setCursor(0, 1);
                        lcd.print("Beware : Hot");
                                        }
                            }
                        }
                }
            else {
                if (Distance<15) {
                    lcd.setCursor(0, 0);
                    lcd.print("Status < Safe >");
                    lcd.setCursor(0, 1);
                    lcd.print("Everything Clear");
                                    }
                    }
                }
    }
}
