# System Architecture

```text
                 SMART ASSISTIVE STICK
                          |
        +-----------------+-----------------+
        |                 |                 |
        v                 v                 v
 Ultrasonic #1      Ultrasonic #2       NEO-6M GPS
  Obstacle           Ground Hazard       Location
        |                 |                 |
        +-----------------+--------+--------+
                                  |
                                  v
                            Arduino Nano
                                  |
                         +--------+--------+
                         |                 |
                         v                 v
                      Buzzer          Sensor Data
                                           |
                                           v
                                    ESP8266 / ESP32
                                           |
                                           v
                                          Wi-Fi
                                           |
                                           v
                                      ThingSpeak
                                           |
                                           v
                                  Remote Monitoring
```

## Responsibility Split

### Arduino Nano
- Read ultrasonic sensors
- Calculate distance
- Apply local warning thresholds
- Drive buzzer

### GPS
- Acquire latitude/longitude

### ESP8266/ESP32
- Wi-Fi connection
- Cloud communication

### ThingSpeak
- Store and visualize time-series data
