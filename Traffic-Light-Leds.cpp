// Pin definitions
const int RED_PIN = 15;
const int YELLOW_PIN = 14;
const int GREEN_PIN = 13;

// Timing (milliseconds)
const int RED_TIME = 5000;
const int GREEN_TIME = 5000;
const int YELLOW_TIME = 2000;

void setup() {
  Serial.begin(115200);
  delay(2000); // Allow time for serial monitor to connect

  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  Serial.println("Traffic Light System Started");
}

void loop() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("RED Light ON");
  delay(RED_TIME);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("GREEN Light ON");
  delay(GREEN_TIME);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("YELLOW Light ON");
  delay(YELLOW_TIME);
}
