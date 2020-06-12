/* In this file all the functions used for drawing buttons are listed.
 * To the best extent, they are divided in the screens they appear, and then listed in alphabetical order, with pairs of active and innactive (greyed out) versions put sequententially.
 * The geometric localization of each button is defined by its respective variables, which are constant integers declared on the main file
 */

// ============================================== LOADING SCREEN BUTTONS ==============================================

void  drawOKButton_LoadingScreen() {//Draws OK button on the Loading Screen
  myGLCD.setColor(41, 201, 26);
  myGLCD.fillRect(OKBut_LoadingScreen_Xmin, OKBut_LoadingScreen_Ymin, OKBut_LoadingScreen_Xmax, OKBut_LoadingScreen_Ymax); //A 80x80 square at the bottom-right corner
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(OKBut_LoadingScreen_Xmin, OKBut_LoadingScreen_Ymin, OKBut_LoadingScreen_Xmax, OKBut_LoadingScreen_Ymax);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(GroteskBold32x64);
  myGLCD.setBackColor(41, 201, 26); // Sets background colour of the text to match the buttons colour defined above
  myGLCD.print(F("OK"), OKBut_LoadingScreen_Xmin + 8 , OKBut_LoadingScreen_Ymin + 10 );
}

void  drawOKButton_Inactive_LoadingScreen() {//Draws Inactive version of OK button on the Loading Screen
  myGLCD.setColor(160, 160, 160);
  myGLCD.fillRect(OKBut_LoadingScreen_Xmin, OKBut_LoadingScreen_Ymin, OKBut_LoadingScreen_Xmax, OKBut_LoadingScreen_Ymax); //A 80x80 square at the bottom-right corner
  myGLCD.setColor(200, 200, 200);
  myGLCD.drawRect(OKBut_LoadingScreen_Xmin, OKBut_LoadingScreen_Ymin, OKBut_LoadingScreen_Xmax, OKBut_LoadingScreen_Ymax); 
  myGLCD.setColor(90, 90, 90);
  myGLCD.setFont(GroteskBold32x64);
  myGLCD.setBackColor(160, 160, 160); // Sets background colour of the text to match the buttons colour defined above
  myGLCD.print(F("OK"), OKBut_LoadingScreen_Xmin + 8 , OKBut_LoadingScreen_Ymin + 10 );
}

void  sensorSelectionButton_NotSelected_LoadingScreen(uint8_t ii) {
  char channelLabel[3];
  byte ypos = 95;
  byte boxHeight = 45;
  myGLCD.setColor(160, 160, 160);
  myGLCD.fillRect(40 * ii, ypos, 39 + 40 * ii, ypos + boxHeight); //-1 is to address the fact that pixel 320 does not seem to exist
  myGLCD.setColor(200, 200, 200);
  myGLCD.drawRect(40 * ii, ypos, 39 + 40 * ii, ypos + boxHeight); //-1 is to address the fact that pixel 320 does not seem to exist
  myGLCD.setColor(90, 90, 90);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(160, 160, 160);
  sprintf (channelLabel, "S%d", ii + 1);
  myGLCD.print(channelLabel, 40 * ii + 4, ypos + (boxHeight - 16) / 2);
}

void  sensorSelectionButton_Selected_LoadingScreen(uint8_t ii) {
  char channelLabel[3];
  byte ypos = 95;
  byte boxHeight = 45;
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(40 * ii, ypos, 40 + 40 * ii - 1, ypos + boxHeight); //-1 is to address the fact that pixel 320 does not seem to exist
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(40 * ii, ypos, 40 + 40 * ii - 1, ypos + boxHeight); //-1 is to address the fact that pixel 320 does not seem to exist
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(255, 0, 0); // Sets color of the given line
  sprintf (channelLabel, "S%d", ii + 1);
  myGLCD.print(channelLabel, 40 * ii + 4, ypos + (boxHeight - 16) / 2);
}

// ============================================== MONITORING TABLE SCREEN BUTTONS ==============================================


void drawConfigButton_MonitoringTableScreen () {//Draws the Configuration Button on Monitoring Screen
  myGLCD.setColor(242, 126, 10);
  myGLCD.fillRect(configBut_MonitTabScren_Xmin, configBut_MonitTabScren_Ymin, configBut_MonitTabScren_Xmax, configBut_MonitTabScren_Ymax);
  myGLCD.setColor(242, 126, 10);
  myGLCD.setFont(Various_Symbols_32x32);
  myGLCD.setBackColor(255, 255, 255); // Sets color of the given line
  myGLCD.print(F("s"), configBut_MonitTabScren_Xmin + 3, configBut_MonitTabScren_Ymin + 3);
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.print(F("Config"), 319 - 48, 0);
}

void drawConfigButton_Inactive_MonitoringTableScreen () {//Draws the Configuration Button on Monitoring Screen on its Inactive mode
  myGLCD.setColor(160, 160, 160);
  myGLCD.fillRect(configBut_MonitTabScren_Xmin, configBut_MonitTabScren_Ymin, configBut_MonitTabScren_Xmax, configBut_MonitTabScren_Ymax);
  myGLCD.setColor(160, 160, 160);
  myGLCD.setFont(Various_Symbols_32x32);
  myGLCD.setBackColor(255, 255, 255); // Sets color of the given line
  myGLCD.print(F("s"), configBut_MonitTabScren_Xmin + 3, configBut_MonitTabScren_Ymin + 3);
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.print(F("Config"), 319 - 48, 0);
}

void drawRecordButton_MonitoringTableScreen () {//Draws the Record Button on Monitoring Screen
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(recordStopBut_MonitTabScren_Xmin, recordStopBut_MonitTabScren_Ymin, recordStopBut_MonitTabScren_Xmax, recordStopBut_MonitTabScren_Ymax);
  myGLCD.setColor(255, 0, 0);
  myGLCD.setFont(Various_Symbols_32x32);
  myGLCD.setBackColor(255, 255, 255); // Sets color of the given line
  myGLCD.print(F("<"), recordStopBut_MonitTabScren_Xmin + 3, recordStopBut_MonitTabScren_Ymin + 3);
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.print(F("Record"), 4, 0);
}

void drawStopButton_MonitoringTableScreen () {//Draws the Record Button on Monitoring Screen
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRect(recordStopBut_MonitTabScren_Xmin, recordStopBut_MonitTabScren_Ymin, recordStopBut_MonitTabScren_Xmax, recordStopBut_MonitTabScren_Ymax);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(Various_Symbols_32x32);
  myGLCD.setBackColor(0, 0, 255); // Sets color of the given line
  myGLCD.print(F("i"), recordStopBut_MonitTabScren_Xmin + 3, recordStopBut_MonitTabScren_Ymin + 3);
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.print(F("      "), 4, 0);
  myGLCD.print(F("Pause"), 7, 0);
}

// ============================================== CONFIGURATION SCREEN BUTTONS ==============================================


void  drawHomeScreenButton_ConfigScreen() { //Draws Home Screen button on the Configuration Screen
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SmallFont); // Sets font to big
  myGLCD.print(" Return to ", 119, 88);
  myGLCD.print("home screen", 119, 98);
  myGLCD.setColor(3, 94, 252);
  myGLCD.fillRect(HomeScreenBut_ConfigScreen_Xmin, HomeScreenBut_ConfigScreen_Ymin, HomeScreenBut_ConfigScreen_Xmax, HomeScreenBut_ConfigScreen_Ymax); //A 80x80 square at the bottom-right corner
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(HomeScreenBut_ConfigScreen_Xmin, HomeScreenBut_ConfigScreen_Ymin, HomeScreenBut_ConfigScreen_Xmax, HomeScreenBut_ConfigScreen_Ymax);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawBitmap(HomeScreenBut_ConfigScreen_Xmin+8, HomeScreenBut_ConfigScreen_Ymin+9, 32, 32, img_home2_png);
  myGLCD.setBackColor(0, 0, 0);
}

void  drawHomeScreenButton_Inactive_ConfigScreen() { //Draws Inactive version of Home Screen button on the Configuration Screen
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SmallFont); // Sets font to big
  myGLCD.print(" Return to ", 119, 88);
  myGLCD.print("home screen", 119, 98);
  myGLCD.setColor(127, 172, 252);
  myGLCD.fillRect(HomeScreenBut_ConfigScreen_Xmin, HomeScreenBut_ConfigScreen_Ymin, HomeScreenBut_ConfigScreen_Xmax, HomeScreenBut_ConfigScreen_Ymax); //A 80x80 square at the bottom-right corner
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(HomeScreenBut_ConfigScreen_Xmin, HomeScreenBut_ConfigScreen_Ymin, HomeScreenBut_ConfigScreen_Xmax, HomeScreenBut_ConfigScreen_Ymax);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawBitmap(HomeScreenBut_ConfigScreen_Xmin+8, HomeScreenBut_ConfigScreen_Ymin+9, 32, 32, img_home2_Inactive_png);
  myGLCD.setBackColor(0, 0, 0);
}

void  drawReloadConnectionsButton_ConfigScreen() {//Draws the Reload Connections button on the Configuration Screen
  //This is a button to re-run the sensors connection, in case a new sensor has been connected
      myGLCD.setColor(255, 255, 255);
      myGLCD.setFont(SmallFont);
      myGLCD.print("  Reload", 18, 88);
      myGLCD.print("connections", 15, 98);
      myGLCD.setColor(41, 201, 26);
      myGLCD.fillRect(ReloadBut_ConfigScreen_Xmin, ReloadBut_ConfigScreen_Ymin, ReloadBut_ConfigScreen_Xmax, ReloadBut_ConfigScreen_Ymax); //A 80x80 square at the bottom-right corner
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawRect(ReloadBut_ConfigScreen_Xmin, ReloadBut_ConfigScreen_Ymin, ReloadBut_ConfigScreen_Xmax, ReloadBut_ConfigScreen_Ymax);
      myGLCD.setColor(255, 255, 255);
      myGLCD.setFont(Various_Symbols_32x32);
      myGLCD.setBackColor(41, 201, 26); // Sets color of the given line
      myGLCD.print(F("q"), ReloadBut_ConfigScreen_Xmin+9, ReloadBut_ConfigScreen_Ymin+8 );
      myGLCD.setBackColor(0, 0, 0);
}

void  drawReloadConnectionsButton_Inactive_ConfigScreen() {//Draws the Inactive version of the Reload Connections button on the Configuration Screen
        myGLCD.setColor(255, 255, 255);
      myGLCD.setFont(SmallFont);
      myGLCD.print("  Reload", 18, 88);
      myGLCD.print("connections", 15, 98);
      myGLCD.setColor(156, 194, 153);
      myGLCD.fillRect(ReloadBut_ConfigScreen_Xmin, ReloadBut_ConfigScreen_Ymin, ReloadBut_ConfigScreen_Xmax, ReloadBut_ConfigScreen_Ymax); //A 80x80 square at the bottom-right corner
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawRect(ReloadBut_ConfigScreen_Xmin, ReloadBut_ConfigScreen_Ymin, ReloadBut_ConfigScreen_Xmax, ReloadBut_ConfigScreen_Ymax);
      myGLCD.setColor(255, 255, 255);
      myGLCD.setFont(Various_Symbols_32x32);
      myGLCD.setBackColor(156, 194, 153); // Sets color of the given line
      myGLCD.print(F("q"), ReloadBut_ConfigScreen_Xmin+9, ReloadBut_ConfigScreen_Ymin+8 );
      myGLCD.setBackColor(0, 0, 0);
}

void  drawSetClockDateButton_ConfigScreen() {//Draws the Set Clock/Date button on the Configuration Screen
  //This is a button to re-run the sensors connection, in case a new sensor has been connected
      myGLCD.setColor(255, 255,255);
      myGLCD.setFont(SmallFont); // Sets font to big
      myGLCD.print("Set clock", 95-25, 178);
      myGLCD.setColor(255, 0, 0);
      myGLCD.fillRect(SetClockDateBut_ConfigScreen_Xmin, SetClockDateBut_ConfigScreen_Ymin, SetClockDateBut_ConfigScreen_Xmax, SetClockDateBut_ConfigScreen_Ymax);
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawRect(SetClockDateBut_ConfigScreen_Xmin, SetClockDateBut_ConfigScreen_Ymin, SetClockDateBut_ConfigScreen_Xmax, SetClockDateBut_ConfigScreen_Ymax);
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawBitmap(SetClockDateBut_ConfigScreen_Xmin+3, SetClockDateBut_ConfigScreen_Ymin+3, 24, 24, img_clock_png);
      myGLCD.setBackColor(0, 0, 0);
}

void  drawSetClockDateButton_Inactive_ConfigScreen() {//Draws the Inactive version Set Clock/Date button on the Configuration Screen
  //This is a button to re-run the sensors connection, in case a new sensor has been connected
      myGLCD.setColor(255, 255,255);
      myGLCD.setFont(SmallFont); // Sets font to big
      myGLCD.print("Set clock", 95-25, 178);
      myGLCD.setColor(255, 141, 141);
      myGLCD.fillRect(SetClockDateBut_ConfigScreen_Xmin, SetClockDateBut_ConfigScreen_Ymin, SetClockDateBut_ConfigScreen_Xmax, SetClockDateBut_ConfigScreen_Ymax);
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawRect(SetClockDateBut_ConfigScreen_Xmin, SetClockDateBut_ConfigScreen_Ymin, SetClockDateBut_ConfigScreen_Xmax, SetClockDateBut_ConfigScreen_Ymax);
      myGLCD.setColor(255, 255, 255);
      myGLCD.drawBitmap(SetClockDateBut_ConfigScreen_Xmin+3, SetClockDateBut_ConfigScreen_Ymin+3, 24, 24, img_clock_Inactive_png);
      myGLCD.setBackColor(0, 0, 0);
}

void  drawSetLanguageENUKButton_ConfigScreen() {//Draws the Set Clock/Date button on the Configuration Screen
      myGLCD.setColor(255, 255,255);
      myGLCD.setFont(SmallFont); // Sets font to big
      myGLCD.print("Language", 178, 178);
      myGLCD.print("EN/UK", 239 ,204);
      myGLCD.setColor(255,255,255);
      myGLCD.drawRect(SetLanguageBut_ConfigScreen_Xmin, SetLanguageBut_ConfigScreen_Ymin, SetLanguageBut_ConfigScreen_Xmax, SetLanguageBut_ConfigScreen_Ymax);
      myGLCD.drawBitmap(SetLanguageBut_ConfigScreen_Xmin+2, SetLanguageBut_ConfigScreen_Ymin+2, 48, 32, img_ukFlag_png);
      myGLCD.setBackColor(0, 0, 0);
}

void  drawSetLanguagePTBRButton_ConfigScreen() {//Draws the Set Clock/Date button on the Configuration Screen
      myGLCD.setColor(255, 255,255);
      myGLCD.setFont(SmallFont); // Sets font to big
      myGLCD.print(" Idioma ", 178, 178);
      myGLCD.print("PT/BR", 239, 204);
      myGLCD.setColor(255,255,255);
      myGLCD.drawRect(SetLanguageBut_ConfigScreen_Xmin, SetLanguageBut_ConfigScreen_Ymin, SetLanguageBut_ConfigScreen_Xmax, SetLanguageBut_ConfigScreen_Ymax);
      myGLCD.drawBitmap(SetLanguageBut_ConfigScreen_Xmin+2, SetLanguageBut_ConfigScreen_Ymin+2, 48, 32, img_brazilFlag_png);
      myGLCD.setBackColor(0, 0, 0);
}

void  drawTurnOffButton_ConfigScreen() {//Draws Turn Off button on the Configuration Screen
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SmallFont); 
  myGLCD.print(" Turn off", 223, 88);
  myGLCD.print("the system", 223, 98);
  myGLCD.setColor(128, 128, 128);
  myGLCD.fillRect(TurnOffBut_ConfigScreen_Xmin, TurnOffBut_ConfigScreen_Ymin, TurnOffBut_ConfigScreen_Xmax, TurnOffBut_ConfigScreen_Ymax);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(TurnOffBut_ConfigScreen_Xmin, TurnOffBut_ConfigScreen_Ymin, TurnOffBut_ConfigScreen_Xmax, TurnOffBut_ConfigScreen_Ymax);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawBitmap(TurnOffBut_ConfigScreen_Xmin+8,TurnOffBut_ConfigScreen_Ymin+9, 32, 32, img_turnOff_png);
  myGLCD.setBackColor(0, 0, 0);
}

void  drawTurnOffButton_Inactive_ConfigScreen() {//Draws Inactive version of Turn Off button on the Configuration Screen
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SmallFont);
  myGLCD.print(" Turn off", 223, 88);
  myGLCD.print("the system", 223, 98);
  myGLCD.setColor(224, 224, 224);
  myGLCD.fillRect(TurnOffBut_ConfigScreen_Xmin, TurnOffBut_ConfigScreen_Ymin, TurnOffBut_ConfigScreen_Xmax, TurnOffBut_ConfigScreen_Ymax);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(TurnOffBut_ConfigScreen_Xmin, TurnOffBut_ConfigScreen_Ymin, TurnOffBut_ConfigScreen_Xmax, TurnOffBut_ConfigScreen_Ymax);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawBitmap(TurnOffBut_ConfigScreen_Xmin+8,TurnOffBut_ConfigScreen_Ymin+9, 32, 32, img_turnOff_Inactive_png);
  myGLCD.setBackColor(0, 0, 0);
}


// ============================================== SET CLOCK SCREEN BUTTONS ==============================================

void drawReturnButton_SetClockScreen(){
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(3, 94, 252); 
  myGLCD.fillRect(15, 202-20, 15+36, 232-20);
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRect(15, 202-20, 15+36, 232-20);
  myGLCD.drawBitmap(21, 205-20, 24, 24, img_return_png);
  myGLCD.print("Return to",15+36+5, 200-20);
  myGLCD.print("previous",15+36+5, 212-20);
  myGLCD.print("screen",15+36+5, 224-20);
}

void drawReturnButton_Inactive_SetClockScreen(){
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(134, 178, 254); 
  myGLCD.fillRect(15, 202-20, 15+36, 232-20);
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRect(15, 202-20, 15+36, 232-20);
  myGLCD.drawBitmap(21, 205-20, 24, 24, img_return_Inactive_png);
  myGLCD.print("Return to",15+36+5, 200-20);
  myGLCD.print("previous",15+36+5, 212-20);
  myGLCD.print("screen",15+36+5, 224-20);
}

void drawSaveAndReturnButton_SetClockScreen(){
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(41, 201, 26); 
  myGLCD.fillRect(319-14-36, 202-20, 319-15, 232-20);
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRect(319-14-36, 202-20, 319-15, 232-20);
  myGLCD.drawBitmap(319-21-24, 205-20, 24, 24, img_saveandreturn_png);
  myGLCD.print("Save and re_",319-(15+36+5)-93, 200-20);
  myGLCD.print("turn to pre_",319-(15+36+5)-93, 212-20);
  myGLCD.print("vious screen",319-(15+36+5)-93, 224-20);
}

void drawSaveAndReturnButton_Inactive_SetClockScreen(){
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(154, 240, 145); 
  myGLCD.fillRect(319-14-36, 202-20, 319-15, 232-20);
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRect(319-14-36, 202-20, 319-15, 232-20);
  myGLCD.drawBitmap(319-21-24, 205-20, 24, 24, img_saveandreturn_Inactive_png);
  myGLCD.print("Save and re_",319-(15+36+5)-93, 200-20);
  myGLCD.print("turn to pre_",319-(15+36+5)-93, 212-20);
  myGLCD.print("vious screen",319-(15+36+5)-93, 224-20);
}
