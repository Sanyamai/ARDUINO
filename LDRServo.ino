#include <Servo.h>

Servo myServo;  // สร้างออบเจ็กต์ Servo
int ldrPin = A0; // กำหนดขา LDR
int servoPin = 9; // กำหนดขา Servo

void setup() {
  myServo.attach(servoPin); // กำหนดขาให้ Servo
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin); // อ่านค่าจาก LDR (0-1023)
  int servoAngle = map(ldrValue, 0, 974, 0, 180); // แปลงค่า LDR เป็นมุม 0-180 องศา
  myServo.write(servoAngle); // สั่งให้ Servo หมุนไปที่มุมนั้น

  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | Servo Angle: ");
  Serial.println(servoAngle);

  delay(100); // หน่วงเวลา
}