//ultrasonic pin
int echoPin = 6;
int trigPin = 7;
long duration;
int distance;

void setup()
{
  pinMode(echoPin, INPUT); //echo
  pinMode(trigPin, OUTPUT); //trig
  Serial.begin(9600);
}

void ultrasonic() //ultrasonic
{
  delay(1000); // 2-second delay
  digitalWrite(trigPin, LOW); //ultrasonic trig pin
  delayMicroseconds(2);

  //ultrasonic trig pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //ultrasonic echo pin
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
}

void loop()
{
  ultrasonic(); //ultrasonic
  Serial.print("Distance between Ultrasonic and Obstacle: ");
  Serial.println(distance);
  
}
