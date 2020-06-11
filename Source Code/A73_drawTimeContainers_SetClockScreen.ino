/*
 * This function draws the Set Clock Screen time containers, and populates them with the last querried time obtained from the RTC clock or the last time setted by the user to be applied to the RTC clock.
 * The last parameter received in this function, the updateAll parameter, indicates wheter to update the entire time table, if equal to 0, or just a specific time container, being, left to right, 1 to 6 each container.
 */

void drawTimeContainers_SetClockScreen(byte hoursTens, byte hoursUnits, byte minutesTens, byte minutesUnits, byte secondsTens, byte secondsUnits, byte updateAll){
  //====================== Geometry parameters of the graphical elements of the Set Clock/Date Screen 
  //X direction position variables
  const byte initialRectX = 12;
  const byte incrementRectX = 36;
  const byte spacingRectX = 16;
  const byte nextRectX = incrementRectX + spacingRectX;
  const byte groupingOffset = 3; //Offset applied to each pair of data (e.g. hours, minutes, seconds, days, months, years), for better visualization
  //Y direction position variables
  const byte firstRowRectHeightY = 55;
  const byte incrementRectY = 40;
  const byte spacingRectY = incrementRectY+22;
  //Text offset position variables
  const byte textXoffset = 10;
  const byte textYoffset = 12;
  //Font style related variables
  const byte smallFontWidth=8; //Width of the SmallFont style, used to correctly ident text labels above each group.
  const byte smallFontYoffsetForGroupLabels=15; //Offset taken from the top of a group rectangles to insert the label.
  //Time separation circles position and geometry
  const byte circleXoffset = (spacingRectX+2*groupingOffset)/2; //it is the half of 22, which is the spacing between two different categories (e.g. hours and minutes), since original spacing was 16 and we made an offset of 3 from each side
  const byte circleYoffset = 8; //To be visually adjusted 
  const byte circleRadius = 3; //To be visually adjusted
  //Time separation circles position and geometry
  const byte LineInitialX = 6; //
  const byte LineFinalX = spacingRectX+2*groupingOffset-LineInitialX; 
  const byte LineInitialY = firstRowRectHeightY+spacingRectY; 
  const byte LineFinalY = firstRowRectHeightY+incrementRectY+spacingRectY; 

  char digitToBeDisplayed[2]; //Temporary holder of the digit to be displayed into each container. It is to be displayed 1 digit per container. A char array need, thus n+1 spaces to hold n values, because the last space must hold a null character. Therefore, we need a 2-char array.
  myGLCD.setFont(BigFont);  
  myGLCD.setBackColor(255, 0, 0); // Sets the background color of the area where the text will be printed to red

  //====================== Drawing of the graphical elements and information contained in each container, accordingly to the type of update informed by updateAll parameter
  switch (updateAll) {
   case 0: //We need to update the entire table
    //Hours
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(initialRectX+groupingOffset, firstRowRectHeightY, initialRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY);
    myGLCD.fillRect(initialRectX+nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(initialRectX+groupingOffset, firstRowRectHeightY, initialRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY);
    sprintf (digitToBeDisplayed, "%d", hoursTens);
    myGLCD.print(digitToBeDisplayed,initialRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset);
    myGLCD.drawRect(initialRectX+nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", hoursUnits);
    myGLCD.print(digitToBeDisplayed,initialRectX+nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset);
    //Minutes
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(initialRectX+2*nextRectX+groupingOffset, firstRowRectHeightY, initialRectX+2*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.fillRect(initialRectX+3*nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+3*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(initialRectX+2*nextRectX+groupingOffset, firstRowRectHeightY, initialRectX+2*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", minutesTens);
    myGLCD.print(digitToBeDisplayed,initialRectX+2*nextRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset);
    myGLCD.drawRect(initialRectX+3*nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+3*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", minutesUnits);
    myGLCD.print(digitToBeDisplayed,initialRectX+3*nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset);
    //Seconds
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(initialRectX+4*nextRectX+groupingOffset, firstRowRectHeightY, initialRectX+4*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.fillRect(initialRectX+5*nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+5*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(initialRectX+4*nextRectX+groupingOffset, firstRowRectHeightY, initialRectX+4*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", secondsTens);
    myGLCD.print(digitToBeDisplayed,initialRectX+4*nextRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset);
    myGLCD.drawRect(initialRectX+5*nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+5*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", secondsUnits);
    myGLCD.print(digitToBeDisplayed,initialRectX+5*nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset);
    //Draw the : separing hours, minutes and seconds
    //The x and y, which specify the center of the circle, values take as reference the next rectangle that follows the circle.
    //Hours from minutes separation circles
    myGLCD.fillCircle(initialRectX+2*nextRectX+groupingOffset-circleXoffset,firstRowRectHeightY-circleYoffset+incrementRectY/2,circleRadius);
    myGLCD.fillCircle(initialRectX+2*nextRectX+groupingOffset-circleXoffset,firstRowRectHeightY+circleYoffset+incrementRectY/2,circleRadius);
    //Minutes from seconds separation circles
    myGLCD.fillCircle(initialRectX+4*nextRectX+groupingOffset-circleXoffset,firstRowRectHeightY-circleYoffset+incrementRectY/2,circleRadius);
    myGLCD.fillCircle(initialRectX+4*nextRectX+groupingOffset-circleXoffset,firstRowRectHeightY+circleYoffset+incrementRectY/2,circleRadius);
   break;
   case 1: //Update just the Tens of Hours container   
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(initialRectX+groupingOffset, firstRowRectHeightY, initialRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(initialRectX+groupingOffset, firstRowRectHeightY, initialRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY);
    sprintf (digitToBeDisplayed, "%d", hoursTens);
    myGLCD.print(digitToBeDisplayed,initialRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset);
   break;
   case 2:
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(initialRectX+nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(initialRectX+nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", hoursUnits);
    myGLCD.print(digitToBeDisplayed,initialRectX+nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset);
   break;
   case 3:
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(initialRectX+2*nextRectX+groupingOffset, firstRowRectHeightY, initialRectX+2*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(initialRectX+2*nextRectX+groupingOffset, firstRowRectHeightY, initialRectX+2*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", minutesTens);
    myGLCD.print(digitToBeDisplayed,initialRectX+2*nextRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset);
   break;
   case 4:
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(initialRectX+3*nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+3*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(initialRectX+3*nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+3*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", minutesUnits);
    myGLCD.print(digitToBeDisplayed,initialRectX+3*nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset);
   break;
   case 5:
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(initialRectX+4*nextRectX+groupingOffset, firstRowRectHeightY, initialRectX+4*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(initialRectX+4*nextRectX+groupingOffset, firstRowRectHeightY, initialRectX+4*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", secondsTens);
    myGLCD.print(digitToBeDisplayed,initialRectX+4*nextRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset);
   break;
   case 6:
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(initialRectX+5*nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+5*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRect(initialRectX+5*nextRectX-groupingOffset, firstRowRectHeightY, initialRectX+5*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY); 
    sprintf (digitToBeDisplayed, "%d", secondsUnits);
    myGLCD.print(digitToBeDisplayed,initialRectX+5*nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset);
   break;
  }
}
