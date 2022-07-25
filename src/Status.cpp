#include "Status.h" // We implement the Status class

/* =====================================================

  This code implement all the functions of the Status class.

======================================================*/

// -------------------------------------------

Status::Status(char *firstText, char *secondText) : _firstText(firstText), _secondText(secondText){};

// -------------------------------------------
void Status::show(int temp, int hum, LiquidCrystal &lcd, int valTemp, int varTemp, int valHum, int varHum)
{

  // print screen
  lcd.setCursor(0, 0);
  lcd.print(_firstText);
  lcd.setCursor(0, 1);
  lcd.print(_secondText);

  // print values
  lcd.setCursor(3, 0);
  lcd.print(temp);

  lcd.setCursor(3, 1);
  lcd.print(hum);

  // Print the state of the relays and the relation between values
  char *tempChar = "  [ok]";
  if (temp < (valTemp - varTemp))
    tempChar = "+[BAJA]";
  else if (temp > (valTemp + varTemp))
    tempChar = "-[ALTA]";

  lcd.setCursor(9, 0);
  lcd.print(tempChar);

  char *humChar = "  [ok]";
  if (hum < (valHum - varHum))
    humChar = "+[BAJA]";
  else if (hum > (valHum + varHum))
    humChar = "-[ALTA]";
  lcd.setCursor(9, 1);
  lcd.print(humChar);
}
// -------------------------------------------
