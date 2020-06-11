/*
 * These two functions informs when invalid entries for dates or times are inserted by the user in the Set Clock screen.
 * Examples of invalid entries are: 
 *  - Time: 29:00:00, which contains an hour equal to 29
 *  - Date: 01/17/00, which contains a month equal to 17
 */


void drawInvalidDate_SetClockScreen(){//Draws warning message saying the date inserted by the user is invalid. After completion, cleans the screen for redraw
  myGLCD.setColor(0, 0, 0); 
  myGLCD.fillRect(84,76,233,154);
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRect(84,76,233,154);
  myGLCD.setFont(BigFont);
  myGLCD.print("Invalid",CENTER, 76+11);
  myGLCD.print("date!",CENTER, 76+11+16+6);
  myGLCD.setFont(SmallFont);
  byte proceed = 0;
  while (proceed == 0) {
    if (myTouch.dataAvailable()) {
      myTouch.read();
      proceed=1;
    }
    myGLCD.print("Touch to continue",CENTER, 131);
    delay(250);
    myGLCD.print("                 ",CENTER, 131);
    delay(250);
  }
  resetTouch();
  myGLCD.setColor(0, 0, 0); 
  myGLCD.fillRect(84,76,233,154);
  drawSaveAndReturnButton_SetClockScreen();
}

void drawInvalidTime_SetClockScreen(){//Draws warning message saying the time inserted by the user is invalid. After completion, cleans the screen for redraw
  myGLCD.setColor(0, 0, 0); 
  myGLCD.fillRect(84,76,233,154);
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.drawRect(84,76,233,154);
  myGLCD.setFont(BigFont);
  myGLCD.print("Invalid",CENTER, 76+11);
  myGLCD.print("time!",CENTER, 76+11+16+6);
  myGLCD.setFont(SmallFont);
  byte proceed = 0;
  while (proceed == 0) {
    if (myTouch.dataAvailable()) {
      myTouch.read();
      proceed=1;
    }
    myGLCD.print("Touch to continue",CENTER, 131);
    delay(250);
    myGLCD.print("                 ",CENTER, 131);
    delay(250);
  }
  resetTouch();
  myGLCD.setColor(0, 0, 0); 
  myGLCD.fillRect(84,76,233,154);
  drawSaveAndReturnButton_SetClockScreen();
}
