
 int Flame = 2; 


  void setup()
 {
     pinMode(Flame, INPUT);

     Serial.begin(9600);
 }
 
  void loop()
 {
     int N = digitalRead(Flame); 
     if (N == 0) 
     {
        Serial.println("Flame!!!");
        delay (500);
     }
     else {
        Serial.println("NO Flame");
        delay (500);
     }
 }