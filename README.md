# Circuits and Electronics

Code from the Circuits and Electronics SBHS CS Club Workshop including projects on LEDs, ultrasonic sensing, servos, and more.

## Hardware

All projects are built around a common pin layout:

| Component | Pin |
|-----------|-----|
| Red LED | 15 |
| Yellow LED | 14 |
| Green LED | 13 |
| Ultrasonic TRIG | 16 |
| Ultrasonic ECHO | 17 |
| Buzzer | 18 |

---

## 📁 `led_patterns`

LED-only projects exploring different blink and animation patterns. Great starting point for beginners.

| File | Description |
|------|-------------|
| `traffic_light.cpp` | Cycles through red → green → yellow with configurable timing, simulating a real traffic light |
| `heartbeat.cpp` | Pulses the red LED in a double-beat heartbeat rhythm |
| `knight_rider.cpp` | Sweeps LEDs left-to-right and back, like the scanner from Knight Rider |
| `wave_flow.cpp` | Turns LEDs on in sequence then all off, creating a flowing wave effect |
| `triple_blink.cpp` | Blinks all three LEDs simultaneously at 100ms intervals |
| `random_flicker.cpp` | Randomly flickers all three LEDs independently to simulate a flame or glitch effect |

---

## 📁 `ultrasonic_sensor`

Projects using an HC-SR04 ultrasonic distance sensor, building from bare readings up to visual feedback.

| File | Description |
|------|-------------|
| `ultrasonic_sensor.cpp` | Minimal sensor sketch — reads distance and prints it to Serial every 500ms |
| `distance_sensor.cpp` | Adds LED feedback: red < 10 cm, yellow < 25 cm, green < 60 cm |
| `distance_sensor_with_leds.cpp` | Same as above with refined pin definitions and sensor helper function |
| `distance_sensor_with_buzzer.cpp` | Adds a buzzer that beeps faster as the object gets closer |
| `distance_sensor_with_display.cpp` | Full build: LEDs + buzzer + 4-digit 7-segment display showing the distance in cm |

---

## 📁 `others`

More advanced projects that combine the sensor and LEDs for interactive or reactive applications.

| File | Description |
|------|-------------|
| `distance_bar.cpp` | Lights LEDs as a proximity bar graph — more LEDs on as object gets closer |
| `parking_assistant.cpp` | Parking sensor with graduated alerts: green (safe) → yellow (close) → red + high tone (stop) |
| `intruder_alarm.cpp` | Triggers a red LED and continuous buzzer tone when something enters the 20 cm threshold |
| `distance_reaction_game.cpp` | Reaction time game — a green LED lights up after a random delay and you must wave your hand in front of the sensor as fast as possible |

---

## Getting Started

1. Open any `.cpp` file in the [Arduino IDE](https://www.arduino.cc/en/software)
2. Select your board
3. Wire up components according to the pin table above
4. Upload and open the Serial Monitor at **115200 baud**
