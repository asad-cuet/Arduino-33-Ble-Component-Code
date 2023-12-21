#include "Arduino_BMI270_BMM150.h"

float x, y, z;
float degreesZ = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
}

void loop() {

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

  }

  float enmo = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) - 1.0;


  if(z > 0.01){
    z = 100*z;
    degreesZ = map(z, 0, 97, 0, 90);
    Serial.print("anglez: ");
    Serial.println(degreesZ);
    Serial.print(", ");
    Serial.print("enmo: ");
    Serial.print(enmo);


    }
  if(z < -0.01){
    z = 100*z;
    degreesZ = map(z, 0, -100, 0, -90);
    Serial.print("anglez: ");
    Serial.println(degreesZ);
    Serial.print(", ");
    Serial.print("enmo: ");
    Serial.print(enmo);
    }
  
  delay(1000);
}
