int G = 10; 
int B =8; 
int R = 9;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(G, OUTPUT);
  Serial.begin(9600);
}
void loop(){
    analogWrite(R, 0); // RED สายถูก น่าจะเป็นที่อุปกรณ์
    analogWrite(B, 0); 
    analogWrite(G, 255); 
    delay(1000); 
    analogWrite(R, 255); // green
    analogWrite(B, 0); 
    analogWrite(G, 0); 
    delay(1000);
    analogWrite(R, 255); // yellow
    analogWrite(B, 0); 
    analogWrite(G, 255); 
    delay(1000);

  
}