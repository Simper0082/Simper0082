int sensorPin = A0; //Select the *analog zero* input pin for probing the photorsistor
int onboardLED = 13;
int sensorValue = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //baud in Serial Monitor 
  pinMode(onboardLED, OUTPUT);

}

void loop() {
  sensorValue = analogRead(sensorPin);
digitalWrite(onboardLED, HIGH);
delay(sensorValue);
digitalWrite(onboardLED, LOW);
delay(sensorValue);

Serial.println(sensorValue);
delay(sensorValue);
  
}
