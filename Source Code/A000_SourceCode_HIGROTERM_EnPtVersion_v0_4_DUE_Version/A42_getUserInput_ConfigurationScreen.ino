/* This function gets the user input on the Configuration Screen. 
 * In the case of an input instructing to move to a different screen, the function returns the result of such input in the form of a byte variable called exit_flag.
 * Each next screen is encoded in the form of a value (from 1 to 3), that indicates to which screen the main code will proceed next.
 * Returning an exit_flag equals to 0 will indicate the main code to continue in the Configuration Screen.
 */

byte getUserInput_ConfigurationScreen(int sliderY_min,int sliderY_max){
  byte exit_flag = 0;
  x = myTouch.getX();
  y = myTouch.getY();

  if ( (y >= sliderY_min) && (y <= sliderY_max)) { //Slide touched, updates sampling frequency
    updateSamplingFrequency_SlidingBar_ConfigScreen(x, sliderY_min, sliderY_max);
  } else if ((x >= ReloadBut_ConfigScreen_Xmin) && (x <= ReloadBut_ConfigScreen_Xmax) && (y >= ReloadBut_ConfigScreen_Ymin) && (y <= ReloadBut_ConfigScreen_Ymax)) { //Reload Connections button touched
    drawReloadConnectionsButton_Inactive_ConfigScreen();
    delay(250);
    exit_flag = 1;
  } else if ((x >= HomeScreenBut_ConfigScreen_Xmin) && (x <= HomeScreenBut_ConfigScreen_Xmax) && (y >= HomeScreenBut_ConfigScreen_Ymin) && (y <= HomeScreenBut_ConfigScreen_Ymax)) { //Home Screen button touched
    drawHomeScreenButton_Inactive_ConfigScreen();
    delay(250);
    exit_flag = 2;
  } else if ((x >= TurnOffBut_ConfigScreen_Xmin) && (x <= TurnOffBut_ConfigScreen_Xmax) && (y >= TurnOffBut_ConfigScreen_Ymin) && (y <= TurnOffBut_ConfigScreen_Ymax)) { //Turn Off button touched
    drawTurnOffButton_Inactive_ConfigScreen();
    delay(250);
    exit_flag = 3;
  } else if ((x >= SetClockDateBut_ConfigScreen_Xmin) && (x <= SetClockDateBut_ConfigScreen_Xmax) && (y >= SetClockDateBut_ConfigScreen_Ymin) && (y <= SetClockDateBut_ConfigScreen_Ymax)) { //Set Clock/Date button touched
    drawSetClockDateButton_Inactive_ConfigScreen();
    delay(250);
    drawSetClockScreen();
    drawEntireConfigurationScreen(sliderY_min, sliderY_max); //Redraws the Configuration Screen after exiting Set Clock/Date Screen
  } else if ((x >= SetLanguageBut_ConfigScreen_Xmin) && (x <= SetLanguageBut_ConfigScreen_Xmax) && (y >= SetLanguageBut_ConfigScreen_Ymin) && (y <= SetLanguageBut_ConfigScreen_Ymax)) {//Set Clock/Date button touched
    if (language == 0) { //Language was set to EN/UK. Thus, we have to change for PT/BR
      language = 1;
      drawSetLanguagePTBRButton_ConfigScreen();
    } else if (language == 1) {//Language was set to PT/BR. Thus, we have to change for EN/UK
      language = 0;
      drawSetLanguageENUKButton_ConfigScreen();
    }
    delay(250);
    //"exit_flag" is not set to any value here because we don't want the sketch to leave the Configuration Screen after changing Language.
  }
  return exit_flag;
}
