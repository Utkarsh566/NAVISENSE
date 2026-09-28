# Circuit Diagram

This repository documents the verified wiring as a text circuit reference.

```text
             +----------------+
             | Arduino Nano   |
             |                |
Obstacle TRIG| D9             |
Obstacle ECHO| D8             |
 Pothole TRIG| D6             |
 Pothole ECHO| D7             |
       Buzzer| D5             |
        GPS  | D2/D3          |
             +-------+--------+
                     |
                     | Sensor/location data
                     v
             +----------------+
             | ESP8266/ESP32  |
             | Wi-Fi + IoT    |
             +-------+--------+
                     |
                     v
                ThingSpeak
```

See `hardware/wiring.md` for detailed connections.
