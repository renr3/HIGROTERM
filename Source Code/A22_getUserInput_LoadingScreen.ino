/*
   This function gets the user input at the Loading Screen, i.e. which sensors were selected as present and if the OK button was pressed.
   It updates the graphics of the buttons pressed, highlighting in red the buttons related to the selected sensors.
   It returns the state of the OK button: if it was pressed, it returns 1, if not, it returns 0.
*/

bool getUserInput_LoadingScreen() {
  //Check which button has been pressed
  bool okButton = 0; //indicates wheter OK button was pressed, if it is set to 1

  if (myTouch.dataAvailable()) {
    myTouch.read();
    x = myTouch.getX(); // X coordinate where the screen has been pressed
    y = myTouch.getY(); // Y coordinates where the screen has been pressed
  }
  for (uint8_t ii = 0; ii < 8; ii++) {// Check which channel button was pressed, and replace by the appropriate style button indicating pressed or not pressed
    if ((x >= sensorSelectionBut_LoadingScreen_Xwidth * ii) && (x <= sensorSelectionBut_LoadingScreen_Xwidth * (1 + ii) - 1) && (y >= sensorSelectionBut_LoadingScreen_Ymin) && (y <= sensorSelectionBut_LoadingScreen_Ymax) && selectedChannels[ii] == 0) { //Check if button was pressed and if its current state is NOT selected
      //Updates the button style to Selected, by applying a red colour style
      sensorSelectionButton_Selected_LoadingScreen(ii);
      selectedChannels[ii] = 1;
      resetTouch();
    }
    //Check if button was pressed and was pressed before
    if ((x >= sensorSelectionBut_LoadingScreen_Xwidth * ii) && (x <= sensorSelectionBut_LoadingScreen_Xwidth * (1 + ii) - 1) && (y >= sensorSelectionBut_LoadingScreen_Ymin) && (y <= sensorSelectionBut_LoadingScreen_Ymax) && selectedChannels[ii] == 1) { //Check if button was pressed and if its current state is selected
      //Updates the button style to Not Selected, by applying a grey colour style
      sensorSelectionButton_NotSelected_LoadingScreen(ii);
      selectedChannels[ii] = 0;
      resetTouch();
    }
  }
  if ((x >= OKBut_LoadingScreen_Xmin) && (x <= OKBut_LoadingScreen_Xmax) && (y >= OKBut_LoadingScreen_Ymin) && (y <= OKBut_LoadingScreen_Ymax)) {// Ckech if OK button was pressed
    //Change button style to grey, so the user will see the button has been pressed
    drawOKButton_Inactive_LoadingScreen();
    okButton = 1;
    resetTouch();
  }
  delay(150); //A little delay so the user can see the buttons changing colours when pressed
  return okButton;
}
