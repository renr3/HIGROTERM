/*
 * This function finds the next unused file name to be used for the file.
 * It also handles possible situations that might occur during this situation and properly outputs messages to the user.
 * It may output messages in the Loading Screen or in the Data Log Console in the Monitoring Table Screen
 */

void findFileName_SD () {
  byte ypos = 30;
  uint8_t named = 0; //Variable that will indicate wheter file was or was not named
  if (BASE_NAME_SIZE > 6) {//Checks if Base Name (e.g. Data in "Data00.csv") size is less than 6 bits, as required by fileName holder. If it is, run the following instructions:
    switch (currentPage) { //Checks in which screen we are
      case 1: //In case we are at Loading Screen
        myGLCD.print(F("Base name too long! Call support."), LEFT, ypos); // Prints the string on the screen
        break;
      case 2: //In case we are at Monitoring Table Screen
        dataLogConsole_MonitoringTableScreen("Long file name. Call support."); //Prints the message on the log table
        break;
    }
  } else { //If the Base Name is not too large, proceed to search for the next available file name
    while (sd.exists(fileName)) {//While sd.exists() returns true, meaning that fileName already exists in SD
      if (fileName[BASE_NAME_SIZE + 1] != '9') {//If the last digit (units digit) after Base Name is not 9, we can add one more unit to it, and see if the name still exists
        fileName[BASE_NAME_SIZE + 1]++; //The units digit increases one unit
        named = 1;//If the code exits this while loop and "named" is equal to 1, it will indicate that a file name was available
      } else if (fileName[BASE_NAME_SIZE] != '9') { //The last digit was 9, and a decimal change needs to be performed
        fileName[BASE_NAME_SIZE + 1] = '0'; //We set the units digit to 0, indicating the decimal "house" has changed, e.g. from 19 to 20, or 29 to 30
        fileName[BASE_NAME_SIZE]++;  //The decimal digit increases one unit
        named = 1; //If the code exits this while loop and "named" is equal to 1, it will indicate that a file name was available
      } else { //Both unit and decimal digits are equal to 9 and so there is no available file name.
        named = 2; //If the code exits this while loop and "named" is equal to 2, it will indicate that a file name was NOT available
        break; //Exits the while loop, bypassing the loop condition check
      }
    }
    if (named == 1) { //If the new file could be named...
      switch (currentPage) { //Checks in which screen we are
        case 1: //In case we are at Loading Screen
          myGLCD.print(F("Data file named!"), LEFT, ypos); // Prints the string on the screen
          break;
        case 2: //In case we are at Monitoring Table Screen
          dataLogConsole_MonitoringTableScreen("File named!"); //Prints the message on the Data Log Console
          break;
      }
    } else if (named == 2) {//If the new file could not be named...
      switch (currentPage) {//Checks in which screen we are
        case 1: //In case we are at Loading Screen
          myGLCD.print(F("Maximum file number reached. Unload SD card."), LEFT, ypos); // Prints the string on the screen
          break;
        case 2: //In case we are at Monitoring Table Screen
          dataLogConsole_MonitoringTableScreen("SD card full. Unload!");//Prints the message on the Data Log Console
          break;
      }
    }
  }
}
