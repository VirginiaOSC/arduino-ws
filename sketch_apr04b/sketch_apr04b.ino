/* Include required headers and/or libraries */
#include <Wire.h>
#include "SparkFunBME280.h"

#define SLAVE_ADDRESS 0x76

/* Instantiate a BME280 object called BME280_obj */
//BME280 BME280_obj;
BME280 mySensor;  //Objetos C++
/*
 * Single-pass function to configure the app
 */
void setup()
{
  /* Start serial for output */
  Serial.begin(115200);

  /* Join I2C bus and set it to 400 kHz */
  Wire.begin(0, 2);
  Wire.setClock(400000);

  /* Address the sensor */
  //mySensor.settings.commInterface = I2C_MODE;
 // mySensor.settings.I2CAddress = 0x76;
  mySensor.setI2CAddress(SLAVE_ADDRESS); //Esta línea sustituye a las otras dos.

  /* Check communication before continue */
  if (mySensor.beginI2C(Wire) == false)
  {
    Serial.printf("The sensor did not respond. Please check wiring.\n");

    /* Stop here (WDT will reset at some point) */
    while(1);
  }
  
  mySensor.setMode(MODE_NORMAL);    //Normal mode
  /*Standby time*/
  mySensor.setStandbyTime(0);     
  /* Filter 3, coefficients = 8*/
  mySensor.setFilter(1);
  
  /* 1 through 5, oversampling *1, *2, *4, *8, *16 respectively*/
  mySensor.setTempOverSample(1);
  mySensor.setPressureOverSample (1);
  mySensor.setHumidityOverSample(1);
  
}

void loop()
{
    /* Welcome message! Useful as a control point */
  Serial.printf("\nAhoy! ESP8266 here!\n---\n");
  
  Serial.print("Humidity:\t ");
  Serial.print(mySensor.readFloatHumidity(), 0);

  Serial.print(" \nPressure:\t ");
  Serial.print(mySensor.readFloatPressure(), 0);

  Serial.print("\nAltitude m:\t ");
  Serial.print(mySensor.readFloatAltitudeMeters(), 1);  //Número de decimales 1
  Serial.print(" \nAltitude feet:\t ");
  Serial.print(mySensor.readFloatAltitudeFeet(), 1);

  Serial.print(" \nTemperature degrees C:\t ");
  Serial.print(mySensor.readTempC(), 2);
  Serial.print(" \nTemperature degrees F:\t ");
  Serial.print(mySensor.readTempF(), 2);

  Serial.println();

  delay(500);
}
