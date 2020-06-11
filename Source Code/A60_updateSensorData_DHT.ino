/*
 * Updates the vectors t1 and h1, that holds the latest measurements of temperature and humidity respectively.
 */

void updateSensorData_DHT () {//It asks each sensor for current data, and update t1 and h1 variables
  for (byte ii = 0; ii < 8; ii++) { //Runs through the eigth channels, to see which are connected
    if (selectedChannels[ii] == 1) { //If the channel is connected, then perform the following instructions...
      t1[ii] = readTemp_DHT(dhtSensor[ii]); //Read a temperature value
      h1[ii] = readHum_DHT(dhtSensor[ii]); //Read a humidity value
    }
  }
}
