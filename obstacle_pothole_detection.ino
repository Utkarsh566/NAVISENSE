/*
  Smart Assistive Stick
  Arduino Nano - Obstacle + Ground/Pothole Detection

  Obstacle TRIG = D9
  Obstacle ECHO = D8
  Ground TRIG   = D6
  Ground ECHO   = D7
  Buzzer        = D5
*/

const int trigObstacle = 9;
const int echoObstacle = 8;
const int trigPothole = 6;
const int echoPothole = 7;
const int buzzerPin = 5;

const float OBSTACLE_WARNING_CM = 15.0;
const float OBSTACLE_URGENT_CM = 10.0;

// Calibrate this reference for your physical sensor mounting.
const float GROUND_REFERENCE_CM = 30.0;
const float GROUND_CHANGE_CM = 8.0;

long readDistanceCm(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);
  if (duration == 0) return -1;

  return (long)(duration * 0.0343 / 2.0);
}

void setup() {
  pinMode(trigObstacle, OUTPUT);
  pinMode(echoObstacle, INPUT);
  pinMode(trigPothole, OUTPUT);
  pinMode(echoPothole, INPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  Serial.begin(9600);
}

void loop() {
  long obstacleDistance = readDistanceCm(trigObstacle, echoObstacle);
  delay(30);
  long groundDistance = readDistanceCm(trigPothole, echoPothole);

  Serial.print("Obstacle: ");
  Serial.print(obstacleDistance);
  Serial.print(" cm | Ground: ");
  Serial.print(groundDistance);
  Serial.println(" cm");

  bool urgentObstacle =
      obstacleDistance > 0 && obstacleDistance <= OBSTACLE_URGENT_CM;

  bool closeObstacle =
      obstacleDistance > 0 && obstacleDistance <= OBSTACLE_WARNING_CM;

  bool possiblePothole =
      groundDistance > 0 &&
      abs(groundDistance - GROUND_REFERENCE_CM) >= GROUND_CHANGE_CM;

  if (urgentObstacle) {
    tone(buzzerPin, 2200);
    delay(800);
    noTone(buzzerPin);
  } else if (closeObstacle) {
    tone(buzzerPin, 1800);
    delay(250);
    noTone(buzzerPin);
  } else if (possiblePothole) {
    tone(buzzerPin, 1200);
    delay(600);
    noTone(buzzerPin);
  } else {
    noTone(buzzerPin);
  }

  delay(100);
}
