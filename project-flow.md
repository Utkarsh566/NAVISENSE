# Project Flow

```text
START
  |
Initialize sensors/GPS/buzzer
  |
Read obstacle distance
  |
Read ground distance
  |
Check thresholds
  |
Hazard detected?
  |             |
 Yes            No
  |             |
Buzzer       Continue
  |             |
  +-------> Read GPS
              |
        Send IoT data
              |
         Repeat loop
```

Local hazard warnings should not depend on internet connectivity.
