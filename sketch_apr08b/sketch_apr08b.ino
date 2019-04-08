#include <Wire.h>
#include "SparkFunBME280.h"

#define SLAVE_ADDRESS 0x76

/* Instantiate a BME280 object called BME280_obj */
//BME280 BME280_obj;
BME280 mySensor;  //Objetos C++

struct sensors   //Descripción de la estructura
{
  uint8_t temp;
  uint8_t alt;
  uint8_t hum;
  uint8_t pres;
};


void setup()
{
  /* Start serial for output */
  Serial.begin(115200);

  /* Initialize the file system */
  Serial.printf("Initializing SPIFFS\n");
  if (SPIFFS.begin() == false)   //Para guardar datos SPIFFS
  {
    Serial.printf("SPIFFS cannot be initialized\n");

    /* Stop here (WDT will reset at some point) */
    while(1) {};
  }
}

void loop()   //Necesitamos 2 funciones una para recoger datos y otra para guardar.
{
    /* Welcome message! Useful as a control point */
  Serial.printf("\nAhoy! ESP8266 here!\n---\n");

  struct nombre dato1;                        //Reserva de memoria 
  Serial.printf("Humidity:\t ");
  Serial.printf(mySensor.readFloatHumidity());

  Serial.printf(" \nPressure:\t ");
  Serial.printf(mySensor.readFloatPressure();

  Serial.printf("\nAltitude m:\t ");
  Serial.printf(mySensor.readFloatAltitudeMeters())  //Número de decimales 1
  Serial.print(" \nAltitude feet:\t ");
  Serial.printf(mySensor.readFloatAltitudeFeet());

  Serial.printf(" \nTemperature degrees C:\t ");
  Serial.printf(mySensor.readTempC();
  Serial.printf(" \nTemperature degrees F:\t ");
  Serial.printf(mySensor.readTempF());

  Serial.println();

  delay(500);
}
