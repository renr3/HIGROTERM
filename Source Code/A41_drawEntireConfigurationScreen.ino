/* This function draws all the graphical elements of the Configuration Screen. 
 * This function was useful so the Configuration Screen could be concisely redrawn when returning from Set Clock/Date Screen.
 * By separating this lines into a single function, we do not have to include all this code at the end of the Set Clock/Date Screen execution.
 */

void drawEntireConfigurationScreen(int sliderY_min,int sliderY_max) {//
  myGLCD.clrScr();
  //Title of the screen:
  myGLCD.setBackColor(0, 0, 0); // Sets the background color of the area where the text will be printed to black
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(BigFont); // Sets font to big
  myGLCD.print(F("System settings"), CENTER, 5);
  myGLCD.setFont(SmallFont);
  myGLCD.print(F("Sampling frequency"), CENTER, 30);

  
  drawSetSamplingFrequency_SlidingBar_ConfigScreen(sliderY_min, sliderY_max); //Draws the sliding interface. This function can be found on file A43.

  drawReloadConnectionsButton_ConfigScreen(); //Draws the Reload Connections Button
  drawHomeScreenButton_ConfigScreen(); //Draws the Home Screen Button
  drawTurnOffButton_ConfigScreen(); //Draws the Turn Off Button
  drawSetClockDateButton_ConfigScreen(); //Draws the Set Clock/Date Button
  drawSetLanguageENUKButton_ConfigScreen(); //Draws the Set Language button, with the EN/UK flag (default)
}
