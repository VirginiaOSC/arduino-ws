/*
  ESP8266 CheckFlashConfig by Markus Sattler

  This sketch tests if the EEPROM settings of the IDE match to the Hardware

*/

uint32_t var1; //Tipo de variable de 32 bits con _t siempre así
uint32_t var2;
uint32_t var3;

void setup(void) {
  Serial.begin(115200);
}

void loop() {
  var1= 0;
  var2 = cos (var1);
  var3 = var1 + var2 +1;
  
  Serial.printf("%u %u %u\n", var1, var2, var3);
  delay(1000);
}
