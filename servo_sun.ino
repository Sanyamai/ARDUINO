#include <Servo.h>

Servo myServo;

int ldrLeft = A0;
int ldrRight = A1;

int pos = 90;  // ตำแหน่งเริ่มต้นของเซอร์โว

//************************************
// คาลิเบรตเริ่มต้น: สมมุติว่าอุปกรณ์หันไปตรงกลางและแสงเท่ากัน
int ldrLeftBase = 147;
int ldrRightBase = 260;
//************************************
void setup() {
  myServo.attach(9);
  myServo.write(pos);
  Serial.begin(9600);

  // คาลิเบรตเริ่มต้น: สมมุติว่าอุปกรณ์หันไปตรงกลางและแสงเท่ากัน
  ldrLeftBase = analogRead(ldrLeft);
  ldrRightBase = analogRead(ldrRight);

  Serial.print("Calibrated base values -> ");
  Serial.print("Left: ");
  Serial.print(ldrLeftBase);
  Serial.print(" | Right: ");
  Serial.println(ldrRightBase);
}

void loop() {
  int leftValueRaw = analogRead(ldrLeft);
  int rightValueRaw = analogRead(ldrRight);

  // ค่าที่ผ่านการคาลิเบรต
  int leftValue = leftValueRaw - ldrLeftBase;
  int rightValue = rightValueRaw - ldrRightBase;

  Serial.print("LeftRaw: ");
  Serial.print(leftValueRaw);
  Serial.print(" | RightRaw: ");
  Serial.print(rightValueRaw);
  Serial.print(" || Calibrated -> Left: ");
  Serial.print(leftValue);
  Serial.print(" | Right: ");
  Serial.print(rightValue);
  Serial.print(" | ");

  int threshold = 50;  // ค่าความต่างที่ยอมรับได้

  // ถ้าแสงใกล้เคียงกัน → หมุนกลับตำแหน่งกลาง
  if (abs(leftValue - rightValue) <= threshold) {
    pos = 90;
    myServo.write(pos);
    Serial.print("Centered | ");
  }
  // ถ้าแสงไม่เท่ากัน → ปรับทิศ
  else {
    if (leftValue > rightValue && pos < 140) {
      pos++;
    } else if (rightValue > leftValue && pos > 50) {
      pos--;
    }
    myServo.write(pos);
  }

  Serial.print("Servo Pos: ");
  Serial.println(pos);
  delay(100);
}
