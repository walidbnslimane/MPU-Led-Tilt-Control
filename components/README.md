## Components 

| Component           | Description                                             | Pin Connection                | Image                                       |
|---------------------|---------------------------------------------------------|-------------------------------|---------------------------------------------|
| Arduino Uno         | Microcontroller board for controlling the LED and MPU6050 | Digital Pin 13 for LED, GND   | <img src="https://github.com/user-attachments/assets/a1a7b740-eb80-467c-aaae-e88018584c9d" width="330"> |
| MPU6050 Sensor      | Gyroscope and accelerometer module for tilt detection   | I2C (SDA to A4, SCL to A5)     | <img src="https://github.com/user-attachments/assets/62f5f655-a1e6-48eb-b8ba-319de83b77c3" alt="MPU6050" width="330"> |
| LED                 | Indicator light for tilt response                        | Anode to Digital Pin 13, Cathode to resistor | <img src="https://github.com/user-attachments/assets/265a4442-a139-4051-82f5-eb93e849d90a" alt="LED" width="330">  |
| Resistor            | 220Ω or 330Ω to limit LED current                       | Between LED cathode and GND    | <img src="https://github.com/user-attachments/assets/ce9a677e-3ba4-4b60-9420-2f1fa8915891" alt="Resistor" width="330">  |
| Breadboard          | Organizing components and connections                   | -                             | <img src="https://github.com/user-attachments/assets/0b694d76-3eea-4123-a352-6cec240d29b1" alt="Breadboard" width="330">  |
| Jumper Wires        | Male-to-male connectors for wiring the components       | Digital Pins, GND              | <img src="https://github.com/user-attachments/assets/b21f7fa1-e0f0-46e0-b93c-fa01bac3a849" alt="Jumper Wires" width="330">  |

## Circuit Diagram

Include a diagram that shows connections between Arduino Uno, MPU6050, LED, and resistor.

## Connections Breakdown

| **Pin**      | **Component**    | **Connection**         |
|--------------|------------------|------------------------|
| Digital Pin 13 | LED (Anode)    | Long leg of LED       |
| GND          | Resistor         | Connected to resistor |
| Resistor end | LED (Cathode)    | Short leg of LED      |
| A4 (SDA)     | MPU6050 (SDA)    | Data line for MPU6050 |
| A5 (SCL)     | MPU6050 (SCL)    | Clock line for MPU6050 |

