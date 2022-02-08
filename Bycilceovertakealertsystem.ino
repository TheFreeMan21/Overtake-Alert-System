const int trigPin = 8;
const int echoPin = 9;
const int pwmPin = 5;
int x=0;
int y=0;
#define Speed_of_Sound 0.034
long duration;
float distance;

void setup()
{
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance = duration * Speed_of_Sound/2;
  
  Serial.print("The distance is: ");
  Serial.println(distance);

  x=distance;
  if(y-x>=90&&x<200)
  {
    Serial.print("Someone comes");
    analogWrite(pwmPin,255);
    delay(1000);
    analogWrite(pwmPin,0);
  }
  else
    if(x<200)
       y=x;
  
  delay(1000);
}
