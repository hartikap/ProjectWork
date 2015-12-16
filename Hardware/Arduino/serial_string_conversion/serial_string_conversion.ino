String inString = "";    // string to hold serial input
const int analogOutPin = 10;
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;

void setup() {

  cli();
  //set timer1 interrupt at 10Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 10hz increments
  OCR1A = 1562;// = (16*10^6) / (10*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();//allow interrupts

  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  /*while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }*/

}

ISR(TIMER1_COMPA_vect){
   
}


void loop() {
  if (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    
    // if you get something that's not a digit, write the received
    // value to analog output
    if (!isDigit(inChar)) {
      //Serial.print("Value:");
      Serial.println(inString.toInt());
      //analogWrite(analogOutPin, inString.toInt());
      // clear the string for new input:
      inString = "";
    }

  }

  // read the analog in value:
   sensorValue = analogRead(analogInPin);
    // map it to the range of the analog out:
   outputValue = map(sensorValue, 0, 1023, 0, 255);
   // change the analog out value:
   analogWrite(analogOutPin, outputValue);
  delay(2);
  
  
}
