#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHTPIN 4        // Pin ที่เชื่อมต่อกับ DHT11
#define DHTTYPE DHT11   // ประเภทของเซ็นเซอร์ DHT

const char* ssid = "YOUR_SSID";        // ชื่อ Wi-Fi
const char* password = "YOUR_PASSWORD"; // รหัสผ่าน Wi-Fi
const char* mqtt_server = "iot.varee.ac.th";  // Use your private broker IP
const char* mqtt_user = "root";               // MQTT username
const char* mqtt_password = "Varee123";       // MQTT password

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {
  Serial.begin(115200);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    snprintf (msg, 50, "Temperature: %2.2f, Humidity: %2.2f", t, h);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("home/garden/temperature", String(t).c_str());
    client.publish("home/garden/humidity", String(h).c_str());
  }
}