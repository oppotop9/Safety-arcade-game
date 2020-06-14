
void setup() {                
	pinMode(13, OUTPUT);  
}

void loop() {
    
	digitalWrite(13, 1); 
	delay(5000); 
    digitalWrite(13, 0);
    delay(1000);
}