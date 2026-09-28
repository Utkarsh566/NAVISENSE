/*
  Smart Assistive Stick - GPS Test

  NEO-6M:
  GPS TX -> Arduino D2
  GPS RX -> Arduino D3
  Baud   -> 9600

  Library: TinyGPS++
*/

#include <SoftwareSerial.h>
#include <TinyGPS++.h>

static const int GPS_RX = 2; // Arduino receives from GPS TX
static const int GPS_TX = 3; // Arduino transmits to GPS RX

SoftwareSerial gpsSerial(GPS_RX, GPS_TX);
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("GPS test started");
}

void loop() {
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (gps.location.isUpdated()) {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Satellites: ");
    Serial.println(gps.satellites.value());
  }
}
