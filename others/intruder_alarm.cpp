const int TRIG = 16;
const int ECHO = 17;
const int RED = 15;
const int BUZZER = 18;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH, 30000);
  return duration * 0.0343 / 2.0;
}

void loop() {
  float d = getDistance();
  Serial.println(d);

  if (d < 20 && d > 0) {
    digitalWrite(RED, HIGH);
    tone(BUZZER, 2500);
  } else {
    digitalWrite(RED, LOW);
    noTone(BUZZER);
  }

  delay(200);
}