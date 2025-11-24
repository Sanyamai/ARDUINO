// Motor A
int IN1 = 2;
int IN2 = 3;

// Motor B
int IN3 = 4;
int IN4 = 5;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

// ฟังก์ชันควบคุมมอเตอร์ A
void motorA_forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void motorA_backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void motorA_stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

// ฟังก์ชันควบคุมมอเตอร์ B
void motorB_forward() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void motorB_backward() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void motorB_stop() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  // ทั้งสองมอเตอร์หมุนไปข้างหน้า
  motorA_forward();
  motorB_forward();
  delay(2000);

  // หมุนถอยหลัง
  motorA_backward();
  motorB_backward();
  delay(2000);

  // หยุด
  motorA_stop();
  motorB_stop();
  delay(2000);
}
