/*
 * Read the humidity of a DHT sensor, and returns the read.
 */
 
float readHum_DHT(DHT &dht) {//Read humidity value from a sensor
  //TODO 2: Implement a check/message to deal with the issue when a sensor can not be read after 10 tries
  float humidity;
  uint8_t tries = 0;
  humidity = dht.readHumidity();//Read humidity with the appropriate DHT library method
  while (isnan(humidity) || tries <= 10) {//Will try to read the humidity until a numerical value is obtained or the number of tries is equal than 10
    tries ++; //Increase variable "tries" by one unit
    humidity = dht.readHumidity();
  }
  return humidity;
}
