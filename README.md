🦯 Smart Assistive Stick for Visually Impaired Individuals
An IoT-enabled assistive walking stick prototype using dual ultrasonic sensing, GPS tracking, audible alerts, and ThingSpeak cloud monitoring.

Features
Front obstacle detection
Ground/pothole hazard detection
Buzzer-based local warning
NEO-6M GPS location tracking
ESP8266/ESP32 Wi-Fi/IoT architecture
ThingSpeak monitoring
Modular Arduino and ESP firmware
Extensible emergency-alert architecture
Architecture
Ultrasonic #1 ─┐
               ├──> Arduino Nano ──> Buzzer
Ultrasonic #2 ─┘
                      │
                      ├── Sensor data ──> ESP8266/ESP32 ──> Wi-Fi ──> ThingSpeak
                      │
NEO-6M GPS ───────────┘
Hardware
Component	Purpose
Arduino Nano	Local sensor processing
Ultrasonic Sensor ×2	Obstacle and ground-hazard detection
Buzzer	Audible warning
NEO-6M GPS	Location tracking
ESP8266 / ESP32	Wi-Fi and IoT communication
Battery/power supply	Portable power
Walking stick	Mechanical platform
Arduino Pin Configuration
Function	Pin
Obstacle TRIG	D9
Obstacle ECHO	D8
Pothole TRIG	D6
Pothole ECHO	D7
Buzzer	D5
GPS RX	D2
GPS TX	D3
GPS baud	9600
Working
Ultrasonic sensors measure distance using echo time.
Arduino calculates distances and checks thresholds.
A detected hazard activates the buzzer.
NEO-6M provides latitude and longitude.
ESP8266/ESP32 provides Wi-Fi connectivity.
ThingSpeak can store and visualize sensor/location data.
Future versions can add IMU-based fall detection and emergency notification.
Important Prototype Note
Ultrasonic sensing detects distance changes; it does not guarantee perfect classification of every road defect as a pothole. GPS provides location but does not itself detect an accident. Automatic accident detection should use an IMU/accelerometer and an appropriate algorithm.

Repository Structure
smart-assistive-stick/
├── README.md
├── LICENSE
├── CONTRIBUTING.md
├── .gitignore
├── docs/
│   ├── system-architecture.md
│   ├── circuit-diagram.md
│   └── project-flow.md
├── hardware/
│   ├── components.md
│   ├── pin-configuration.md
│   └── wiring.md
├── arduino/
│   ├── obstacle-pothole-detection/
│   │   └── obstacle_pothole_detection.ino
│   └── gps/
│       └── gps_tracking.ino
├── esp/
│   ├── thingspeak/
│   │   └── thingspeak_monitoring.ino
│   └── gps-iot/
│       └── gps_iot_architecture.ino
├── cloud/
│   └── thingspeak/
│       └── channel-configuration.md
└── images/
    └── README.md
Software
Arduino IDE
Arduino C/C++
TinyGPS++
ESP8266WiFi / ESP32 WiFi libraries
ThingSpeak
Future Improvements
MPU6050/IMU-based fall detection
Emergency SMS/app notification
Voice feedback
Mobile dashboard
Better pothole classification
Battery monitoring
AI-based obstacle classification
Route/hazard history
Project Type
Embedded Systems + IoT + Assistive Technology + GPS

Disclaimer
This is an academic/prototype project and is not a certified mobility or safety device.
