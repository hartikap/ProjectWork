String inString = "";    // string to hold input
const int ledPin = 10;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  //Serial.println("\n\nString toInt():");
  //Serial.println();
}

void loop() {
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char
      // and add it to the string:
      inString += (char)inChar;
    }
    //Serial.println(inString.toInt());
    
    // if you get a newline, print the string,
    // then the string's value:
    if (!isDigit(inChar)) {
      //Serial.print("Value:");
      Serial.println(inString.toInt());
      analogWrite(ledPin, inString.toInt());
      // clear the string for new input:
      inString = "";
    }

  }
}
