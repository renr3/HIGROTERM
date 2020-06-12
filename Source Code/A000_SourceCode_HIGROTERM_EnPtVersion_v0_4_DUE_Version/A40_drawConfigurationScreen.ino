/* This function draws the Configuration Screen. 
 * When it finishes, it outputs the value of exit_flag, a byte variable.
 * This variable indicates where to proceed next:
 *  - A output of 1 indicates the main code will proceed to Loading Screen;
 *  - A output of 2 indicates the main code will proceed to Monitoring Table Screen.
 */

byte drawConfigurationScreen () {
  resetTouch();//Reset touch screen
  currentPage = 3; // Indicates that we are at Configuration Screen
  byte exit_flag = 0; /*While 0, sketch stays in Configuration Screen.
                        When not 0, sketch leaves Configuration Screen:
                          -When 1, it performs Loading Screen right after.
                          -When 2, it goes to Monitoring Table Screen.*/
  int sliderY_min = 65;
  int sliderY_max = sliderY_min + 15;

  drawEntireConfigurationScreen(sliderY_min,sliderY_max);//Draws all graphical elements from this screen

  while (exit_flag == 0) {
    if (myTouch.dataAvailable()) {
      myTouch.read();
      exit_flag = getUserInput_ConfigurationScreen(sliderY_min,sliderY_max);
      //Check the inputs the user may perform in the system while the Configuration Screen is displayed
    }
  }
  return exit_flag;
}

