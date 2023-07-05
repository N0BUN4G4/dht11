#include<Servo.h>
Servo Servo1;
Servo Servo2;
int pos=0;
int buttonPin = 8;
int buttonstate = 0;

void setup()
{
  pinMode(buttonPin,INPUT);
  Servo1.attach(2);
  Servo2.attach(7);
}

void loop ()
{
  buttonstate = digitalRead(buttonPin);

  if (buttonstate == HIGH)
  {
  Servo1.write(90);
  delay(1000);
  Servo2.write(0);
  delay(1000);
  Servo1.write(0);
  delay(1000);
  Servo2.write(140);
   }
  else
  Servo1.write(0);
  Servo2.write(140);
}
