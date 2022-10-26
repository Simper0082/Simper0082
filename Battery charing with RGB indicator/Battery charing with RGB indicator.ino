int sensorPin = A0; //set up A0 as ananlog 
int sensorValue = 0; //Starting sensor value

//light pints
int red = 11; 
int green = 10;
int blue = 9;

unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double PercentFull;
//================================================================

void setup() {
//RGB light set up
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

//serial monitor start
  Serial.begin(9600);
}
//================================================================

void RGB_color(int red_value, int green_value, int blue_value)
{
  //cusotom function for PWM
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);

}
//================================================================

//customer funciton calculates battery charge percentage and returns results as precision number
 double getBatteryPercentage() {
   return (((double)batteryLevel / (double)batteryCapacity)*100);
 }
//=====================================================================

//Send battery results to both serial and LED outputs
void ShowBatteryPercentage() {
  PercentFull=getBatteryPercentage(); //function to determine battery level

//print elasped time
  Serial.print(ticks);
  Serial.print(" ms  charge at ");
//Print the percentage of charge
  Serial.print(PercentFull);
//Print a percent charater to end the line
  Serial.println("%");

//update color of LED
  if (PercentFull > 0 && PercentFull <= 25)
  {
    RGB_color(125, 0, 0); //RED
  }
  else if (PercentFull > 25 && PercentFull <=50) {
    RGB_color(65, 10,0); //Yellow
  }
  else if (PercentFull > 50 && PercentFull <= 75) {
    RGB_color (0,125,125); //Light Blue
  }
  else if (PercentFull > 75 && PercentFull < 100) {
    RGB_color(125, 0, 125); //Purple
  }
}
//===================================================================


void loop() {
//Read values for sensors
  sensorValue = analogRead(sensorPin);
  batteryLevel += sensorValue;
  ticks += wait;

  if(batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.print(" ms   ");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity; //prevents intiger increase
    ticks = 0;
    RGB_color(0, 125, 0); //GREEN MEANS GO!
    delay(4000);
  }
  else {
    ShowBatteryPercentage();
  }
  delay(wait);

}
