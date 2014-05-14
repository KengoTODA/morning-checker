// see http://playground.arduino.cc/Code/Time
#include <Time.h>

#include <Servo.h>

unsigned int GREEN = 12;
unsigned int RED = 8;
unsigned int SERVO = 9;

unsigned int LIMIT = 30; // mins

Servo servo;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  servo.attach(SERVO);
  servo.write(180);

  Serial.begin(9600);
}

void loop() {
  Serial.print(minute());
  Serial.print(" ");
  Serial.print(second());
  Serial.println();

  if (minute() < LIMIT) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  } else {
    digitalWrite(GREEN, LOW);
    if (second() % 2) {
      digitalWrite(RED, HIGH);
    } else {
      digitalWrite(RED, LOW);
    }

    if (minute() == LIMIT) {
      servo.write(180 - second() * 2);
    }
  }
  delay(200);
}

