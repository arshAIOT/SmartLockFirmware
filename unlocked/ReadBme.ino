// to work with BME 280 we need to use Adafruit BME280 library
// to work with BME 280 library we need adafruit sensor library (adafruit unified sensor)




/*
bme.readTemperature() – reads temperature in Celsius;
bme.readHumidity() – reads absolute humidity;
bme.readPressure() – reads pressure in hPa (hectoPascal = millibar);
bme.readAltitude(SEALEVELPRESSURE_HPA) – estimates altitude in meters based on the pressure at the sea level.
 */


void BmeSetup() {

   //serial communication

  bool status;
  
  status = bme.begin(0x76);// address 0*76 passed to bme.begin method to start communication with bme sensor //  This function initializes I2C interface with given I2C Address and checks if the chip ID is correct. It then resets the chip using soft-reset & waits for the sensor for calibration after wake-up.
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  
  Serial.println("-- Default Test --");


  Serial.println();
}




                               
