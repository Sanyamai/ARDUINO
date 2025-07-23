#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
int lamp = 5;
int ldr = A0;
int rawValue = 0;
int val = 0;

Servo myServo;  // สร้างอ็อบเจกต์เซอร์โว

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ldr, INPUT);
  pinMode(lamp, OUTPUT);
  Serial.begin(9600);
  myServo.attach(6);  // เซอร์โวต่อที่ขา 6
}

void loop() {
  // ส่งคลื่นอัลตราโซนิก
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // รับเวลาการสะท้อนกลับ
  duration = pulseIn(echoPin, HIGH);

  // คำนวณระยะทาง (หน่วย: เซนติเมตร)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  rawValue = analogRead(ldr);  // อ่านค่าแสงจาก LDR
  val = map(rawValue, 0, 900, 0, 100);
  Serial.print("LDR: ");
  Serial.println(val);

  if (distance < 10) {
    myServo.write(170);
    Serial.println("Open");
    delay(1000);
  } else if (distance > 11) {
    myServo.write(10);
    delay(100);
  } else {
    myServo.write(10);
    delay(100);
  }

  if (val < 5){
    delay(1000);
    digitalWrite(lamp, LOW);
    delay(100);
  }
  else if (val > 5){
    digitalWrite(lamp, HIGH);
    delay(100);
  }

}