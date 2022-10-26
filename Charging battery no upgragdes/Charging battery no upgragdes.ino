int sensorPin = A0; //Select the *analog zero* input pin for probing the photorsistor
int onboardLED = 13;
int sensorValue = 0; 
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double PercentFull;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //baud in Serial Monitor 
  pinMode(onboardLED, OUTPUT);

}

void PrintBatteryPercentage() { 
  // Print the elasped time
  Serial.print(ticks);
  Serial.print(" ms  charge at ");

// Connvert the intergers to decimal number, divide them and print.
  PercentFull=100*((double)batteryLevel/(double)batteryCapacity);
  Serial.print(PercentFull);

// Print a Percent character and line return.
  Serial.println("%");

}

void loop() {
  sensorValue = analogRead(sensorPin);
  batteryLevel += sensorValue;
  ticks += wait;

  if(batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.print(" ms   ");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity;
    ticks = 0;
    delay(20000);
  }
  else {
    PrintBatteryPercentage();
  }
  delay(1000);
}
