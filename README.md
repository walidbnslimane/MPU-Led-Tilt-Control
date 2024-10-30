# Tilt-Based LED Control Using Arduino Uno and MPU6050

This project demonstrates how to control an LED using the MPU6050 accelerometer and gyroscope sensor connected to an Arduino Uno. When the Arduino detects a specific tilt angle from the MPU6050, the LED responds by turning on or off. This project can be useful for tilt-based control in various applications.

https://github.com/user-attachments/assets/3d977d3e-f013-457e-82d3-f72368918978


## Features
- **Tilt Detection**: Uses MPU6050 to detect tilt in the X, Y, or Z axis.
- **LED Control**: Lights up the LED based on tilt angle.
- **Portable**: Can be adapted for any project that requires tilt-based control.

## Components 

| Component           | Description                                             | Pin Connection                | Image                                       |
|---------------------|---------------------------------------------------------|-------------------------------|---------------------------------------------|
| Arduino Uno         | Microcontroller board for controlling the LED and MPU6050 | Digital Pin 13 for LED, GND   | <img src="https://github.com/user-attachments/assets/a1a7b740-eb80-467c-aaae-e88018584c9d" width="330"> |
| MPU6050 Sensor      | Gyroscope and accelerometer module for tilt detection   | I2C (SDA to A4, SCL to A5)     | <img src="https://github.com/user-attachments/assets/62f5f655-a1e6-48eb-b8ba-319de83b77c3" alt="MPU6050" width="330"> |
| LED                 | Indicator light for tilt response                        | Anode to Digital Pin 13, Cathode to resistor | <img src="https://github.com/user-attachments/assets/265a4442-a139-4051-82f5-eb93e849d90a" alt="LED" width="330">  |
| Resistor            | 220Ω or 330Ω to limit LED current                       | Between LED cathode and GND    | <img src="https://github.com/user-attachments/assets/ce9a677e-3ba4-4b60-9420-2f1fa8915891" alt="Resistor" width="330">  |
| Breadboard          | Organizing components and connections                   | -                             | <img src="https://github.com/user-attachments/assets/0b694d76-3eea-4123-a352-6cec240d29b1" alt="Breadboard" width="330">  |
| Jumper Wires        | Male-to-male connectors for wiring the components       | Digital Pins, GND              | <img src="https://github.com/user-attachments/assets/b21f7fa1-e0f0-46e0-b93c-fa01bac3a849" alt="Jumper Wires" width="330">  |


## Connections Breakdown

| **Pin**      | **Component**    | **Connection**         |
|--------------|------------------|------------------------|
| Digital Pin 13 | LED (Anode)    | Long leg of LED       |
| GND          | Resistor         | Connected to resistor |
| Resistor end | LED (Cathode)    | Short leg of LED      |
| A4 (SDA)     | MPU6050 (SDA)    | Data line for MPU6050 |
| A5 (SCL)     | MPU6050 (SCL)    | Clock line for MPU6050 |

## Circuit Diagram
<img src="https://github.com/user-attachments/assets/1299b173-764b-415f-aef3-6cea27840ccd">

Include a diagram that shows connections between the Arduino Uno, MPU6050, LED, and resistor.
## How It Works
1. The MPU6050 measures tilt along the X, Y, and Z axes.
2. The Arduino reads this data via I2C communication.
3. Based on tilt angle thresholds, the Arduino controls the LED:
   - **LED On**: LED lights up if the MPU6050 detects a tilt beyond a specified threshold.
   - **LED Off**: LED turns off if the angle is within the safe range.

## Code Overview

### MPU6050 Setup
This section initializes the MPU6050 and establishes I2C communication with the Arduino Uno.

```cpp
#include <Wire.h>
const int MPU_addr = 0x68;
int16_t AcX, AcY, AcZ;
int LED = 13;

void setup() {
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

```

### Tilt-Based LED Control
This function checks the tilt angles and turns the LED on or off based on the tilt.

```cpp
void checkTilt(int x, int y, int z) {
  if (abs(x) > 15000 || abs(y) > 15000) {
    digitalWrite(LED, HIGH);  // Turn LED on if tilt is detected
  } else {
    digitalWrite(LED, LOW);   // Keep LED off if no tilt
  }
}

```

