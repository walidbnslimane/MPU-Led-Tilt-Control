#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

const int ledPins[] = {13, 12, 11, 10, 9, 7}; 
int ledCount = sizeof(ledPins) / sizeof(ledPins[0]); 

const float thresholds[] = {-25, -15, -5, 5, 15, 25};

void setup() {
  Wire.begin(); 
  Serial.begin(9600); 
  
  mpu.initialize(); 
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1); 
  }
  
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int16_t ax, ay, az; 
  
  mpu.getAcceleration(&ax, &ay, &az);
  
  float angleX = atan2(ay, az) * 180 / PI;
  
  updateLEDs(angleX);
  
  delay(100); 
}

void updateLEDs(float angleX) {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  int ledIndex = getLEDIndex(angleX);

  if (ledIndex >= 0 && ledIndex < ledCount) {
    digitalWrite(ledPins[ledIndex], HIGH);
  }
}

int getLEDIndex(float angleX) {
  // Find the matching LED
  for (int i = 0; i < ledCount - 1; i++) {
    if (angleX < thresholds[i]) {
      return i; // Return matching LED index
    }
  }
  return ledCount - 1;
}
