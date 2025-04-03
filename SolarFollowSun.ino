#include <Servo.h>

Servo myServo;
const int ldrLeft = A0;   // LDR ซ้าย
const int ldrRight = A1;  // LDR ขวา
const int servoPin = 9;
const int tolerance = 30;  // ค่าความแตกต่างที่ยอมรับได้

int servoPos = 90;  // เริ่มต้นที่ 90 องศา

void setup() {
  myServo.attach(servoPin);
  myServo.write(servoPos);  // กำหนดมุมเริ่มต้น
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  int leftValue = analogRead(ldrLeft);    // อ่านค่า LDR ซ้าย
  int rightValue = analogRead(ldrRight);  // อ่านค่า LDR ขวา

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print(" | Right: ");
  Serial.print(rightValue);


  int diff = rightValue - leftValue;  // คำนวณความแตกต่างของค่าแสง (สลับทิศ)
  Serial.print(" | diff: ");
  Serial.print(diff);
  Serial.print(" | Servo Position: ");
  Serial.println(servoPos);

  if (abs(diff) <= tolerance) {
    // แสงแดดอยู่ตรงกลาง -> เซอร์โวอยู่ที่ 90 องศา
    servoPos = 90;
  } else if (diff > tolerance) {
    // แสงมาทางขวา (ขวาสว่างมากกว่า) -> หมุนไปทางขวา
    if (diff > 50) {
      servoPos = 150;
    } else if (diff > 100) {
      servoPos = 120;
    } else {
      servoPos = 105;
    }
  } else if (diff < -tolerance) {
    // แสงมาทางซ้าย (ซ้ายสว่างมากกว่า) -> หมุนไปทางซ้าย
    if (diff < 0) {
      servoPos = 30;
    } else if (diff < -50) {
      servoPos = 60;
    } else {
      servoPos = 75;
    }
  }

  myServo.write(servoPos);  // อัพเดตตำแหน่ง Servo
  delay(200);               // หน่วงเวลาเพื่อป้องกันการแกว่งของเซอร์โว
}
