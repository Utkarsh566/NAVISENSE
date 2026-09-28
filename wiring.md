# Wiring Guide

## Obstacle Ultrasonic

```text
VCC  -> 5V
GND  -> GND
TRIG -> Arduino D9
ECHO -> Arduino D8
```

## Ground/Pothole Ultrasonic

```text
VCC  -> 5V
GND  -> GND
TRIG -> Arduino D6
ECHO -> Arduino D7
```

## Buzzer

```text
Buzzer + -> Arduino D5
Buzzer - -> GND
```

For a higher-current buzzer, use a suitable transistor/driver.

## GPS

```text
GPS TX -> Arduino D2
GPS RX -> Arduino D3
GPS GND -> GND
GPS VCC -> Appropriate supply
```

Check the breakout's voltage requirements before powering it.

## ESP

Provide the ESP with a suitable 3.3 V-compatible power arrangement and common ground where signals are exchanged.
