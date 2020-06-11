void drawMonitoringTableScreen() {//Draws the Monitoring Table Screen, a screen for monitoring sampling in a tabular form
  currentPage = 2; // Indicates that we are at Monitoring Table Screen
  myGLCD.clrScr(); //Clear screen
  myGLCD.setBackColor(0, 0, 0); // Sets the background color of the area where the text will be printed to black
  drawRecordButton_MonitoringTableScreen (); //Draw Record button
  drawConfigButton_MonitoringTableScreen (); //Draw Configuration button
  drawSensorDataTable_MonitoringTableScreen (); //Draw the Sensor Data Table
  //Draws the Data Log Console layout
  myGLCD.drawRect(52, 4, 319 - 52, 51);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(255, 255, 255);
  myGLCD.print(F("Data log"), CENTER, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor(0, 0, 0);
  //Iniatilize Data Log Console variables
  dataLogConsole_MonitoringTableScreen_State = 0;
  dataLogConsole_MonitoringTableScreen("");
}

