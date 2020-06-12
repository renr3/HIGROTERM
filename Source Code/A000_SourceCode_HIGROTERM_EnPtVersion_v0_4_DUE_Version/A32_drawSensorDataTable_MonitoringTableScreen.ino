/*
   This function draws the Sensor Data Table outline at the Monitoring Table Screen

   The table is to be represented as: Sensor|Temperature|RH || Sensor|Temperature|RH,
   with a total of four rows on each side of the table.
   This allows representing 8 sensor datas.

   The rows associated with connected sensors receive a red coloured background.
   The rows associa ted with non-connected sensors receive a grey coloured background.
*/


void drawSensorDataTable_MonitoringTableScreen () {

  //Declaring the vectors that will hold the colors of each row in the Sensor Data Table
  //The colors are stored in RGB values
  //The rows are divided in right hand side and left hand side, with each side having 4 rows.
  uint8_t rowColors_LeftHandSide[4][3];
  uint8_t rowColors_RightHandSide[4][3];

  //Initiate row colors vector.
  //Check which rows are associated to sensors that are not connected, applying the grey color (160,160,160)
  //and which rows are associated to sensors that are connected, applying the red color (255,0,0)
  for (byte ii = 0; ii < 4; ii++) {
    //Check the left hand side rows
    if (selectedChannels[ii] == 0) {
      rowColors_LeftHandSide[ii][0] = 160;
      rowColors_LeftHandSide[ii][1] = 160;
      rowColors_LeftHandSide[ii][2] = 160;
    } else {
      rowColors_LeftHandSide[ii][0] = 255;
      rowColors_LeftHandSide[ii][1] = 0;
      rowColors_LeftHandSide[ii][2] = 0;
    }
    //Check the right hand side rows
    if (selectedChannels[ii + 4] == 0) {
      rowColors_RightHandSide[ii][0] = 160;
      rowColors_RightHandSide[ii][1] = 160;
      rowColors_RightHandSide[ii][2] = 160;
    } else {
      rowColors_RightHandSide[ii][0] = 255;
      rowColors_RightHandSide[ii][1] = 0;
      rowColors_RightHandSide[ii][2] = 0;
    }
  }

  //Draw Sensor data boxes - First column for sensor labels
  // Graphical variables
  uint8_t xIdent = 5;
  uint8_t yHeader = 80;
  uint8_t ySpacing = 10;
  uint8_t xSpacing = 5;
  uint8_t boxHeight = 30;
  uint8_t boxWidth = 40;
  uint8_t boxExtraWidth = 9;
  //The cells_Xparameter is a value used to define the X coordinate of the rightmost vertices of the Sensor Data Table cells.
  //Depending on the column being draw, this value is multiplied by a proper parameter to position the column's cell on the screen.
  uint8_t cells_Xparameter = boxWidth + xSpacing + boxExtraWidth;
  //The cells_Yparameter is a value used to define the Y coordinate of the rightmost vertices of the Sensor Data Table cells.
  //Depending on the row being draw, this value is multiplied by a proper parameter to position the column's cell on the screen.
  uint8_t cells_Yparameter = boxHeight + ySpacing;

  char sensorLabel[3];
  uint8_t columnNumber = 0;
  uint8_t rowColors_Temporary[4][3]; //Temporary colour vector, to hold the present colour to be used in the cell being draw

  //Prints the first column, Sensor, of both left and right hand sides
  for (uint8_t columnIterator = 0; columnIterator < 2; columnIterator++) {
    //The columnNumber is a helpful parameter that will perform the necessary offset between the first Sensor column to the second
    //The first Sensor column is the first column of the Sensor Data Table, so it starts after a proper ident from the left-most side of the screen
    //The second Sensor column, however, is the 4 column in the Sensor Data Table, and its positioning must take into account the presence of the other columns.
    //The variable columnNumber takes this fact into account.
    //v0.4 noteL: Its logic is a legacy from early implementations, when each column had its own block of code, i.e. there were no for loops as implemented on v0.4.
    //            In that implementation, the first Sensor column was the Sensor Data Table column #1 and the second Sensor column was column #4.
    //In this Switch we also choose the appropriate color vector, depending on which sensor column (left or right hand side) we are drawing, and copy it to rowColors_Temporary
    switch (columnIterator) {
      case 0:
        columnNumber = 1;
        memcpy(rowColors_Temporary, rowColors_LeftHandSide, sizeof(rowColors_LeftHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
      case 1:
        columnNumber = 4;
        memcpy(rowColors_Temporary, rowColors_RightHandSide, sizeof(rowColors_RightHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
    }

    //Prints the column header
    myGLCD.setFont(SmallFont);
    myGLCD.setBackColor(0, 0, 0);
    myGLCD.setColor(255, 255, 255);
    myGLCD.print(F("Sens"), xIdent + (columnNumber - 1) * (boxWidth + xSpacing + boxExtraWidth) + 6, yHeader - 20);

    //Draws the cells
    for (uint8_t count = 0; count < 4; count++) {
      sprintf (sensorLabel, "S%d", count + 1 + 4 * (columnIterator)); //Gets the correct sensor numbering based on the column being ploted: sumns 4 in all cells from the right hand side column.
      myGLCD.setFont(BigFont);
      myGLCD.setColor(rowColors_Temporary[count][0], rowColors_Temporary[count][1], rowColors_Temporary[count][2]); // Sets color of the given line
      myGLCD.fillRect (xIdent + (columnNumber - 1)*cells_Xparameter, yHeader + count * cells_Yparameter, xIdent + boxWidth + (columnNumber - 1) * (cells_Xparameter), yHeader + boxHeight + count * cells_Yparameter); // Draws filled rectangle
      myGLCD.setBackColor(rowColors_Temporary[count][0], rowColors_Temporary[count][1], rowColors_Temporary[count][2]); // Sets color of the given line
      myGLCD.setColor(255, 255, 255);
      myGLCD.print(sensorLabel, xIdent + (columnNumber - 1)*cells_Xparameter + 5, yHeader + 7 + cells_Yparameter * count);
    }
  }

  char columnTitle[8];

  //Prints the Temperature and Humidity columns
  for (uint8_t columnIterator = 0; columnIterator < 4; columnIterator++) {
    //This columnNumber parameter follows the same logic as explained on the previous for loop
    switch (columnIterator) {
      case 0:
        columnNumber = 2;
        strcpy(columnTitle, "Temp(C)");
        memcpy(rowColors_Temporary, rowColors_LeftHandSide, sizeof(rowColors_LeftHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
      case 1:
        columnNumber = 3;
        strcpy(columnTitle, " RH(%) ");
        memcpy(rowColors_Temporary, rowColors_LeftHandSide, sizeof(rowColors_LeftHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
      case 2:
        columnNumber = 5;
        strcpy(columnTitle, "Temp(C)");
        memcpy(rowColors_Temporary, rowColors_RightHandSide, sizeof(rowColors_RightHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
      case 3:
        columnNumber = 6;
        strcpy(columnTitle, " RH(%) ");
        memcpy(rowColors_Temporary, rowColors_RightHandSide, sizeof(rowColors_RightHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
    }

    //Prints the column header
    myGLCD.setFont(SmallFont);
    myGLCD.setBackColor(0, 0, 0); // Sets color of the given line
    myGLCD.print(columnTitle, xIdent + (columnNumber - 1)*cells_Xparameter - boxExtraWidth, yHeader - 20);

    //Draws the cells
    for (uint8_t count = 0; count < 4; count++) {
      myGLCD.setFont(BigFont);
      myGLCD.setColor(rowColors_Temporary[count][0], rowColors_Temporary[count][1], rowColors_Temporary[count][2]); // Sets color of the given line
      myGLCD.fillRect (xIdent + (columnNumber - 1) * (cells_Xparameter) - boxExtraWidth, yHeader + cells_Yparameter * count, xIdent + (columnNumber - 1) * (cells_Xparameter)+boxWidth, yHeader + boxHeight + cells_Yparameter * count); // Draws filled rectangle
      myGLCD.setBackColor(rowColors_Temporary[count][0], rowColors_Temporary[count][1], rowColors_Temporary[count][2]); // Sets color of the given line
      myGLCD.setColor(255, 255, 255);
      //myGLCD.print(sensorLabel, xIdent + 5, (yHeader + 7) + (boxHeight + ySpacing)*count);
    }
  }
}
