int ledPin = 10;
int lighterPin = 11;
int dimmerPin = 12;
int buzzerPin = 13;

int dimmerVal = 1;
int lighterVal = 1;

int brightness = 255;
int step = 10;

int MIN = 0;
int MAX = 255;

int dt = 100;

void setup() {
  pinMode(lighterPin, INPUT);
  pinMode(dimmerPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  dimmerVal = digitalRead(dimmerPin);
  lighterVal = digitalRead(lighterPin);

  if (lighterVal == 0 && ((brightness + step) <= MAX)) {
    brightness += step;
    digitalWrite(buzzerPin, HIGH);
    delay(dt);
    digitalWrite(buzzerPin, LOW);
  }

  if (dimmerVal == 0 && ((brightness - step) >= MIN)) {
    brightness -= step;
    digitalWrite(buzzerPin, HIGH);
    delay(dt);
    digitalWrite(buzzerPin, LOW);
  }

  analogWrite(ledPin, brightness);
  Serial.println(brightness);

  delay(dt);
}
