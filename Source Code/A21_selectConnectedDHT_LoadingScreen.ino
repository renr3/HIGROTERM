/*
 * This function draws the sensor selection interface, that allows the user to select which DHT sensors are connected to the system.
 */


void drawSensorSelectionInterface_LoadingScreen() {//Draw the interface for user selection of which channels are connected. Used only on the Loading Screen
  for (uint8_t ii = 0; ii < 8; ii++) {//Resets the selectedChannels vector, to allow new user inputs. Necessary if the user came to Loading Screen from Configuration Screen
    selectedChannels[ii] = 0;
  }
  for (uint8_t ii = 0; ii < 8; ii++) {//Draws sensor channel buttons
    //All are initialized in Not Selected style, which is represented by a grey colour
    sensorSelectionButton_NotSelected_LoadingScreen(ii);
  }
  //Draws OK button
  drawOKButton_LoadingScreen();
}
