#include <Servo.h>

Servo myservo;
int L1, L2, x, degree = 90;

void setup() {
  myservo.attach(9);
  myservo.write(90);  // ตั้งค่าเริ่มต้น
  Serial.begin(9600);
  delay(3000);
}

void loop() {
  L1 = analogRead(A0);
  L2 = analogRead(A1);
  x = L1 - L2;

  Serial.print("L1: ");
  Serial.print(L1);
  Serial.print(" | L2: ");
  Serial.print(L2);
  Serial.print(" | x: ");
  Serial.print(x);

  // ปรับค่ามุม degree ตามค่าความต่างของแสง
  if (x < 80) degree--;
  else if (x > 80) degree++;


  // จำกัดค่าของ degree ให้อยู่ในช่วง 30 - 150 องศา
  if (degree > 150) degree = 150;
  if (degree < 30) degree = 30;
  if ((x > 200) & (x < 300)) degree = 90 ;


  myservo.write(degree);  // ส่งค่ามุมไปที่เซอร์โว

  Serial.print(" | servo: ");
  Serial.println(degree);
  delay(100);
}
