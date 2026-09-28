/*
  Smart Assistive Stick - ThingSpeak Monitoring Template

  Replace the placeholders locally. Never commit real Wi-Fi
  passwords or ThingSpeak API keys to a public repository.

  ESP8266 example.
*/

#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

const char* WIFI_SSID = "YOUR_WIFI_SSID";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

unsigned long CHANNEL_ID = 0;
const char* THINGSPEAK_API_KEY = "YOUR_WRITE_API_KEY";

WiFiClient client;

void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi connected");

  ThingSpeak.begin(client);
}

void loop() {
  // Replace these with values received from the Arduino
  // or measured directly by the ESP.
  float obstacleDistance = 0;
  float groundDistance = 0;
  float latitude = 0;
  float longitude = 0;

  ThingSpeak.setField(1, obstacleDistance);
  ThingSpeak.setField(2, groundDistance);
  ThingSpeak.setField(3, latitude);
  ThingSpeak.setField(4, longitude);

  int response = ThingSpeak.writeFields(CHANNEL_ID, THINGSPEAK_API_KEY);

  Serial.print("ThingSpeak response: ");
  Serial.println(response);

  delay(15000);
}
