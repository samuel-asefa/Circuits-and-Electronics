const int TRIG_PIN = 16;
const int ECHO_PIN = 17;

const int RED = 15;
const int YELLOW = 14;
const int GREEN = 13;

const int BUZZER = 18;

const int digitPins[4] = {0, 1, 2, 3};
const int segmentPins[8] = {4, 5, 6, 7, 8, 9, 10, 11};

const byte numbers[10][8] = {
  {0,0,0,0,0,0,1,1},
  {1,0,0,1,1,1,1,1},
  {0,0,1,0,0,1,0,1},
  {0,0,0,0,1,1,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,1,0,0,1},
  {0,1,0,0,0,0,0,1},
  {0,0,0,1,1,1,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,1,0,0,1}
};

void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  for(int i=0;i<4;i++) pinMode(digitPins[i], OUTPUT);
  for(int i=0;i<8;i++) pinMode(segmentPins[i], OUTPUT);
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

void clearDigits() {
  for(int i=0;i<4;i++) digitalWrite(digitPins[i], LOW);
}

void displayDigit(int digit, int num) {
  clearDigits();
  for(int i=0;i<8;i++)
    digitalWrite(segmentPins[i], numbers[num][i] ? HIGH : LOW);
  digitalWrite(digitPins[digit], HIGH);
  delay(3);
}

void displayNumber(int value) {
  if(value > 9999) value = 9999;
  if(value < 0) value = 0;

  int d0 = (value / 1000) % 10;
  int d1 = (value / 100) % 10;
  int d2 = (value / 10) % 10;
  int d3 = value % 10;

  displayDigit(0, d0);
  displayDigit(1, d1);
  displayDigit(2, d2);
  displayDigit(3, d3);
}

void loop() {
  float distance = getDistance();
  int distInt = (int)distance;

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
  }

  for(int i=0;i<40;i++) displayNumber(distInt);
}
