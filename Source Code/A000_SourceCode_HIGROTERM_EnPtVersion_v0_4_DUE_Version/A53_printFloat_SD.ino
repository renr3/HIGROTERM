/*
 * Function made to facilitate the printing of a float value in the log file.
 */


void printFloat_SD (float t) { //Print a float value to the log file
  char str_temp[6];
  char tTemp[6];
  /* 4 is mininum width, 2 is precision; float value is copied onto str_temp*/
  dtostrf(t, 4, 2, str_temp);
  sprintf(tTemp, "%s", str_temp);
  file.print(tTemp);
}
