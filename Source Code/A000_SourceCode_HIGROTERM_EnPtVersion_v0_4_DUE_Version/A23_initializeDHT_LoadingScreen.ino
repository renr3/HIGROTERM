/*
 * Function that initializes all sensors.
 * It is a function that runs only in the Loading Screen.
 * While it checks the sensor connection, it outputs a message indicating the current status of the process
 */

void initializeSensorsDHT_LoadingScreen() {//Initialize all sensor. Used only on the Loading Screen
  //Initialize all DHT sensors
  myGLCD.setBackColor(0, 0, 0); // Sets the background color of the area where the text will be printed to black
  myGLCD.setColor(255, 255, 255); // Sets color to white
  char configuringWarning[21];
  byte skipSensor = 0; //This variable is used to control in which line the message will be displayed.

  for (uint8_t ii = 0; ii < 8; ii++) {//Check if the current sensor is to be connected or not
    if (selectedChannels[ii] == 0) {//Checks if sensor was not indicated, by the user, to be connected
      skipSensor ++; //Updates the variable skipSensor to assess how many sensors were skipped, so we know in which line we should write the next connection message
      continue; //Goes to the next iteration of the for loop, which performing the instructions below
    }
    uint8_t tries = 0;
    byte maximumNumberOfTries = 10;
    
    //Variables to adjust the position of the status text being displayed
    byte ypos = 150;
    byte nextLine = (ii - skipSensor); //Computed in which line the connection message will be displayed
    
    myGLCD.setFont(SmallFont);
    sprintf (configuringWarning, "Sensor %d: connecting", ii + 1); //Builds a string to indicate the user which sensor the system is trying to connect to
    myGLCD.print(configuringWarning, LEFT, ypos + nextLine * 10); // Prints the built string on the appropriate line
    do {
      dhtSensor[ii].begin(); //Tries to initiate the sensor
      t1[ii] = dhtSensor[ii].readTemperature(); //Tries to read a temperature from the sensor.
      //If the sensor is properly connected, the read value will be a numeric value.
      //This is used to check if the sensor is correctly connected.
      //Perform a little animation so the user can understand the system is performing actions
      //Prints loading dots on the screen
      delay(100);
      myGLCD.print(F("."), 162, ypos + nextLine * 10);
      delay(100);
      myGLCD.print(F("."), 170, ypos + nextLine * 10);
      delay(100);
      myGLCD.print(F("."), 178, ypos + nextLine * 10);
      delay(100);
      myGLCD.print(F(" "), 162, ypos + nextLine * 10);
      delay(100);
      myGLCD.print(F(" "), 170, ypos + nextLine * 10);
      delay(100);
      myGLCD.print(F(" "), 178, ypos + nextLine * 10);
      tries ++; //Increase variable "tries", so the system will only perform a maximum number of connection tries
    } while (isnan(t1[ii]) && tries < maximumNumberOfTries); //Do the previous instructions until a numeric temperature value is obtained or the number of tries exceeds maximumNumberOfTries
    if (tries >= 10) { //If the number of  tries exceeded 10, the sensor was not connected
      myGLCD.print(F("                          "), LEFT, ypos + nextLine * 10); //Erases the connection message
      sprintf (configuringWarning, "Sensor %d: not found!", ii + 1); //Builds a string with the status message
      myGLCD.print(configuringWarning, LEFT, ypos + nextLine * 10); // Prints the string with the status message
      selectedChannels[ii] = 0; //Indicates the sensor was not connected, to allow the sketch to continue normally as if the said sensor was simply not connected by the user
    } else {
      myGLCD.print(F("                          "), LEFT, ypos + nextLine * 10); //Erases the connection message
      sprintf (configuringWarning, "Sensor %d: connected!", ii + 1); //Builds a string with the status message
      myGLCD.print(configuringWarning, LEFT, ypos + nextLine * 10); // Prints the string with the status message
    }
  }
}
