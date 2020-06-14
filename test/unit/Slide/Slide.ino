int n=0;

void setup(){
Serial.begin(9600);
}

void loop(){
n=analogRead(A0);
Serial.println("OTA=" + (String)analogRead(A0)+""); //in Bread borad 235 ถึง 1023


  delay(1000);
}
