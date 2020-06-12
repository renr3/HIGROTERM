/* This function updates information on the Data Log Console on the Monitoring Table Screen
 * This function was created to handle the lines in the Data Log Console in the Monitoring Table Screen. 
 * When the console space is full and a new line must be shown, then a "scrolling" method has to be performed, eliminating the 
 * oldest line, on the top, moving the previous printed lines one position above, and printing the new line on the bottom. 
 * This scrolling is handled by the char arrays dataLogTable1, dataLogTable2 and dataLogTable3, that are responsible for 
 * storing the texts to be shown on each line. They are subsequently updated when a new line needs to be show on the 
 * Data Log Console in the Monitoring Table Screen. 
 * The following switch structure handles the case when: (i) only one line has been shown; (ii) two lines has been shown;
 * (iii) three lines has been shown; (iv) more than three lines has been shown, i.e. the data log text list is full.
 * 
 */

void dataLogConsole_MonitoringTableScreen (char message[24]) {//
  switch (dataLogConsole_MonitoringTableScreen_State) {
    case 0://Just to initialize
      dataLogConsole_MonitoringTableScreen_State++;
      break;
    case 1://This is the first message to be ploted on the Data Log Console
      for (byte ii = 0; ii < 23; ii++) {
        dataLogTable1[ii + 3] = message[ii];
      }
      dataLogConsole_MonitoringTableScreen_State++;
      break;
    case 2://This is the second message to be ploted on the Data Log Console
      for (byte ii = 0; ii < 23; ii++) {
        dataLogTable2[ii + 3] = message[ii];
      }
      dataLogConsole_MonitoringTableScreen_State++;
      break;
    case 3://This is the third message to be ploted on the Data Log Console. There is no free lines available anymore.
      for (byte ii = 0; ii < 23; ii++) {
        dataLogTable3[ii + 3] = message[ii];
      }
      dataLogConsole_MonitoringTableScreen_State++;
      break;
    default: //Data log text list is full. Need to update all of them. Perform the scroll procedure: eliminate the first line (which is the oldest), and 
             //pass each line below for one line above. Use the third line, which will then be free, to store the new message.
      char tempMessage[1];
      sprintf(tempMessage, "%0.2u", dataLogConsole_MonitoringTableScreen_State);
      dataLogTable1[0] = tempMessage[0];
      dataLogTable1[1] = tempMessage[1];
      for (byte ii = 0; ii < 23; ii++) {
        dataLogTable1[ii + 3] = dataLogTable2[ii + 3];
      }
      sprintf(tempMessage, "%0.2u", dataLogConsole_MonitoringTableScreen_State + 1);
      dataLogTable2[0] = tempMessage[0];
      dataLogTable2[1] = tempMessage[1];
      for (byte ii = 0; ii < 23; ii++) {
        dataLogTable2[ii + 3] = dataLogTable3[ii + 3];
      }
      sprintf(tempMessage, "%0.2u", dataLogConsole_MonitoringTableScreen_State + 2);
      dataLogTable3[0] = tempMessage[0];
      dataLogTable3[1] = tempMessage[1];
      for (byte ii = 0; ii < 23; ii++) {
        dataLogTable3[ii + 3] = message[ii];
      }
      dataLogConsole_MonitoringTableScreen_State++;
  }
  //Clear the data log:
  myGLCD.print(F("                          "), 53, 14);
  myGLCD.print(F("                          "), 53, 26);
  myGLCD.print(F("                          "), 53, 38);
  //Update the data log with the new set of messages.
  myGLCD.print(dataLogTable1, 53, 14);
  myGLCD.print(dataLogTable2, 53, 26);
  myGLCD.print(dataLogTable3, 53, 38);
}
