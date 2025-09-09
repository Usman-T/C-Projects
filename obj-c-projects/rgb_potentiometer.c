int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int redRead = A0;
int greenRead = A1;
int blueRead = A2;

float redReadVal;
float greenReadVal;
float blueReadVal;

float redVal = 0;
float greenVal = 0;
float blueVal = 0;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  redReadVal = analogRead(redRead);
  greenReadVal = analogRead(greenRead);
  blueReadVal = analogRead(blueRead);
  
  redVal = redReadVal * (255.0 / 1023.0);
  greenVal = greenReadVal * (255.0 / 1023.0);
  blueVal = blueReadVal * (255.0 / 1023.0);

  Serial.print(redVal);
  Serial.print(" ");
  Serial.print(greenVal);
  Serial.print(" ");
  Serial.print(blueVal);
  
  Serial.println(" ");
  
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}
