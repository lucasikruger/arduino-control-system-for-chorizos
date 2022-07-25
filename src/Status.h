#ifndef STATUS_DEF

#define STATUS_DEF

#include "Screens.h" // This class is herited from Screens

/* =====================================================

  This code defines the specification of the Status class.
  It's intent is to be an screen that shows information
  about the system such as the temperature and the humidity.

======================================================*/

class Status : public Screens
{
public:
  Status(char *firstText, char *secondText);
  void show(int temp, int hum, LiquidCrystal &lcd, int valTemp, int varTemp, int valHum, int varHum);

private:
  char *_firstText;  // First line of the screen
  char *_secondText; // Second line of the screen
};
#endif
