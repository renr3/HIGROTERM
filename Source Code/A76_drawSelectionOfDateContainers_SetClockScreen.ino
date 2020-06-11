/*
 * This function draws an animation that greys-out the selected container indicated by the updateAll parameter.
 * Its template is almost identical to drawTimeContainers_SetClockScreen function.
 * The only difference is that it colors the background of the time container with grey colour, intead of a red color.
 * The time values need to be passed because when the container is redraw, it erases the value, requiring it to be printed again.
 * So, the last value, before updating to the next value of the container, is used to biuld the greyed-out version of the selected time container.
 */

void drawSelectionOfDateContainers_SetClockScreen(byte daysTens, byte daysUnits, byte monthsTens, byte monthsUnits, byte yearsTens, byte yearsUnits, byte updateAll){
   //updateAll variable indicates wheter to update the entire table, if equal to 0, or just a specific container, being, left rto right, 1 to 6 each container 
  //====================== Geometry parameters of the buttons of the Set Clock/Date Screen 
  //X direction position variables
  int initialRectX = 12;
  int incrementRectX = 36;
  int spacingRectX = 16;
  int nextRectX = incrementRectX + spacingRectX;
  int groupingOffset = 3; //Offset applied to each pair of data (e.g. hours, minutes, seconds, days, months, years), for better visualization
  //Y direction position variables
  int firstRowRectHeightY = 55;
  int incrementRectY = 40;
  int spacingRectY = incrementRectY+22;
  //Text offset position variables
  int textXoffset = 10;
  int textYoffset = 12;
  //Font style related variables
  int smallFontWidth=8; //Width of the SmallFont style, used to correctly ident text labels above each group.
  int smallFontYoffsetForGroupLabels=15; //Offset taken from the top of a group rectangles to insert the label.
  //Time separation circles position and geometry
  int circleXoffset = (spacingRectX+2*groupingOffset)/2; //it is the half of 22, which is the spacing between two different categories (e.g. hours and minutes), since original spacing was 16 and we made an offset of 3 from each side
  int circleYoffset = 8; //To be visually adjusted 
  int circleRadius = 3; //To be visually adjusted
  //Time separation circles position and geometry
  int LineInitialX = 6; //
  int LineFinalX = spacingRectX+2*groupingOffset-LineInitialX; 
  int LineInitialY = firstRowRectHeightY+spacingRectY; 
  int LineFinalY = firstRowRectHeightY+incrementRectY+spacingRectY;
  //Font style
  myGLCD.setFont(BigFont);  
  myGLCD.setBackColor(160, 160, 160); // Sets the background color of the area where the text will be printed to red

  char digitToBeDisplayed[2]; //Temporary holder of the digit to be displayed into each container
  
  switch (updateAll) {
   case 0: //We need to update the entire table
   //Day
  myGLCD.setColor(160, 160, 1600);
  myGLCD.fillRect(initialRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY); 
  myGLCD.fillRect(initialRectX+nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(initialRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", daysTens); 
  myGLCD.print(digitToBeDisplayed,initialRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
  myGLCD.drawRect(initialRectX+nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY); 
  sprintf (digitToBeDisplayed, "%d", daysUnits); 
  myGLCD.print(digitToBeDisplayed,initialRectX+nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
  //Month
  myGLCD.setColor(160, 160, 160);
  myGLCD.fillRect(initialRectX+2*nextRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+2*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY); 
  myGLCD.fillRect(initialRectX+3*nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+3*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(initialRectX+2*nextRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+2*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", monthsTens); 
  myGLCD.print(digitToBeDisplayed,initialRectX+2*nextRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
  myGLCD.drawRect(initialRectX+3*nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+3*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", monthsUnits); 
  myGLCD.print(digitToBeDisplayed,initialRectX+3*nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
  //Year
  myGLCD.setColor(160, 160, 160);
  myGLCD.fillRect(initialRectX+4*nextRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+4*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  myGLCD.fillRect(initialRectX+5*nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+5*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(initialRectX+4*nextRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+4*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", yearsTens);
  myGLCD.print(digitToBeDisplayed,initialRectX+4*nextRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
  myGLCD.drawRect(initialRectX+5*nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+5*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", yearsUnits);
  myGLCD.print(digitToBeDisplayed,initialRectX+5*nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
  //Draw bars separating days, months and years
  //The bar coordinates are defined taking as reference the next rectangle that follows the bar.
  myGLCD.drawLine(initialRectX+2*nextRectX+groupingOffset-LineInitialX,LineInitialY, initialRectX+2*nextRectX+groupingOffset-LineFinalX,LineFinalY);
  myGLCD.drawLine(initialRectX+4*nextRectX+groupingOffset-LineInitialX,LineInitialY, initialRectX+4*nextRectX+groupingOffset-LineFinalX,LineFinalY);
   break;
   case 1:
   myGLCD.setColor(160, 160, 160);
  myGLCD.fillRect(initialRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(initialRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", daysTens); 
  myGLCD.print(digitToBeDisplayed,initialRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
   break;
   case 2:
    myGLCD.setColor(160, 160, 160);
  myGLCD.fillRect(initialRectX+nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(initialRectX+nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY); 
  sprintf (digitToBeDisplayed, "%d", daysUnits); 
  myGLCD.print(digitToBeDisplayed,initialRectX+nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
   break;
   case 3:
    myGLCD.setColor(160, 160, 160);
  myGLCD.fillRect(initialRectX+2*nextRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+2*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY); 
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(initialRectX+2*nextRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+2*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", monthsTens); 
  myGLCD.print(digitToBeDisplayed,initialRectX+2*nextRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
  
   break;
   case 4:
    myGLCD.setColor(160, 160, 160);
   myGLCD.fillRect(initialRectX+3*nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+3*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
 myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(initialRectX+3*nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+3*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", monthsUnits); 
  myGLCD.print(digitToBeDisplayed,initialRectX+3*nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
   break;
   case 5:
   myGLCD.setColor(160, 160, 160);
  myGLCD.fillRect(initialRectX+4*nextRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+4*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(initialRectX+4*nextRectX+groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+4*nextRectX+incrementRectX+groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", yearsTens);
  myGLCD.print(digitToBeDisplayed,initialRectX+4*nextRectX+textXoffset+groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
  break;
   case 6:
   myGLCD.setColor(160, 160, 160);
   myGLCD.fillRect(initialRectX+5*nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+5*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRect(initialRectX+5*nextRectX-groupingOffset, firstRowRectHeightY+spacingRectY, initialRectX+5*nextRectX+incrementRectX-groupingOffset, firstRowRectHeightY+incrementRectY+spacingRectY);
  sprintf (digitToBeDisplayed, "%d", yearsUnits);
  myGLCD.print(digitToBeDisplayed,initialRectX+5*nextRectX+textXoffset-groupingOffset, firstRowRectHeightY+textYoffset+spacingRectY);
   break;
  }
}

