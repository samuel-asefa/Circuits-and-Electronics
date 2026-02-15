const int RED = 15;
const int YELLOW = 14;
const int GREEN = 13;

void setup() {
  Serial.begin(115200);
  delay(2000);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  Serial.println("Random Flicker");
  digitalWrite(RED, random(0,2));
  digitalWrite(YELLOW, random(0,2));
  digitalWrite(GREEN, random(0,2));
  delay(100);
}
