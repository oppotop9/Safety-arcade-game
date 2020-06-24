#include <Keypad.h>

const byte ROWS = 2; 

const byte COLS = 1; 

char keys[ROWS][COLS] = {

  {'A'},

  {'B'}

};
byte rowPins[ROWS] = {4,3}; 
byte colPins[COLS] = {2}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}