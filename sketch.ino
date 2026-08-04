#include <WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// ==========================
// WiFi Settings
// ==========================
#define WLAN_SSID "Wokwi-GUEST"
#define WLAN_PASS ""

// ==========================
// Adafruit IO Settings
// ==========================
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883

#define ADAFRUIT_AIO_USERNAME "tarun_exp"
#define ADAFRUIT_AIO_KEY      "aio_qEwd89vl76UHAEbVEYnRAY6qz593"

// ==========================
// ESP32 Pins
// ==========================
#define TRIG_PIN    5
#define ECHO_PIN    18
#define LED_PIN     2
#define BUZZER_PIN  13

WiFiClient client;

Adafruit_MQTT_Client mqtt(
  &client,
  AIO_SERVER,
  AIO_SERVERPORT,
  ADAFRUIT_AIO_USERNAME,
  ADAFRUIT_AIO_KEY
);

Adafruit_MQTT_Publish distanceFeed =
  Adafruit_MQTT_Publish(&mqtt,
                        ADAFRUIT_AIO_USERNAME "/feeds/distance");

long duration;
float distance;

//----------------------------------

void connectWiFi() {

  if (WiFi.status() == WL_CONNECTED)
    return;

  Serial.print("Connecting to WiFi");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WLAN_SSID, WLAN_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

//----------------------------------

void MQTT_connect() {

  if (mqtt.connected())
    return;

  Serial.print("Connecting to Adafruit IO... ");

  int8_t ret;

  while ((ret = mqtt.connect()) != 0) {

    Serial.println(mqtt.connectErrorString(ret));

    mqtt.disconnect();

    delay(5000);
  }

  Serial.println("Connected!");
}

//----------------------------------

void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  noTone(BUZZER_PIN);

  Serial.println();
  Serial.println("==================================");
  Serial.println(" Cloud Connected Security Node");
  Serial.println("==================================");

  connectWiFi();
}

//----------------------------------

void loop() {

  connectWiFi();
  MQTT_connect();

  // Trigger Ultrasonic Sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  // Read Echo
  duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {

    Serial.println("No Echo Received");

    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);

    delay(1000);
    return;
  }

  // Calculate Distance
  distance = duration * 0.0343 / 2.0;

  Serial.print("Distance: ");
  Serial.print(distance, 2);
  Serial.println(" cm");

  // Upload to Adafruit IO
  if (distanceFeed.publish(distance)) {
    Serial.println("Uploaded to Adafruit IO");
  } else {
    Serial.println("Upload Failed");
  }

  // Alarm
  if (distance <= 20) {

    Serial.println(">>> INTRUDER DETECTED <<<");

    digitalWrite(LED_PIN, HIGH);

    tone(BUZZER_PIN, 1000);

  } else {

    digitalWrite(LED_PIN, LOW);

    noTone(BUZZER_PIN);
  }

  Serial.println("--------------------------------");

  delay(2000);
}