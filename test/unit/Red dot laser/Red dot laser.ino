
void setup() {                
	pinMode(13, OUTPUT);  // Define the digital output interface pin 13 
}

void loop() {
    
	digitalWrite(13, 1); // Open the laser head
	delay(5000); // Delay one second
    digitalWrite(13, 0);
    delay(1000);
}