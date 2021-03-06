/*
  ReadAnalogVoltage
  Reads an analog input on pin 0, converts it to voltage, and prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */
int avg = 512;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int val = analogRead(A0);
  avg = (7 * avg + val) >> 3;
  int dval = val - avg;
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  if (abs(dval) > 60) {
    Serial.println(val);
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }
}
