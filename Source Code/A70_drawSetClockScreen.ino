void drawSetClockScreen() {//Draws the Set Clock and Date Screen
  myGLCD.clrScr();
  resetTouch();//Reset touch screen
  myGLCD.setBackColor(0, 0, 0); // Sets the background color of the area where the text will be printed to black
  myGLCD.setColor(255, 255, 255); // Sets color to white
  myGLCD.setFont(BigFont); // Sets font to big
  myGLCD.print("Set Clock", CENTER, 5); // Prints the string on the screen
  myGLCD.setFont(SmallFont); // Sets font to small
  myGLCD.print("Tap on the numbers to set the value", CENTER, 25); // Prints the string on the screen

/*  //Variables to store time and data and each decimal place (tens and units)
  byte hours = 0; byte minutes = 0; byte seconds = 0; byte days = 0; byte months = 0; byte years = 0;
  byte hoursTens = 0; byte hoursUnits = 0; byte minutesTens = 0; byte minutesUnits = 0; byte secondsTens = 0; byte secondsUnits = 0;
  byte daysTens = 0; byte daysUnits = 0; byte monthsTens = 0; byte monthsUnits = 0; byte yearsTens = 0; byte yearsUnits = 0;*/

  //Get date and time using RTC functions and pass them to drawTimeContainers and drawDateContainers
  rtc.refresh();
  hours = rtc.hour();
  minutes = rtc.minute();
  seconds = rtc.second();  
  years = rtc.year();
  months = rtc.month();
  days = rtc.day();
  
  //Divide date and time into units and tens
  hoursTens = hours/10; hoursUnits = hours%10; minutesTens = minutes/10; minutesUnits = minutes%10; secondsTens = seconds/10; secondsUnits = seconds%10;
  daysTens = days/10; daysUnits = days%10; monthsTens = months/10; monthsUnits = months%10; yearsTens = years/10; yearsUnits = years%10;

  //(Added on v0.3): Handling invalid values of RTC Clock configuration, which may occur when Clock is badly wired and the abover querry gets double digits for hoursTens, hoursUnits, minutesTens, etc.
  validateTimeContainers(&hoursTens, &hoursUnits, &minutesTens, &minutesUnits, &secondsTens, &secondsUnits);
  validateDateContainers(&daysTens, &daysUnits, &monthsTens, &monthsUnits, &yearsTens, &yearsUnits);

  drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,0);//Draw time data containers/buttons
  drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,0);//Draw date data containers/buttons
  drawContainersLabels_SetClockScreen();//Draw containers label
  drawReturnButton_SetClockScreen();//Draw Return button
  drawSaveAndReturnButton_SetClockScreen();//Draw Save and Return button
  getUserInput_SetClockScreen(); //Get the user input and performs the appropriate actions based on it
}
