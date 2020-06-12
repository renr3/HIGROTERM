/* Although this sliding bar is in practice a button, it constains mechanics that are particular to it, 
 * such as the need to have its top text updated accordingly to the sliding of the bar.
 * It was considered better to allocate both functions here, for better clarity, then in the all buttons file.
 */

//Draws the set frequency sliding bar interface at the Configuration screen
void drawSetSamplingFrequency_SlidingBar_ConfigScreen(int sliderY_min, int sliderY_max) {
  char tempMessage[34];
  char str_temp[5];
  float temp;
  temp = (float)fs / (float)(60000); //Transform from fs, that is given in miliseconds, to minutes
  dtostrf(temp, 4, 2, str_temp); //Converts temp to string
  myGLCD.setFont(SmallFont);
  sprintf(tempMessage, "Sampling once every %s minutes", str_temp);
  myGLCD.print(tempMessage, CENTER, 45);

  int x_freq = map(fs, 60000, 300000 , 17, 303); //Maps the fs value from the range of 60s-300s (1min to 5min) to the scale of the sliding bar length, given in pixels from 17px to 303 px.
  myGLCD.drawRect(9, sliderY_min, 310, sliderY_max); // Slider
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRect(x_freq, sliderY_min + 1, (x_freq + 7), sliderY_max - 1); // Positioner
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(10, sliderY_min + 1, (x_freq - 1), sliderY_max - 1);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect((x_freq + 5), sliderY_min + 1, 309, sliderY_max - 1);
}

//Updates the sampling frequency and the sliding bar interface at the Configuration screen
void updateSamplingFrequency_SlidingBar_ConfigScreen(int x_freq, int sliderY_min, int sliderY_max ) {
  if (x_freq <= 17) { // Confines the area of the slider to be above 17 pixels
    x_freq = 17;
  }
  if (x_freq >= 303) { /// Confines the area of the slider to be under 303 pixels
    x_freq = 303;
  }
  fs = map(x_freq, 17, 303, 60000, 300000); //Maps the fs value from the range of 60s-300s (1min to 5min) to the scale of the sliding bar length, given in pixels from 17px to 303 px.
  // Draws the cursor position
  myGLCD.setColor(255, 255, 255);
  myGLCD.fillRect(x_freq, sliderY_min + 1, (x_freq + 7), sliderY_max - 1); //Cursor position
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRect(10, sliderY_min + 1, (x_freq - 1), sliderY_max - 1); //Left part of the sliding bar, filled with red
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect((x_freq + 5), sliderY_min + 1, 309, sliderY_max - 1); //Right part of the sliding bar, filled with grey colour
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(SmallFont);
  char tempMessage[34]; //Char array variable to store the message
  char str_temp[5]; //Char array to receive the converted float value of fs
  float temp; //Variable to store the fs value converted to minutes
  temp = (float)fs / (float)(60000); //Converts fs in miliseconds to minutes
  dtostrf(temp, 4, 2, str_temp); //Converts temp in float to string
  sprintf(tempMessage, "Sampling once every %s minutes", str_temp); //Builds the string and store in tempMessage variable
  myGLCD.print(F("                                  "), CENTER, 45); //Cleans the message space
  myGLCD.print(tempMessage, CENTER, 45); //Prints the message stating "Sampling once every XX minustes"
}
