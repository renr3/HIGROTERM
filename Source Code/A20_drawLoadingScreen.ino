void drawLoadingScreen() {//Draws the Loading Screen
  currentPage = 1; // Indicates that we are at Loading Screen
  myGLCD.clrScr(); //Clear screen
  myGLCD.setBackColor(0, 0, 0); // Sets the background color of the area where the text will be printed to black
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(BigFont);
  myGLCD.print(F("Configuring SD"), LEFT, 0);
  delay(250);
  initialize_SD(); //Initialize SD. See the function for details. It can be found on A50_initialize_SD file.
  findFileName_SD(); //Find a valid file name. See the functin for details
  myGLCD.setFont(BigFont);
  myGLCD.print(F("Configuring DHT"), LEFT, 45);
  myGLCD.setFont(SmallFont); // Sets font to big
  myGLCD.print(F("Touch in the connected channels, and,"), LEFT, 65);
  myGLCD.print(F("then, touch OK to connect them"), LEFT, 75);
  
  drawSensorSelectionInterface_LoadingScreen(); //Draws the sensor selection interface
  
  //Gets the user input. Only proceeds if OK button was pressed
  byte okButton = 0;
  while (okButton == 0) {//Perform these actions until okButton is pressed.
    okButton=getUserInput_LoadingScreen();
  }
  
  initializeSensorsDHT_LoadingScreen(); //Initialize the selected sensors. See the function for details
}
