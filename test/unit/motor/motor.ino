

 #include "CytronMotorDriver.h"


// Configure the motor driver.
CytronMD motor1(PWM_PWM, 3, 4);   


// The setup routine runs once when you press reset.
void setup() {
  
}


// The loop routine runs over and over again forever.
void loop() {
  motor1.setSpeed(128);   // Motor 1 runs forward at 50% speed.
 
  delay(1000);
  
  motor1.setSpeed(255);   // Motor 1 runs forward at full speed.
  
  delay(1000);

  motor1.setSpeed(0);     // Motor 1 stops.
  
  delay(1000);

  motor1.setSpeed(-128);  // Motor 1 runs backward at 50% speed.
 
  delay(1000);
  
  motor1.setSpeed(-255);  // Motor 1 runs backward at full speed.
  
  delay(1000);

  motor1.setSpeed(0);     // Motor 1 stops.
  
  delay(1000);
}
