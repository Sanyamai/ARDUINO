#include <Servo.h>
Servo myservo;
int b;
void setup() {
  Serial.begin(9600);
  pinMode(4, INPUT);
  myservo.attach(12);
  myservo.write(0);
}
void loop() {
  b = digitalRead(4);
  Serial.println(b);
  if (b == 0) {
    Serial.println(b);
    delay(3000);
    myservo.write(180);
    delay(5000);
    myservo.write(0);
  }
}