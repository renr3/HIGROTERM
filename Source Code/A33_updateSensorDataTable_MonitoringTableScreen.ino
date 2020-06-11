/*
   This function updates the readings of currently active sensors on the Sensor Data Table outline at the Monitoring Table Screen

   The table is represented as: Sensor|Temperature|RH || Sensor|Temperature|RH,
   with a total of four rows on each side of the table.
   This allows representing 8 sensor datas.

   The rows associated with connected sensors receive a red coloured background.
*/

//Update sensor table with the latest sensor values

void updateSensorDataTable_MonitoringTableScreen () {
  //Draw Sensor data boxes - First column for sensor labels
  // Graphical variables
  uint8_t xIdent = 13;
  uint8_t yHeader = 88;
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
  
  uint8_t columnNumber = 0;
  
  //Prints the Temperature and Humidity updated readings
  for (uint8_t columnIterator = 0; columnIterator < 4; columnIterator++) {
    //This columnNumber parameter follows the same logic as explained on the previous for loop
    switch (columnIterator) {
      case 0:
        columnNumber = 2;
        //memcpy(rowColors_Temporary, rowColors_LeftHandSide, sizeof(rowColors_LeftHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
      case 1:
        columnNumber = 3;
        //memcpy(rowColors_Temporary, rowColors_LeftHandSide, sizeof(rowColors_LeftHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
      case 2:
        columnNumber = 5;
        //memcpy(rowColors_Temporary, rowColors_RightHandSide, sizeof(rowColors_RightHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
      case 3:
        columnNumber = 6;
        //memcpy(rowColors_Temporary, rowColors_RightHandSide, sizeof(rowColors_RightHandSide[0]) * 4); //the memcpy function serves to copy an entire array into another
        break;
    }

    //Draws the cells
    for (uint8_t count = 0; count < 4; count++) {
      myGLCD.setFont(SmallFont);
    if (selectedChannels[count] == 1) {
      myGLCD.setColor(255, 255, 255); // Sets color of the given line
      myGLCD.setBackColor(255, 0, 0); // Sets color of the given line
      myGLCD.printNumF(t1[count], 2,xIdent+(columnNumber-1)*(cells_Xparameter)-boxExtraWidth,yHeader+cells_Yparameter*count, ',', 4); // Draws filled rectangle
    } else {
      //dont nothing
    }
    }
  }
}


