// see http://playground.arduino.cc/Code/Time
#include <Time.h>

unsigned int GREEN = 12;
unsigned int RED = 8;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  // TODO: needed? setTime(0, 0, 0, 1, 1, 2014);
}

void loop() {
  if (minute() < 10) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  } else {
    digitalWrite(GREEN, LOW);
    if (second() % 2) {
      digitalWrite(RED, HIGH);
    } else {
      digitalWrite(RED, LOW);
    }
  }
  delay(200);
}

