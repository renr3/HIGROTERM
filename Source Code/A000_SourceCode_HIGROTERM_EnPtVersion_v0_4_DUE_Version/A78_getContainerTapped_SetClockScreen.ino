
byte getContainerTapped_SetClockScreen(){
  //====================== Geometry parameters of the buttons of the Set Clock/Date Screen 
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
  
  byte buttonClicked = 0;
  if ((x >=  initialRectX+groupingOffset) && (x <= initialRectX+incrementRectX+groupingOffset) && (y >= firstRowRectHeightY) && (y <= firstRowRectHeightY+incrementRectY)) { //Tens House container of the hour was touched
        buttonClicked = 1;
      } else if ((x >= initialRectX+nextRectX-groupingOffset) && (x <= initialRectX+nextRectX+incrementRectX-groupingOffset) && (y >= firstRowRectHeightY) && (y <= firstRowRectHeightY+incrementRectY)) { //Unit House container of the hour was touched
        buttonClicked = 2;
      } else if ((x >= initialRectX+2*nextRectX+groupingOffset) && (x <= initialRectX+2*nextRectX+incrementRectX+groupingOffset) && (y >= firstRowRectHeightY) && (y <= firstRowRectHeightY+incrementRectY)) { //Tens House container of the minutes was touched
        buttonClicked = 3;
      } else if ((x >= initialRectX+3*nextRectX-groupingOffset) && (x <= initialRectX+3*nextRectX+incrementRectX-groupingOffset) && (y >= firstRowRectHeightY) && (y <= firstRowRectHeightY+incrementRectY)) { //Units House container of the minutes was touched
        buttonClicked = 4;
      } else if ((x >= initialRectX+4*nextRectX+groupingOffset) && (x <= initialRectX+4*nextRectX+incrementRectX+groupingOffset) && (y >= firstRowRectHeightY) && (y <= firstRowRectHeightY+incrementRectY)) {//Tens House container of the seconds was touched
        buttonClicked = 5;
      } else if ((x >= initialRectX+5*nextRectX-groupingOffset) && (x <= initialRectX+5*nextRectX+incrementRectX-groupingOffset) && (y >= firstRowRectHeightY) && (y <= firstRowRectHeightY+incrementRectY)) {//Units House container of the seconds was touched
        buttonClicked = 6;
      } else if ((x >=  initialRectX+groupingOffset) && (x <= initialRectX+incrementRectX+groupingOffset) && (y >= firstRowRectHeightY+spacingRectY) && (y <= firstRowRectHeightY+incrementRectY+spacingRectY)) { //Tens House container of the days was touched
        buttonClicked = 7;
      } else if ((x >= initialRectX+nextRectX-groupingOffset) && (x <= initialRectX+nextRectX+incrementRectX-groupingOffset) && (y >= firstRowRectHeightY+spacingRectY) && (y <= firstRowRectHeightY+incrementRectY+spacingRectY)) { //Unit House container of the days was touched
        buttonClicked = 8;
      } else if ((x >= initialRectX+2*nextRectX+groupingOffset) && (x <= initialRectX+2*nextRectX+incrementRectX+groupingOffset) && (y >= firstRowRectHeightY+spacingRectY) && (y <= firstRowRectHeightY+incrementRectY+spacingRectY)) { //Tens House container of the months was touched
        buttonClicked = 9;
      } else if ((x >= initialRectX+3*nextRectX-groupingOffset) && (x <= initialRectX+3*nextRectX+incrementRectX-groupingOffset) && (y >= firstRowRectHeightY+spacingRectY) && (y <= firstRowRectHeightY+incrementRectY+spacingRectY)) { //Units House container of the months was touched
        buttonClicked = 10;
      } else if ((x >= initialRectX+4*nextRectX+groupingOffset) && (x <= initialRectX+4*nextRectX+incrementRectX+groupingOffset) && (y >= firstRowRectHeightY+spacingRectY) && (y <= firstRowRectHeightY+incrementRectY+spacingRectY)) {//Tens House container of the years was touched
        buttonClicked = 11;
      } else if ((x >= initialRectX+5*nextRectX-groupingOffset) && (x <= initialRectX+5*nextRectX+incrementRectX-groupingOffset) && (y >= firstRowRectHeightY+spacingRectY) && (y <= firstRowRectHeightY+incrementRectY+spacingRectY)) {//Units House container of the years was touched
        buttonClicked = 12;
      } else if ((x >= 15) && (x <= 15+36) && (y >= 202-20) && (y <= 232-20)) {//Return button was touched
        buttonClicked = 13;
      } else if ((x >= 319-14-36) && (x <= 319-15) && (y >= 202-20) && (y <= 232-20)) {//Save and Return button was touched
        buttonClicked = 14;
      }
      return buttonClicked;
}
