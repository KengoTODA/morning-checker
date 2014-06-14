#include <Wire.h>

// see https://code.google.com/p/arms22/downloads/detail?name=RTC8564-001.zip
// see http://arms22.blog91.fc2.com/blog-entry-232.html
#include <RTC8564.h>

// see http://playground.arduino.cc/Code/Time
#include <Time.h>

#include <Servo.h>

unsigned int GREEN = 12;
unsigned int RED = 8;
unsigned int SERVO = 9;

unsigned int LIMIT = 13; // hour

Servo servo;

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);

  servo.attach(SERVO);
  servo.write(180);

  Serial.begin(9600);
  Rtc.begin();
}

void loop() {
  Rtc.available();
  Serial.print(0x2000+Rtc.years(),HEX);
  Serial.print("/");
  Serial.print(Rtc.months(),HEX);
  Serial.print("/");
  Serial.print(Rtc.days(),HEX);
  Serial.print(" ");
  Serial.print(Rtc.hours(),HEX);
  Serial.print(":");
  Serial.print(Rtc.minutes(),HEX);
  Serial.print(":");
  Serial.println(Rtc.seconds(),HEX);

  if (Rtc.hours() < LIMIT) {
    if (Rtc.hours() == (LIMIT - 1) && Rtc.minutes() == 59) {
      digitalWrite(GREEN, (Rtc.seconds() % 2) ? HIGH : LOW);
    } else {
      digitalWrite(GREEN, HIGH);
    }
    digitalWrite(RED, LOW);
    servo.write(0);
  } else if (Rtc.hours() > LIMIT) {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, LOW);
  } else {
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, (Rtc.seconds() % 2) ? HIGH : LOW);

    if (Rtc.minutes() == 0) {
      servo.write(180 - Rtc.seconds() * 2);
    }
  }
  delay(200);
}

