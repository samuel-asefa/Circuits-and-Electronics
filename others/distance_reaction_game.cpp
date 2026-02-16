const int TRIG = 16;
const int ECHO = 17;
const int GREEN = 13;
const int RED = 15;
const int BUZZER = 18;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  randomSeed(analogRead(26));
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
  delay(random(2000,5000));
  digitalWrite(GREEN, HIGH);

  unsigned long start = millis();
  while (true) {
    if (getDistance() < 15) {
      unsigned long reaction = millis() - start;
      Serial.print("Reaction Time: ");
      Serial.println(reaction);
      digitalWrite(GREEN, LOW);
      tone(BUZZER, 2000, 200);
      break;
    }
  }
  delay(3000);
}