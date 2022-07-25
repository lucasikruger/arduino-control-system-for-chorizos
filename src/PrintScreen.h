#ifndef PRINTSCREEN_DEF

#define PRINTSCREEN_DEF

#include "Screens.h" // This class is herited from Screens

/* =====================================================

  This code defines the specification of the Print class.
  It's intent is to be an screen that shows information
  a simple message.

======================================================*/

class PrintScreen : public Screens
{
public:
  PrintScreen(char *firstText, char *secondText);
  void show(int temp, int hum, LiquidCrystal &lcd, int valTemp, int varTemp, int valHum, int varHum);

private:
  char *_firstText;  // first text to show
  char *_secondText; // second text to show
};
#endif
