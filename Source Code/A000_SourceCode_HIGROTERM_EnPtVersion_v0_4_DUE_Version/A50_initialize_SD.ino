/*
 * SD related functions will be stored in the A5X series of files
 */

//Initialize SD and test its connection.
//Needs to be performed everytime the SD card is inserted back into the system.
void initialize_SD() {
  //TODO 3: Implement SD card initialization in Monitoring Table Screen. Right now, it is just performed on Loading Screen. If you disconnect the SD card, you need to run Loading Screen again by using the Configuration Screen
  bool mysd = 0;
  byte ypos = 20;
  int initTime = millis();
  
  while (!mysd) {//Will repeat .begin method until SD card is properly initialized
    myGLCD.setFont(SmallFont); // Sets the font to small
    myGLCD.print(F("SD card: connecting"), LEFT, ypos); // Prints the string on the screen
    if (!sd.begin(SD_CHIP_SELECT, SPI_FULL_SPEED)) {// If .begin method returns 1, it means that the sd is not properly initialized yet, so a loading animation will be displayed
      //Loading animation: print loading dots on the screen.
      delay(150);
      myGLCD.print(F("."), 170, ypos);
      delay(150);
      myGLCD.print(F("."), 178, ypos);
      delay(150);
      myGLCD.print(F("."), 186, ypos);
      delay(150);
      myGLCD.print(F(" "), 170, ypos);
      delay(150);
      myGLCD.print(F(" "), 178, ypos);
      delay(150);
      myGLCD.print(F(" "), 186, ypos);
      if (millis()-initTime>1000) {//APAGAR: If 1 second has passed, bypass this verification. THIS IS TO BE USED ONLY FOR THE PAPER WRITING, SINCE OUR SD CARD SLOT IS MALFUNCTIONING
        mysd = 1;
      }
    }
    else {//If the .begin method returned 0, it means the SD card could be properly connected
      myGLCD.print(F("                       "), LEFT, ypos); // Prints the string on the screen
      myGLCD.print(F("SD card initialized!"), LEFT, ypos); // Prints the string on the screen
      mysd = 1; //Allows leaving the while loop
    }
  }
}
