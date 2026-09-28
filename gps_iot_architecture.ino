/*
  ESP GPS/IoT Architecture Reference

  Suggested packet between Arduino and ESP:
  OBS=<cm>,GROUND=<cm>,LAT=<lat>,LON=<lon>,ALERT=<0/1>

  Example:
  OBS=24,GROUND=31,LAT=18.520400,LON=73.856700,ALERT=0

  Implement the selected UART/I2C protocol according to the
  final physical wiring.
*/

void setup() {
  Serial.begin(115200);
  Serial.println("ESP IoT architecture template");
}

void loop() {
  // Receive validated sensor/GPS data and forward it to cloud.
  delay(1000);
}
