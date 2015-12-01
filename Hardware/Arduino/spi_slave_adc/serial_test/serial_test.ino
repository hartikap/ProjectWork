const int ledPin = 9;

void setup(){
Serial.begin(9600);
}

void loop(){
if (Serial.available()) {
light(Serial.read());
}
delay(500);
}

void light(int voltage){
analogWrite(ledPin,voltage);
delay(2000);
//analogWrite(ledPin,0);
}

