/*
 * This functin gets the user input on the Set Clock Screen and performs the appropriate actions based on it.
 */

void getUserInput_SetClockScreen(){
//Check for user input
  byte exit_flag = 0; //Variable that will indicate whether to quit the Set Clock/Date Screen
  int buttonClicked = 0; //Variable that will receive the code of the button that was clicked by the user
  int delayAfterClick = 200; //Delay after pressing a button, so the user can see that his touch worked. Too high will increase latency and jeopardize user experience
  while (exit_flag == 0) {
    if (myTouch.dataAvailable()) {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      buttonClicked=getContainerTapped_SetClockScreen(); //Returns which button of the Set Clock/Date screen the user clicked. Note that x and y are global variables, so we don't need to explicitly pass them to the function
      
      switch (buttonClicked) {
        //Test each possibility of button to be pressed. There are 
      case 1://Tens House of hours container was clicked
        drawSelectionOfTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,1);//Draw time data containers/buttons
        delay(delayAfterClick);
        if (hoursTens>=2){
          hoursTens=0;
        } else {
          hoursTens++;
        }
        drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,1);//Draw time data containers/buttons
        break;
      case 2://Units House of hours container was clicked
      drawSelectionOfTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,2);//Draw time data containers/buttons
        delay(delayAfterClick);
        if (hoursUnits>=9){
          hoursUnits=0;
        } else {
          hoursUnits++;
        }
        drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,2);//Draw time data containers/buttons
        break;
      case 3://Tens House of minutes container was clicked
      drawSelectionOfTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,3);//Draw time data containers/buttons
        delay(delayAfterClick);
        if (minutesTens>=5){
          minutesTens=0;
        } else {
          minutesTens++;
        }
        drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,3);//Draw time data containers/buttons
        break;
      case 4://Units House of minutes container was clicked
      drawSelectionOfTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,4);//Draw time data containers/buttons
        delay(delayAfterClick);
        if (minutesUnits>=9){
          minutesUnits=0;
        } else {
          minutesUnits++;
        }
        drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,4);//Draw time data containers/buttons
        break;
      case 5://Tens House of seconds container was clicked
      drawSelectionOfTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,5);//Draw time data containers/buttons       
        delay(delayAfterClick);
        if (secondsTens>=5){
          secondsTens=0;
        } else {
          secondsTens++;
        }
        drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,5);//Draw time data containers/buttons
        break;
      case 6://Units House of seconds container was clicked
      drawSelectionOfTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,6);//Draw time data containers/buttons
        delay(delayAfterClick);
        if (secondsUnits>=9){
          secondsUnits=0;
        } else {
          secondsUnits++;
        }
        drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,6);//Draw time data containers/buttons
        break;
      case 7://Tens House of days container was clicked
      drawSelectionOfDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,1);
        delay(delayAfterClick);
        if (daysTens>=3){
          daysTens=0;
        } else {
          daysTens++;
        }
        drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,1);
        break;
      case 8://Units House of days container was clicked
      drawSelectionOfDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,2);
        delay(delayAfterClick);
        if (daysUnits>=9){
          daysUnits=0;
        } else {
          daysUnits++;
        }
        drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,2);
        break;
      case 9://Tens House of months container was clicked
      drawSelectionOfDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,3);
        delay(delayAfterClick);
        if (monthsTens>=1){
          monthsTens=0;
        } else {
          monthsTens++;
        }
        drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,3);
        break;
      case 10://Units House of months container was clicked
      drawSelectionOfDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,4);
        delay(delayAfterClick);
        if (monthsUnits>=9){
          monthsUnits=0;
        } else {
          monthsUnits++;
        }
        drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,4);
        break;
      case 11://Tens House of years container was clicked
      drawSelectionOfDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,5);
        delay(delayAfterClick);
        if (yearsTens>=9){
          yearsTens=0;
        } else {
          yearsTens++;
        }
        drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,5);
        break;
      case 12://Units House of years container was clicked
      drawSelectionOfDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,6);
       delay(delayAfterClick);
       if (yearsUnits>=9){
          yearsUnits=0;
        } else {
          yearsUnits++;
        }
        drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,6);
        break;
      case 13://Return button was clicked
        drawReturnButton_Inactive_SetClockScreen();//Draw Return button
        delay(delayAfterClick);
        exit_flag=1;//We can leave  the screen, since the Return button was clicked
        //We don't do anything before leaving
        break;
      case 14://Save and Return button was clicked
        drawSaveAndReturnButton_Inactive_SetClockScreen();//Draw Save and Return button
        delay(delayAfterClick);
        
        //We need to check if the date/time information is consistent/valid!
        if ((hoursTens*10+hoursUnits)>23) {//Checks if hours is higher than 23, which is invalid
          drawInvalidTime_SetClockScreen();//Draw warning message
          drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,0);//Draw time data containers/buttons
          drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,0);//Draw date data containers/buttons
        } else if ((monthsTens*10+monthsUnits)>12){//Checks if months are higher than 12, which is invalid
          drawInvalidDate_SetClockScreen();//Draw warning message
          drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,0);//Draw time data containers/buttons
          drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,0);//Draw date data containers/buttons
        } else if ((daysTens*10+daysUnits)==0 || (monthsTens*10+monthsUnits)==0){//Checks if days or months are equal to zero, which is invalid
          drawInvalidDate_SetClockScreen();//Draw warning message
          drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,0);//Draw time data containers/buttons
          drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,0);//Draw date data containers/buttons
        } else if ((((monthsTens*10+monthsUnits)==1)||((monthsTens*10+monthsUnits)==3)||((monthsTens*10+monthsUnits)==5)||((monthsTens*10+monthsUnits)==7)|| ((monthsTens*10+monthsUnits)==8)||((monthsTens*10+monthsUnits)==10)||((monthsTens*10+monthsUnits)==12))&&((daysTens*10+daysUnits)>31) ) { //Checks the months with 31 days
          drawInvalidDate_SetClockScreen();//Draw warning message
          drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,0);//Draw time data containers/buttons
          drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,0);//Draw date data containers/buttons
        } else if ((((monthsTens*10+monthsUnits)==2)||((monthsTens*10+monthsUnits)==4)||((monthsTens*10+monthsUnits)==6)||((monthsTens*10+monthsUnits)==9)||((monthsTens*10+monthsUnits)==11))&&((daysTens*10+daysUnits)>31)) {// Checks for the months with 30 days
          drawInvalidDate_SetClockScreen();//Draw warning message
          drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,0);//Draw time data containers/buttons
          drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,0);//Draw date data containers/buttons 
        } else if ( ((monthsTens*10+monthsUnits)==2)&&((daysTens*10+daysUnits)>29)) {
          //This code does not account for leap years yet...
          //TODO 5: Account for leap year (in: drawSetClockScreen())
          drawInvalidDate_SetClockScreen();//Draw warning message
          drawTimeContainers_SetClockScreen(hoursTens, hoursUnits, minutesTens, minutesUnits, secondsTens, secondsUnits,0);//Draw time data containers/buttons
          drawDateContainers_SetClockScreen(daysTens, daysUnits, monthsTens, monthsUnits, yearsTens, yearsUnits,0);//Draw date data containers/buttons
        } else {//If all the tests passed, then the time/date information is correct and we can proceed with seting the clock and returning to previous page
          exit_flag=1;//We can leave the screen, since the Save and Return button was clicked. First, we have to save the time and date
          rtc.set(secondsTens*10+secondsUnits, minutesTens*10+minutesUnits, hoursTens*10+hoursUnits, 1, daysTens*10+daysUnits, monthsTens*10+monthsUnits, yearsTens*10+yearsUnits);//System does not work with DayOfTheWeek, will always set to zero.
          //  RTCLib::set(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year)
        }
      break;
      default://If no button was pressed, do nothing
      break;
      }
    }  
  }
}
