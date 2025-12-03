// Motor A
int IN1 = 2;
int IN2 = 3;
int ENA = 6;  // ขาปรับความเร็วมอเตอร์ซ้าย

// Motor B
int IN3 = 4;
int IN4 = 5;
int ENB = 7;  // ขาปรับความเร็วมอเตอร์ขวา

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}
void loop() {
  /*เดินหน้า*/
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 254);  // ความเร็วมอเตอร์ซ้าย
  analogWrite(ENB, 180);  // ความเร็วมอเตอร์ขวา
  delay(5000);

  /*หยุด*/
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
}
