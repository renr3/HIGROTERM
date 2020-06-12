/*
 * Functions that prints a new line of logged data to the log file.
 * It involves printing the clock data, updating the sensor data vector t1 and h1, and printing these vectors in the same line,
 * in the format of comma separeted values
 */

void logData_SD() {// Log a data record
  rtc.refresh();//Get the current time and date from the RTC clock
  //Print the date and time data in the format: YY-MM-DD-HH:MM:SS
  file.print(rtc.year());
  file.print(F("-"));
  file.print(rtc.month());
  file.print(F("-"));
  file.print(rtc.day());
  file.print(F("-"));
  file.print(rtc.hour());
  file.print(F(":"));
  file.print(rtc.minute());
  file.print(F(":"));
  file.print(rtc.second());

  updateSensorData_DHT();//Read sensor data, updating t1 and h1 variables, for the connected channels

  for (byte ii = 0; ii < 8; ii++) {//Runs through all the channels to see which one is connected
    if (selectedChannels[ii] == 1) {//Checks if the channel is connected. If yes, then run the following instructions...
      file.print(F(","));//Prints a comma, to separate the previous data from the next data
      printFloat_SD(t1[ii]);//Prints the sensor temperature value
      file.print(F(","));//Prints a comma, to separate the previous data from the next data
      printFloat_SD(h1[ii]);//Prints the sensor humidity vlue
    }
  }
  file.println(); //Prints a new line
  
  //-TODO 7: Implement !file.sync() method in the logData_SD function, so to prevent the system from losing data due to power loss
  //See SDFat library documentation.
}
