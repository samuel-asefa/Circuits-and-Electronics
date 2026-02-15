const int TRIG_PIN = 16;
const int ECHO_PIN = 17;

const int RED = 15;
const int YELLOW = 14;
const int GREEN = 13;

const int BUZZER = 18;

void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUZZER, OUTPUT);
}

float getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  return duration * 0.0343 / 2.0;
}

void beep(int delayTime) {
  tone(BUZZER, 2000);
  delay(80);
  noTone(BUZZER);
  delay(delayTime);
}

void loop() {
  float distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  if (distance > 0 && distance < 10) {
    digitalWrite(RED, HIGH);
    beep(100);
  }
  else if (distance >= 10 && distance < 25) {
    digitalWrite(YELLOW, HIGH);
    beep(300);
  }
  else if (distance >= 25 && distance < 60) {
    digitalWrite(GREEN, HIGH);
    beep(600);
  }
  else {
    noTone(BUZZER);
    delay(200);
  }
}
