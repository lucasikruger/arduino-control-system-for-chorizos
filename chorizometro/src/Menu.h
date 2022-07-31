#ifndef MENU_DEF

#define MENU_DEF
#include "Status.h"
#include "Seter.h"
#include "PrintScreen.h"

/* ==================================================

    This code defines the class Menu
    It is a specification for menu's implementation.
    Its intent is to manage the screens of the system.

===================================================*/

class Menu
{
public:
  Menu(Screens **screens); // Constructor
  void up();
  void down();
  void left();
  void right();
  void show(int temp, int hum, LiquidCrystal &lcd);
  void getTempValues(int &valTemp, int &varTemp);
  void getHumValues(int &valTemp, int &varTemp);

private:
  Screens **_screens;
  int _currentScreen = 0;
};

#endif
