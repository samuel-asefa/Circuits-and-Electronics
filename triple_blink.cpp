const int RED = 15;
const int YELLOW = 14;
const int GREEN = 13;

void setup() {
  Serial.begin(115200);
  delay(2000);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  Serial.println("Triple Blink");
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, HIGH);
  delay(100);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  delay(100);
}
