// see http://playground.arduino.cc/Code/Time
#include <Time.h>

#include <Servo.h>

unsigned int GREEN = 12;
unsigned int RED = 8;
unsigned int SERVO = 9;
Servo servo;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  servo.attach(SERVO);

  // TODO: needed? setTime(0, 0, 0, 1, 1, 2014);
}

void loop() {
  if (minute() < 10) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
    servo.write(0);
  } else {
    digitalWrite(GREEN, LOW);
    if (second() % 2) {
      digitalWrite(RED, HIGH);
    } else {
      digitalWrite(RED, LOW);
    }

    if (minute() == 10) {
      servo.write(second() * 3);
    } else {
      servo.write(180);
    }
  }
  delay(200);
}

