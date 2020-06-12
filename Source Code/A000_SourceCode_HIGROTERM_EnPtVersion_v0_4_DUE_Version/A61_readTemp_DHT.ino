/*
 * Read the temperature of a DHT sensor, and returns the read.
 */


float readTemp_DHT(DHT &dht) {//Read temperature value from a sensor
  //TODO 2: Implement a check/message to deal with the issue when a sensor can not be read after 10 tries
  float temperature;
  uint8_t tries = 0;
  byte maximumNumberOfTries = 10;
  
  temperature = dht.readTemperature();//Read temperature with the appropriate DHT library method
  while (isnan(temperature) || tries <= maximumNumberOfTries) {//Will try to read the temperature until a numerical value is obtained or the number of tries is equal than maximumNumberOfTries
    tries ++; //Increase variable "tries" by one unit
    temperature = dht.readTemperature();
  }
  return temperature;
}
