int sensorPin = A0;    // select the input pin for the Soil moisture sensor
int sensorValue = 0;  // variable to store the value coming from the sensor
 
void setup() {
  // declare the ledPin as an OUTPUT:
   Serial.begin(9600);  
}
 
void loop() {
  
  sensorValue = analogRead(sensorPin);    
  delay(1000);          
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);     

  if(sensorValue <= 300)
  {
    Serial.println("With out Water");
  }
  else
  {
    Serial.println("Water");
  }
}