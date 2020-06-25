#define Red 9
#define Green 10
#define Blue 11

String R(int colorR){
    pinMode(Red, OUTPUT);
    pinMode(Green, OUTPUT);
    pinMode(Blue, OUTPUT);
    Serial.begin(9600);
    analogWrite(Red, 255); // RED 
    analogWrite(Green, 0); 
    analogWrite(Blue, 0); 
}

String G(int colorG){
    pinMode(Red, OUTPUT);
    pinMode(Green, OUTPUT);
    pinMode(Blue, OUTPUT);
    Serial.begin(9600);
    analogWrite(Red, 0); // Green
    analogWrite(Green, 255); 
    analogWrite(Blue, 0); 
}

String Y(int colorY){
    pinMode(Red, OUTPUT);
    pinMode(Green, OUTPUT);
    pinMode(Blue, OUTPUT);
    Serial.begin(9600);
    analogWrite(Red, 255); // Yellow
    analogWrite(Green, 255); 
    analogWrite(Blue, 0); 
}