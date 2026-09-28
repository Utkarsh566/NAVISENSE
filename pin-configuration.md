# Pin Configuration

## Arduino Nano

| Device | Signal | Pin |
|---|---|---:|
| Obstacle ultrasonic | TRIG | D9 |
| Obstacle ultrasonic | ECHO | D8 |
| Pothole ultrasonic | TRIG | D6 |
| Pothole ultrasonic | ECHO | D7 |
| Buzzer | Signal | D5 |

## GPS

| GPS | Arduino |
|---|---:|
| TX | D2 |
| RX | D3 |
| Baud | 9600 |

Verify TX/RX direction and voltage compatibility for your specific module.

## ESP

ESP8266/ESP32 pins depend on the final board revision. Avoid applying 5 V logic directly to a 3.3 V-only ESP GPIO.
