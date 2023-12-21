#include <Arduino_BMI270_BMM150.h>

float degreesZ = 0;
float enmo=0;

void readZFromAccelerometer() 
{
    float x, y, z;
    if (IMU.accelerationAvailable()) 
    {
      IMU.readAcceleration(x, y, z);
    }

    enmo = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)) - 1.0;


    if(z > 0.01)
    {
      z = 100*z;
      degreesZ = map(z, 0, 97, 0, 90);
      Serial.print("anglez: ");
      Serial.print(degreesZ);
      Serial.print(", ");
      Serial.print("enmo: ");
      Serial.println(enmo);
    }
    
    if(z < -0.01)
    {
      z = 100*z;
      degreesZ = map(z, 0, -100, 0, -90);
      Serial.print("anglez: ");
      Serial.print(degreesZ);
      Serial.print(", ");
      Serial.print("enmo: ");
      Serial.println(enmo);
    }
      
}

void setup() 
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  

  
}

void loop() {
  readZFromAccelerometer();
  delay(100); // Adjust the delay to set the sampling rate
}
