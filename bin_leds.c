int pin1 = 7;
int pin2 = 8;
int pin3 = 12;
int pin4 = 13;
int delayVal = 2500;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void loop() {
  delay(delayVal);
  digitalWrite(pin1, HIGH);

  delay(delayVal);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);

  delay(delayVal);
  digitalWrite(pin1, HIGH);

  delay(delayVal);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);

  delay(delayVal);
  digitalWrite(pin1, HIGH);

  delay(delayVal);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);

  delay(delayVal);
  digitalWrite(pin1, HIGH);

  delay(delayVal);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);

  delay(delayVal);
  digitalWrite(pin1, HIGH);

  delay(delayVal);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);

  delay(delayVal);
  digitalWrite(pin1, HIGH);

  delay(delayVal);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);

  delay(delayVal);
  digitalWrite(pin1, HIGH);

  delay(delayVal);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);

  delay(delayVal);
  digitalWrite(pin1, HIGH);

  delay(5000);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}
