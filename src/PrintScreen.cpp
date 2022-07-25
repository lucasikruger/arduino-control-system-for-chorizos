#include "PrintScreen.h" // We implement the Status class

/* =====================================================

  This code implement all the functions of the PrintScreen class.

======================================================*/

// -------------------------------------------

PrintScreen::PrintScreen(char *firstText, char *secondText) : _firstText(firstText), _secondText(secondText){};

// -------------------------------------------
void PrintScreen::show(int temp, int hum, LiquidCrystal &lcd, int valTemp, int varTemp, int valHum, int varHum)
{
  // print screen
  lcd.setCursor(0, 0);
  lcd.print(_firstText);
  lcd.setCursor(0, 1);
  lcd.print(_secondText);
}
// -------------------------------------------
