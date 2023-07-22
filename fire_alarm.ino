const int sensorMin = 0;     //  sensor minimum
const int sensorMax = 1024;// sensor maximum
const int ledPin = 13;

void setup()  {
  // initialize serial communication @ 9600 baud:
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);  
}
void loop() {
  // read the sensor on analog A0:
  int sensorReading  = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long  int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading,  sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
  case 0:    // A fire closer than 1.5 feet away.
    Serial.println("** Close  Fire **");
    digitalWrite(ledPin, HIGH); 
    break;
  case 1:    // A fire between 1-3 feet away.
    Serial.println("**  Distant Fire **");
    digitalWrite(ledPin, HIGH); 
    break;
  case 2:    // No fire detected.
    Serial.println("No  Fire");
    digitalWrite(ledPin, LOW);
    break;
  }
  delay(1);  // delay between reads
}
