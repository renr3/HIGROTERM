#/*
 * These functions were added on v0.3: 
 * They handle invalid readings querried from RTC Clock. Such invalid readings might occur if RTC is badly wired, or not wired at all, which outputs spurious numbers when querried.
 */


void validateTimeContainers(byte *hoursTens, byte *hoursUnits, byte *minutesTens, byte *minutesUnits, byte *secondsTens, byte *secondsUnits){
  if (*hoursTens>2){
    *hoursTens=0;
  }
  if (*hoursUnits>9){
    *hoursUnits=0;
  }
  if (*minutesTens>5){
    *minutesTens=0;
  }
  if (*minutesUnits>9){
    *minutesUnits=0;
  }
  if (*secondsTens>5){
    *secondsTens=0;
  }
  if (*secondsUnits>9){
    *secondsUnits=0;
  }
}

//Added on v0.3: Handling invalid readings querried from RTC Clock. They might occur if RTC is badly wired, or no wired at all, which outputs spurious numbers when querried
void validateDateContainers(byte *daysTens, byte *daysUnits, byte *monthsTens, byte *monthsUnits, byte *yearsTens, byte *yearsUnits){
  if (*daysTens>3){
    *daysTens=0;
  }
  if (*daysUnits>9){
    *daysUnits=0;
  }
  if (*monthsTens>1){
    *monthsTens=0;
  }
  if (*monthsUnits>9){
    *monthsUnits=0;
  }
  if (*yearsTens>9){
    *yearsTens=0;
  }
  if (*yearsUnits>9){
    *yearsUnits=0;
  }
}
