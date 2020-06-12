/*
 * Draws an animation that simulates the system being shut down.
 * It is virtually unnecessary, because this function does not perform anytging besides the anumation.
 * But it was implemented so users can have a established method to turn the device off safely, without worrying about losing data from the SD.
 */
void drawTurnOffScreen() {//Draws a screen that will indicate that the user can turn the device off
  //A little animation is performed, even if unnecessary, to emulate a common turning off procedure usually followed by many devices.
  myGLCD.clrScr();
  myGLCD.setFont(BigFont);
  myGLCD.print(F("Shutting down"), CENTER, 100);
  myGLCD.print(F("the system"),CENTER, 120);
  for (uint8_t ii = 0; ii < 3; ii++) {
    //Loading animation: print loading dots on the screen.
    delay(150);
    myGLCD.print(".", 319 / 2 - 2 * 16, 140);
    delay(150);
    myGLCD.print(".", 319 / 2, 140);
    delay(150);
    myGLCD.print(".", 319 / 2 + 2 * 16, 140);
    delay(150);
    myGLCD.print(" ", 319 / 2 - 2 * 16, 140);
    delay(150);
    myGLCD.print(" ", 319 / 2, 140);
    delay(150);
    myGLCD.print(" ", 319 / 2 + 2 * 16, 140);
  }
  myGLCD.clrScr();
  myGLCD.print(F("You can turn off"), CENTER, 100);
  myGLCD.print(F("the device now"), CENTER, 120);
}
