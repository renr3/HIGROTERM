void drawInitialScreen() {//Draws the Initiral Screen
  myGLCD.setBackColor(0, 0, 0); // Sets the background color of the area where the text will be printed to black
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(GroteskBold32x64); // Sets font to the external library GroteskBold32x64
  myGLCD.print(F("HIGROTERM"), CENTER, 30); // Prints the title
  myGLCD.setFont(BigFont); // Sets font to BigFont, that comes with the UTFT library
  myGLCD.print(F("temperature and"), CENTER, 100);
  myGLCD.print(F("humidity"), CENTER, 120);
  myGLCD.print(F("monitoring"), CENTER, 140);
  myGLCD.print(F("system"), CENTER, 160);
  myGLCD.setColor(255, 0, 0); // Sets color to red
  myGLCD.drawLine(0, 200, 319, 200); // Draws a red line
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(SmallFont); // Sets the font to SmallFont, that comes with the UTFT library
  myGLCD.print(F("University of Brasilia/PECC: v0.1/10-19"), CENTER, 210);
  myGLCD.print(F("renan.rocha.ribeiro@gmail.com"), CENTER, 224);

  //Wait for user imput to proceed with sketch
  byte proceed = 0;//Variable to control wheter the screen was touched
  while (!proceed) {//Run this loop until variable "proceed" assumes a value equal to "1"
    myGLCD.setFont(SmallFont);
    //Display a little animation to indicate for the user that the system is waiting for a command
    myGLCD.print(F("Touch on the screen to proceed"), CENTER, 180);
    delay(250);
    myGLCD.print(F("                              "), CENTER, 180);
    delay(250);
    if (myTouch.dataAvailable()) {
      myTouch.read();
      proceed = 1;
    }
  }
}
