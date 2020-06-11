
/*  HIGROTERM SYSTEM
     Developed by Renan Ribeiro, in the Graduate program in Structures and Civil Construction
     at the University of Brasília, Brasília-DF-Brazil.
     Current version: 0.4
    ===============================
    Version 0.1:
    - Release version;
    Version 0.2:
    - Added dual language option, based on variable byte language.
    - Added setting time and damage from within the system
    Version 0.3:
    - ################  THIS VERSION IS FOR THE PAPER WRITING ONLY. IT WAS MODIFIED IN THE FUNCTION initialize_SD TO BYPASS ITS VERFICATION ################ 
    - Fixing handling invalid RTC Clock configuration (which may occurs when it is badly wired) that would print 2 digits in each house
    Version 0.4:
    - Breaking up of the source code into multiple header files
    - Total of lines (except icons and fonts): 2389
    - With icons: 3188
    ===============================
    Implementation notes:
   The page indexing, to be used to facilitate the screen update, is based on
   the variable currentPage. On the present implementation, the following table
   is followed:
    -currentPage = 0: Initial screen
    -currentPage = 1: Loading screen
    -currentPage = 2: Monitoring Table screen
    -currentPage = 3: Configuration screen
    ===============================
    TODO LIST:
    -TODO 1: In void closeFile_SD(){...} - implement conditions to deal with unsuccessful .close method. Check SdFat.h to know more about the .close method and its returns.
    -TODO 2: In void readTemp_DHT(){...} and readHum_DHT(){...) - implement a check/message to deal with the issue when a sensor can not be read after 10 tries
    -TODO 3: In void initialize_SD(){...} - Implement SD card initialization in Monitoring Table Screen. Right now, it is just performed on Loading Screen. If you disconnect the SD card, you need to run Loading Screen again by using the Configuration Screen.
    -TODO 4: Separate the icons bitmaps into an external .c file #Implemented on v0.4
    -TODO 5: Account for leap year (in: drawSetClockScreen()) 
    -TODO 6: Implement a live graphic version of MonitoringTableScreen, so the user can see the evolution of the variables during sampling
    -TODO 7: Implement !file.sync() method in the logData_SD function, so to prevent the system from losing data due to power loss
  //
    ===============================
    Ackowledgements:
    -This sketch uses the UTFT and URTouch libraries made by Henning Karlsen. You can find and download them at: www.RinkyDinkElectronics.com
    -This sketch is based on "Arduino TFT Tutorial Program" made by Dejan Nedelkovski. You can find it in: www.HowToMechatronics.com
    -This sketch uses parts of "Simple data logger example" from SdFat.h library. You can find it in  https://github.com/greiman/SdFat/archive/master.zip
*/

//Since UTFT and URTouch libraries use BY-NC-SA Version 3.0, this software may be released only under BY-NC-SA Version 3.0 or later
//https://creativecommons.org/licenses/by-nc-sa/3.0/
//https://creativecommons.org/licenses/by-nc-sa/4.0/


//=========== Importing libraries
#include <UTFT.h> //CC BY-NC-SA 3.0
#include <URTouch.h> //CC BY-NC-SA 3.0
#include <SPI.h> //GNU GENERAL PUBLIC LICENSE
#include <SdFat.h> //MIT License
#include <uRTCLib.h>//GNU LESSER GENERAL PUBLIC LICENSE
#include <Wire.h> //GNU GENERAL PUBLIC LICENSE
#include <DHT.h> //MIT License
#include <avr/dtostrf.h> //Necessary so this code can be used in Arduino DUE as well, in which the dtostrf.h is not natively available
#include <avr/pgmspace.h> //Necessary in order to plot bitmaps in Arduinos other than Arduino Due

//=========== DHT definitions
#define DHTPIN1 8 //Sensor 1 pin
#define DHTPIN2 9 //Sensor 2 pin   
#define DHTPIN3 10 //Sensor 3 pin   
#define DHTPIN4 11 //Sensor 4 pin  
#define DHTPIN5 12 //Sensor 5 pin   
#define DHTPIN6 13 //Sensor 6 pin  
#define DHTPIN7 14 //Sensor 7 pin   
#define DHTPIN8 15 //Sensor 8 pin
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dhtSensor[] = {DHT(DHTPIN1, DHTTYPE), DHT(DHTPIN2, DHTTYPE), DHT(DHTPIN3, DHTTYPE), DHT(DHTPIN4, DHTTYPE), DHT(DHTPIN5, DHTTYPE), DHT(DHTPIN6, DHTTYPE), DHT(DHTPIN7, DHTTYPE), DHT(DHTPIN8, DHTTYPE)};
float t1[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; //Variables to store current temperature measured. This is used to receive sensor data and display values in the table.
float h1[8] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; //Variables to store current temperature measured. This is used to  receive sensor data and display values in the table.
byte selectedChannels[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //Sensor chanels. A "0" indicates channel is not selected/connected/used by the user. A 1 indicates the channel is selected/connected/used by the user

//=========== Display definitions
UTFT    myGLCD(ILI9341_16, 38, 39, 40, 41);
URTouch  myTouch( 6, 5, 4, 3, 2); 
byte currentPage; //Will store which page we are currently showing in the screen
uint8_t recording = 0; //Will indicate whether we are storing/recording sensor data in the SD card
int x, y; //Variables for touch screen coordinates when pressed
byte language = 0; //Variable to indicate display language: 0 - English; 1 -  Portuguese; ...
byte configureFlag = 0; //Flag that indicates what to do after visiting the Configuration Screen

//=========== Import external fonts and bitmaps
//Fonts
extern uint8_t SmallFont[]; //Importing font.
extern uint8_t BigFont[]; //Importing font.
extern uint8_t SevenSegNumFont[]; //Importing font.
extern uint8_t GroteskBold32x64[]; //Importing font.
extern uint8_t Various_Symbols_32x32[]; //Importing font.
//Bitmaps
extern uint16_t img_home2_png[] ;
extern uint16_t img_brazilFlag_png[];
extern uint16_t img_ukFlag_png[];
extern uint16_t img_clock_png[];
extern uint16_t img_home2_Inactive_png[];
extern uint16_t img_turnOff_png[];
extern uint16_t img_turnOff_Inactive_png[];
extern uint16_t img_clock_Inactive_png[];
extern uint16_t img_saveandreturn_png[];
extern uint16_t img_return_png[];
extern uint16_t img_saveandreturn_Inactive_png[];
extern uint16_t img_return_Inactive_png[];

//=========== Sampling frequency definitions
unsigned long time1 = 0; unsigned long time2 = 0; unsigned long timeUpdate = 0; //Variables to set the sampling frequency
unsigned long fs = 150000; //CHECK THIS COMMENT: Time between consecutive measurements. Default sampling frequency is 2.5 minutes. It is not sampling frequency per se, but the time elapsed between two consecutive reads, in milliseconds

//=========== Clock definitions
uRTCLib rtc(0x68); //Instancing RTC clock object
//Variables to store time and data and each decimal place (tens and units)
byte hours = 0; byte minutes = 0; byte seconds = 0; byte days = 0; byte months = 0; byte years = 0;
byte hoursTens = 0; byte hoursUnits = 0; byte minutesTens = 0; byte minutesUnits = 0; byte secondsTens = 0; byte secondsUnits = 0;
byte daysTens = 0; byte daysUnits = 0; byte monthsTens = 0; byte monthsUnits = 0; byte yearsTens = 0; byte yearsUnits = 0;

//=========== SD card definitions
#define SD_CHIP_SELECT  53  // SD chip select pin
SdFat sd; //Instancing SD object
SdFile file; //Creating log file
#define FILE_BASE_NAME "Data" // Log file base name, i.e. "Data" will be the prefix of all data files, e.g. "Data01.csv", "Data02.csv", etc.  Must be no more than six characters
const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1; //This is to assure a size less than six characters
char fileName[13] = FILE_BASE_NAME "00.csv"; //Building the first log file name
byte openFile_SDStatus = 0; //Assumes 0 or 1 if file could or could not be opened, respectively. To receive the return from openFile_SD() function

//=========== Log table prompt at Monitoring Table Screen
byte dataLogConsole_MonitoringTableScreen_State = 0; //Shows how many lines have been fed to Data Log Console, on the Monitoring Table Screen, to allow automatic scrolling from past lines to free display space for new text
char dataLogTable1[27] = "01:                      "; //Message 1 in the data log screen (Monitoring Table)
char dataLogTable2[27] = "02:                      "; //Message 2 in the data log screen (Monitoring Table)
char dataLogTable3[27] = "03:                      "; //Message 3s in the data log screen (Monitoring Table)

//=========== Definitions of button areas at touchscreen
//Record and Stop button at Monitoring Table Screen
const int recordStopBut_MonitTabScren_Xmin = 7;
const int recordStopBut_MonitTabScren_Xmax = 45;
const int recordStopBut_MonitTabScren_Ymin = 13;
const int recordStopBut_MonitTabScren_Ymax = 51;

//Configuration button at Monitoring Table Screen
const int configBut_MonitTabScren_Xmin = 274;
const int configBut_MonitTabScren_Xmax = 312;
const int configBut_MonitTabScren_Ymin = 13;
const int configBut_MonitTabScren_Ymax = 51;

//OK button at Loading Screen
const int OKBut_LoadingScreen_Xmin = 239;
const int OKBut_LoadingScreen_Xmax = 319;
const int OKBut_LoadingScreen_Ymin = 159;
const int OKBut_LoadingScreen_Ymax = 239;

//"S1","S2","S3","S4","S5","S6","S7","S8" buttons at Loading Screen
const int sensorSelectionBut_LoadingScreen_Xwidth = 40;
const int sensorSelectionBut_LoadingScreen_Ymin = 95;
const int sensorSelectionBut_LoadingScreen_Ymax = 140;

//Home Screen button at Configuration Screen
const int HomeScreenBut_ConfigScreen_Xmin=135;
const int HomeScreenBut_ConfigScreen_Xmax=183;
const int HomeScreenBut_ConfigScreen_Ymin=116;
const int HomeScreenBut_ConfigScreen_Ymax=164;

//Turn Off button at Configuration Screen
const int TurnOffBut_ConfigScreen_Xmin=237;
const int TurnOffBut_ConfigScreen_Xmax=285;
const int TurnOffBut_ConfigScreen_Ymin=116;
const int TurnOffBut_ConfigScreen_Ymax=164;

//Reload button at Configuration Screen
const int ReloadBut_ConfigScreen_Xmin=33;
const int ReloadBut_ConfigScreen_Xmax=81;
const int ReloadBut_ConfigScreen_Ymin=116;
const int ReloadBut_ConfigScreen_Ymax=164;

//Set Clock/Date button at Configuration Screen
const int SetClockDateBut_ConfigScreen_Xmin=89;
const int SetClockDateBut_ConfigScreen_Xmax=119;
const int SetClockDateBut_ConfigScreen_Ymin=197;
const int SetClockDateBut_ConfigScreen_Ymax=227;

//Set Language button at Configuration Screen
const int SetLanguageBut_ConfigScreen_Xmin=182;
const int SetLanguageBut_ConfigScreen_Xmax=234;
const int SetLanguageBut_ConfigScreen_Ymin=194;
const int SetLanguageBut_ConfigScreen_Ymax=230;

void setup() {
  Serial.begin(115200); //At use we don't really need Serial. We can comment out this line.
  Wire.begin(); //Start wire to allow peripheral communications
  myGLCD.InitLCD(); //Start LCD
  myGLCD.clrScr(); //Clear LCD screen
  myTouch.InitTouch(); //Start touchscreen
  myTouch.setPrecision(PREC_HI); //Set touchscreen precision. Check URTouch documentation for further details about .setPrecision method.
  currentPage = 0; // Indicates that we are at Initial Screen,
  drawInitialScreen();  // Draws the Initial Screen
  drawLoadingScreen();  // Draws the Loading Screen
}

void loop() {
  if (currentPage != 2) { //The code will only get here if we came from another screen that is not the Monitoring Table Screen. Therefore, we need to initialize it. This is what this if-clause does
    drawMonitoringTableScreen(); //Draw the Monitoring Table Screen
    updateSensorData_DHT(); //It asks each sensor for current data, and update t1 and h1 variables.
    updateSensorDataTable_MonitoringTableScreen(); //Updates sensor table with the latest sensor values, taken from the last updateSensorData_DHT function
    timeUpdate = millis(); //Initializes this variable. The DataTable will only update again when [current millis()]-timeUpdate > fs, i.e. a time greater than fs, in miliseconds, has elapsed since the last table update
  } else { //Indicates we are at the Monitoring Table Screen
    if (myTouch.dataAvailable()) { //Read touch screen data, if available, to know if any command has been sent by the user
      myTouch.read(); //Method to read data from touch screen
      x = myTouch.getX(); // X coordinate where the screen has been pressed
      y = myTouch.getY(); // Y coordinates where the screen has been pressed
    }
    //If we pressed the Config Button, that will only work if recoring is off. (Move above recordStopBut check for better clarity)
    if ((x >= configBut_MonitTabScren_Xmin) && (x <= configBut_MonitTabScren_Xmax) && (y >= configBut_MonitTabScren_Ymin) && (y <= configBut_MonitTabScren_Ymax) && recording == 0) {//If we pressed the Configuration button
      drawConfigButton_Inactive_MonitoringTableScreen(); //Makes the Configuration button Inactive, so the user can't change configuration while logging, since such configuration will affect the logging
      delay(250); //Delay so one touch is not seen as multiple touches
      configureFlag = drawConfigurationScreen(); //Draw the Configuration Screen and store its return on "configureFlag" variable, which will indicate what to do after the user interact with the Configuration Screen
      if (configureFlag == 1) {//The Reload Connections button was pressed
        drawLoadingScreen();  // Draws the Loading Screen
      } else if (configureFlag == 2) {//The Home button was pressed
        drawMonitoringTableScreen(); //Draws the Monitoring Table Screen
      } else if (configureFlag == 3) {//The Turn Off button was pressed
        drawTurnOffScreen(); //It will just draw a black screen written: "You can turn off the device now"
        while (1); //System is going to be turned off. Just be here forever.
      } else if (configureFlag == 4) {//The Set Clock/Date button was pressed
        //drawSetClockScreen(); //It will draw the Set Clock/Date Screen
      }
    }
    if ((x >= recordStopBut_MonitTabScren_Xmin) && (x <= recordStopBut_MonitTabScren_Xmax) && (y >= recordStopBut_MonitTabScren_Ymin) && (y <= recordStopBut_MonitTabScren_Ymax) && recording == 0) {// If we pressed the Record Button
      drawStopButton_MonitoringTableScreen(); //Substitutes the Record button for the Stop button, that will allow stopping the data logging
      drawConfigButton_Inactive_MonitoringTableScreen(); //Makes the Configuration button Inactive, so the user can't change configuration while logging, since such configuration will affect the logging
      delay(250); //Delay so one touch is not seen as multiple touches
      recording = 1; //Updates the "recording" variable, indicating that the system is currently logging data
      resetTouch(); //Reset x and y variables so they can receive new input values
      openFile_SDStatus = openFile_SD(); //Check if file could be opened. Return 0 if file was successfully opened, or 1 if the file could not be opened/created
      if (openFile_SDStatus == 1) { //If the file could not be opened, execute these instructions to deal with the fact that logging could not be started
        recording = 0; //File could not be opened, do not let sampling proceed. A error message will be shown in the Data Log Console, in the appropriate field accordingly to the current screen
        drawRecordButton_MonitoringTableScreen(); //Draw record button again, so the user can try to start logging again after solving the issue with the SD card
      } else {//If the file could be opened, then execute this instruction...
        time1 = millis(); //Update "time1" variable. This variable will be used to know when the next data reading/logging will be done:
        timeUpdate = time1; //If we are in a recording session, we want the Monitoring Table Screen to be updated at the same instant the SD card is logged with new data.
        //the sensor data will only be read and stored again when [current millis()]- time1 > fs, i.e. a time greater than fs, in miliseconds, has elapsed since the last sensor reading/logging
      }
    }
    if ((x >= recordStopBut_MonitTabScren_Xmin) && (x <= recordStopBut_MonitTabScren_Xmax) && (y >= recordStopBut_MonitTabScren_Ymin) && (y <= recordStopBut_MonitTabScren_Ymax) && recording == 1) {//If we pressed the Stop Button
      recording = 0; //Updates the "recording" variable, indicating that the system is not logging data
      drawRecordButton_MonitoringTableScreen(); //Substitutes the Stop button by the Record button
      drawConfigButton_MonitoringTableScreen(); //Draws the Configuration button again, allowing the user to access the Configuration Screen since the logging has stoppped
      delay(250); //Delay so one touch is not seen as multiple touches
      resetTouch(); //Reset x and y variables so they can receive new input values
      closeFile_SD (); //Close the data log file
      findFileName_SD(); //Find the next available file name, or deal with the fact that the file could not be named.
    }


    time2 = millis(); //Store current time on "time2" variable
    if (recording == 1) {//To be performed if the system is under recording (recording==1)
      if (time2 - time1 > fs) {//If the difference between the current time, stored in "time2", and the time when the data was last read/logged, stored in "time1", is higher than "fs", the time between measurements,
        //then perform a data read/log
        logData_SD(); //Logs sensor data
        time1 = millis(); //Updates the "time1" variable to store the time when the system last read/logged data.
      }
    }
    if (time2 - timeUpdate > fs) { //If the difference between the current time, stored in "time2", and the time when the Monitoring Table was last updated, stored in "timeUpdate", is higher than "fs", the time between measurements,
      //then update the Monitoring Table
      updateSensorData_DHT(); //Read sensor data, updating variables t1 and h1
      updateSensorDataTable_MonitoringTableScreen (); //Updates the Monitoring Table, writing the current values of t1 and h1
      timeUpdate = millis(); //Updates the "timeUpdate" variable to store the time when the system last updated the Monitoring Table
    }
  }
}
