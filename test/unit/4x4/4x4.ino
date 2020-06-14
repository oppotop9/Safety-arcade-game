#include <Keypad.h>

const byte ROWS = 2 ; //four rows

const byte COLS = 1; //three columns

char keys[ROWS][COLS] = {

  {'A'},

  {'B'}

};
byte rowPins[ROWS] = {8,7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2}; //connect to the column pinouts of the keypad

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