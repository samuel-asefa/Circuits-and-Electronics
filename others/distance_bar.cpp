const int TRIG = 16;
const int ECHO = 17;
const int RED = 15;
const int YELLOW = 14;
const int GREEN = 13;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
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

  digitalWrite(RED, d < 20);
  digitalWrite(YELLOW, d < 40);
  digitalWrite(GREEN, d < 60);

  delay(200);
}