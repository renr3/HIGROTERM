/*
 * Function that opens the log file to be written, and print the file header. 
 * Return 0 if file could be successfully opened, or 1 if file could not be opened.
 */

byte openFile_SD() {
  if (!file.open(fileName, O_WRONLY | O_CREAT | O_EXCL)) { //If the file could not be opened, it might be due to a corrupt SD card or that no file name is available anymore
    switch (currentPage) {//Check in which screen we are
      case 1:
        myGLCD.print(F("Data file initialization not possible! Restart the system"), LEFT, 150); // Prints the string on the screen
        break;
      case 2: //Monitoring Table Screen
        dataLogConsole_MonitoringTableScreen("Restart/unload SD card"); //Prints the message on the Data Log Console
        break;
    }
    return 1;//Return one because file could not be successfully opened
  } else {
    switch (currentPage) {//Check in which screen we are
      case 1:
        myGLCD.print(F("Data file initialized!"), LEFT, 150); // Prints the string on the screen
        break;
      case 2: //Monitoring Table Screen
        dataLogConsole_MonitoringTableScreen("SD init. successful"); //Prints the message on the Data Log Console
        break;
    }
    //Print file header, based on what sensors will be connected during sampling
    file.print(F("YEAR-MONTH-DAY-HOUR:MINUTE:SECOND"));
    char sensorLabel[3];
    for (byte ii = 0; ii < 8; ii++) {//Runs through all the eight channels
      if (selectedChannels[ii] == 1) {//If the channel is connected, then perform the following instructions:
        file.print(F(","));//Print a coma to separate from previous data
        sprintf (sensorLabel, "T%d", ii + 1); //Builds a string with a "T", for temperature, and a number to indicate which channel this value will refer to
        file.print(sensorLabel); //Prints the sensor label for temperature+channel, e.g. "T1" for the temperature of channel 1; "T2" for the temperature of channel 2, etc.
        file.print(F(","));//Print a coma to separate from previous data
        sprintf (sensorLabel, "H%d", ii + 1);//Builds a string with a "H", for temperature, and a number to indicate which channel this value will refer to
        file.print(sensorLabel);//Prints the sensor label for temperature+channel, e.g. "H1" for the temperature of channel 1; "H2" for the temperature of channel 2, etc.
      }
    }
    file.println();//Sets the cursor to the next line
    return 0;//Return zero because file could be successfully opened
  }
}
