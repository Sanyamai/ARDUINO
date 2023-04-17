#include <Servo.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <BH1750FVI.h>
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

#include <SPI.h>
#include <SD.h>
int sensor = A0;  //
int val = 0;
File myFile;  // สร้างออฟเจก File สำหรับจัดการข้อมูล
const int chipSelect = 4;

Servo myservo;
int b;
int time = 1;
String result = "";

void setup() {
  Serial.begin(9600);
  pinMode(9, INPUT);
  myservo.attach(8);
  myservo.write(0);
  Serial.println("DHT11 test!");
  dht.begin();
  Serial.println("TEST BH1750");
  LightSensor.begin();
 

  /////SD CARD///////
  while (!Serial) {
    ;
  }
  Serial.print("Initializing SD card...");
  pinMode(SS, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  myFile = SD.open("cansat.txt", FILE_WRITE);
  myFile.print("Time");
  myFile.print(",");
  myFile.print("Humidity %");
  myFile.print(",");
  myFile.print("Temperature C ํ ");
  myFile.print(",");
  myFile.print("Temperature F ");
  myFile.print(",");
  myFile.print("Heat index");
  myFile.print(",");
  myFile.print("Light");
  myFile.print(",");
  myFile.println("CO-2");

  myFile.close();
    Serial.print("END SETUP");
}

void loop() {
  //static unsigned long Time = millis();
  /*
  if (time > 10) {
    time = 1;
  }
*/
  b = digitalRead(9);
  Serial.println(b);

  if (b == 0) {
    Serial.println(b);
    delay(3000);
    myservo.write(180);
    delay(5000);
    myservo.write(0);
  }

////////////DHT11//////////////////
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  float hi = dht.computeHeatIndex(f, h);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hi);
  Serial.println(" *F");
  
  
/////////////LightSenso///////////////
  uint16_t lux = LightSensor.GetLightIntensity();  // อ่านค่าความเ้ข้มแสง หน่วยเป็น LUX
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lux");

/////////////MQ-2//////////////////
  val = analogRead(sensor);
  Serial.println(val);


///////////////sd card/////////////
  myFile = SD.open("cansat.txt", FILE_WRITE);
  result = String(time) + "," + String(h) + "," + String(t) + "," + String(f) + "," + String(hi) + "," + String(lux) + "," + String(val);
  if (myFile) {
    Serial.println("Now writing obtained data to Moisture.csv...");
    myFile.println(result);
    myFile.close();
  } else {
    Serial.println("error opening cansat.txt");
  }
  Serial.println();

  time++;
  delay(1000);
  //delay(900000);

Serial.println("*********");
}