int red = 11;
int green = 10;
int blue = 9;

void setup() {

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void RGB_color(int red_value, int green_value, int blue_value)
{
  //cusotom function for PWM
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);

}

void loop() {
//turn my lights on fancy like
  RGB_color(125, 0, 0);
  delay(1000);
  RGB_color(0, 125, 0);
  delay(1000);
  RGB_color(0, 0, 125);
  delay(1000);
  RGB_color(64, 35, 0);
  delay(1000);
  RGB_color(125, 0, 125);
  delay(1000);
  RGB_color(125, 125, 125);
  delay(1000);
  RGB_color(50,0,125);
  delay(3000);
 
}
