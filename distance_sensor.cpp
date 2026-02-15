const int TRIG_PIN = 3;
const int ECHO_PIN = 2;

const int RED = 15;
const int YELLOW = 14;
const int GREEN = 13;

void setup() {
  Serial.begin(115200);
  delay(2000);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distance = duration * 0.0343 / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  if (distance > 0 && distance < 10) {
    digitalWrite(RED, HIGH);
  } else if (distance >= 10 && distance < 25) {
    digitalWrite(YELLOW, HIGH);
  } else if (distance >= 25 && distance < 60) {
    digitalWrite(GREEN, HIGH);
  }

  delay(200);
}
