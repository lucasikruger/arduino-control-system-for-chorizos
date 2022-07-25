#ifndef SCREENS_DEF

#define SCREENS_DEF

#include <LiquidCrystal.h> // We will use the LiquidCrystal library

/* ==================================================

    This code defines the superclass Screens.
    It is a specification for screen's implementation.

===================================================*/

class Screens
{
public:
  // Every screen has to know the LCD object and
  // implement the next functions.
  void virtual up() {};
  void virtual down() {};
  void virtual show(int temp, int hum, LiquidCrystal &lcd,int valTemp, int varTemp, int valHum, int varHum) {};
  int virtual value() {};
};

#endif
