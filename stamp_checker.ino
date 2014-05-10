unsigned int GREEN = 12;
unsigned int RED = 8;

unsigned long time;
unsigned long HOUR = 1 * 60 * 60 * 1000; // ms

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  time = millis();
  if (time < HOUR) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  } else {
    digitalWrite(GREEN, LOW);
    if ((time / 1000) % 2) {
      digitalWrite(RED, HIGH);
    } else {
      digitalWrite(RED, LOW);
    }
  }
  delay(200);
}

