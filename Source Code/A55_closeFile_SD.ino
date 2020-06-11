/*
 * Function thtat closes the log data file.
 */


void closeFile_SD() {
  //TODO 1: implement conditions to deal with unsuccessful .close method. Check SdFat.h to know more about .close method and its returns
  file.close(); //Close file
  switch (currentPage) { //Check in which screen we are
    case 1: //In case we are at Loading Screen
      myGLCD.print(F("Data file closed!"), LEFT, 150); // Prints the string on the screen
      break;
    case 2: //In case we are at Monitoring Table Screen
      dataLogConsole_MonitoringTableScreen("File closed."); //Prints the message on the Data Log Console
      break;
  }
}
