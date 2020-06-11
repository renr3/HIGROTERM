/*
 * This function draws the labels above each containers, e.g.: "Hours", "Minutes", "Seconds", "Day", "Month", "Year"
 */

void drawContainersLabels_SetClockScreen(){
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
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(0, 0, 0); // Sets the background color of the area where the text will be printed to black
  //Draw labels above each group to identify hours, minutes, seconds, day, month, year.
  myGLCD.print("Hours", -2*smallFontWidth+((initialRectX+groupingOffset)+(initialRectX+nextRectX+incrementRectX-groupingOffset))/2, firstRowRectHeightY-smallFontYoffsetForGroupLabels);//The X value is computed by calculating the middle pixel of the group, and, then, offsetting the appropriate width calculated from half of the characters quantity in the text 
  myGLCD.print("Minutes", CENTER, firstRowRectHeightY-smallFontYoffsetForGroupLabels);
  myGLCD.print("Seconds", -3*smallFontWidth+((initialRectX+4*nextRectX+groupingOffset)+(initialRectX+5*nextRectX+incrementRectX-groupingOffset))/2, firstRowRectHeightY-smallFontYoffsetForGroupLabels);//The X value is computed by calculating the middle pixel of the group, and, then, offsetting the appropriate width calculated from half of the characters quantity in the text 
  myGLCD.print("Day", -1*smallFontWidth+((initialRectX+groupingOffset)+(initialRectX+nextRectX+incrementRectX-groupingOffset))/2, firstRowRectHeightY+spacingRectY-smallFontYoffsetForGroupLabels);//The X value is computed by calculating the middle pixel of the group, and, then, offsetting the appropriate width calculated from half of the characters quantity in the text 
  myGLCD.print("Month", CENTER, firstRowRectHeightY+spacingRectY-smallFontYoffsetForGroupLabels);
  myGLCD.print("Year", -2*smallFontWidth+((initialRectX+4*nextRectX+groupingOffset)+(initialRectX+5*nextRectX+incrementRectX-groupingOffset))/2, firstRowRectHeightY+spacingRectY-smallFontYoffsetForGroupLabels);//The X value is computed by calculating the middle pixel of the group, and, then, offsetting the appropriate width calculated from half of the characters quantity in the text 
}

