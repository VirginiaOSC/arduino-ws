#include <Wire.h>

void setup() {
  // join i2c bus (address optional for master)
  Wire.begin(0, 2);          //da acceso al bus con wire(carretera/librería), función que define los pines sda y scl

  // start serial for output
  Serial.begin(115200);       
}

void loop() {
  // request 6 bytes from slave device #111011x0
  Wire.requestFrom(0x76,1);  // probamos con 1 byte
  
  Wire.beginTransmission(0x76);
  Wire.write(0xD0);   //Puntero que apunta al registro
  Wire.endTransmission();
  
  // slave may send less than requested
  while (Wire.available())
  {
    // receive a byte as character
    
    char c = Wire.read();

    // print the character
    Serial.printf("Received: %02X\n", c);
  }

  delay(500);
}
