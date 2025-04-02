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
}

void loop() {
  int leftValue = analogRead(ldrLeft);    // อ่านค่า LDR ซ้าย
  int rightValue = analogRead(ldrRight);  // อ่านค่า LDR ขวา

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print(" | Right: ");
  Serial.print(rightValue);
  Serial.print(" | Servo Position: ");
  Serial.print(servoPos);

  int diff = leftValue - rightValue;  // คำนวณความแตกต่างของค่าแสง
  Serial.print(" | diff: ");
  Serial.println(diff);
  if (abs(diff) <= tolerance) {
    // แสงแดดอยู่ตรงกลาง -> เซอร์โวอยู่ที่ 90 องศา
    servoPos = 90;
  } else if (diff > tolerance) {
    // แสงมาทางซ้าย -> หมุนไปทางซ้าย (ตะวันตก)
    if (diff > 200) {
      servoPos = 30;  // หมุนไปทางซ้ายมาก
    } else if (diff > 100) {
      servoPos = 60;  // หมุนไปทางซ้ายปานกลาง
    } else {
      servoPos = 75;  // หมุนไปทางซ้ายเล็กน้อย
    }
  } else if (diff < -tolerance) {
    // แสงมาทางขวา -> หมุนไปทางขวา (ตะวันออก)
    if (diff < -200) {
      servoPos = 150;  // หมุนไปทางขวามาก
    } else if (diff < -100) {
      servoPos = 120;  // หมุนไปทางขวาปานกลาง
    } else {
      servoPos = 105;  // หมุนไปทางขวาเล็กน้อย
    }
  }

  myServo.write(servoPos);  // อัพเดตตำแหน่ง Servo
  delay(200);               // หน่วงเวลาเพื่อป้องกันการแกว่งของเซอร์โว
}
