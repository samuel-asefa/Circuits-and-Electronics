const int TRIG = 16;
const int ECHO = 17;

const int RED = 15;
const int YELLOW = 14;
const int GREEN = 13;

const int BUZZER = 18;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
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

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  if (d < 10) {
    digitalWrite(RED, HIGH);
    tone(BUZZER, 3000);
  } 
  else if (d < 25) {
    digitalWrite(YELLOW, HIGH);
    tone(BUZZER, 2000);
  } 
  else if (d < 60) {
    digitalWrite(GREEN, HIGH);
    tone(BUZZER, 1000);
  } 
  else {
    noTone(BUZZER);
  }

  delay(100);
}