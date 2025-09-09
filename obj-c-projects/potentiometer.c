int redPin = 13;
int yellowPin = 12;
int greenPin = 11;
int readPin = A2;

float V = 0;
int readVal;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  readVal = analogRead(readPin);
  V = (5.0 / 1023.0) * readVal;
  
  Serial.println(V);
  
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  
  if (V < 2) {
    digitalWrite(greenPin, HIGH);
  }
  else if (V >= 2 && V < 4) {
    digitalWrite(yellowPin, HIGH);
  }
  else if (V >= 4) {
    digitalWrite(redPin, HIGH);
  }
}
