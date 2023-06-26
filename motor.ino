int MotorPin1 = D0; //in 1 ขา D0
int MotorPin2 = D1; //in 2 ขา D1
int MotorPin3 = D2; //in 3 ขา D2
int MotorPin4 = D4; //in 4 ขา D3

void setup() {
  pinMode(MotorPin1, OUTPUT); //ตั้งค่า MotorPin1 เป็น OUTPUT
  pinMode(MotorPin2, OUTPUT); //ตั้งค่า MotorPin2 เป็น OUTPUT
  pinMode(MotorPin3, OUTPUT); //ตั้งค่า MotorPin3 เป็น OUTPUT
  pinMode(MotorPin4, OUTPUT); //ตั้งค่า MotorPin4 เป็น OUTPUT
  Serial.begin(9600);
}

void loop() {

  /////Right/////
  digitalWrite(MotorPin1, HIGH);  //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT1
  digitalWrite(MotorPin2, LOW);   //สั่งงานให้ขา OUT2  เป็นขารับไฟจากขา OUT3
  digitalWrite(MotorPin3, HIGH);  //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT3
  digitalWrite(MotorPin4, LOW);   //สั่งงานให้ขา OUT4  เป็นขารับไฟจากขา OUT3
  Serial.println("Motor Right");
  delay(2000);  //หน่วงเวลา 2 วินาที

  /////Motor STOP/////
  digitalWrite(MotorPin1, LOW);  //สั่งงานให้ขา OUT1 หยุดจ่ายไฟ
  digitalWrite(MotorPin2, LOW);  //สั่งงานให้ขา OUT2 หยุดจ่ายไฟ
  digitalWrite(MotorPin1, LOW);  //สั่งงานให้ขา OUT3 หยุดจ่ายไฟ
  digitalWrite(MotorPin2, LOW);  //สั่งงานให้ขา OUT4 หยุดจ่ายไฟ
  Serial.println("Motor STOP");
  delay(2000); //หน่วงเวลา 2 วินาที

  /////Left/////
  digitalWrite(MotorPin1, LOW);   //สั่งงานให้ขา OUT1  เป็นขารับไฟจากขา OUT2
  digitalWrite(MotorPin2, HIGH);  //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT2
  digitalWrite(MotorPin3, LOW);   //สั่งงานให้ขา OUT3  เป็นขารับไฟจากขา OUT4
  digitalWrite(MotorPin4, HIGH);  //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT4
  Serial.println("Motor Left");
  delay(2000); //หน่วงเวลา 2 วินาที

  /////Forward/////
  digitalWrite(MotorPin1, LOW);   //สั่งงานให้ขา OUT1  เป็นขารับไฟจากขา OUT2
  digitalWrite(MotorPin2, HIGH);  //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT2
  digitalWrite(MotorPin3, HIGH);  //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT3
  digitalWrite(MotorPin4, LOW);   //สั่งงานให้ขา OUT4  เป็นขารับไฟจากขา OUT3
  Serial.println("Forward");
  delay(2000); //หน่วงเวลา 2 วินาที

  /////Backward/////
  digitalWrite(MotorPin1, LOW);   //สั่งงานให้ขา OUT1  เป็นขารับไฟจากขา OUT2
  digitalWrite(MotorPin2, HIGH);  //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT2
  digitalWrite(MotorPin3, HIGH);  //สั่งงานให้โมดูลขับมอเตอร์จ่ายไฟ ออกขา OUT3
  digitalWrite(MotorPin4, LOW);   //สั่งงานให้ขา OUT4  เป็นขารับไฟจากขา OUT3
  Serial.println("Backward");
  delay(2000); //หน่วงเวลา 2 วินาที
}