#include "Menu.h" // We implement the Menu class

/* =====================================================

  This code implement all the functions of the Menu class.

======================================================*/

// -------------------------------------------
Menu::Menu(Screens **screens) : _screens(screens){};

// -------------------------------------------

void Menu::up()
{
  _screens[_currentScreen]->up();
}

// -------------------------------------------

void Menu::down()
{
  _screens[_currentScreen]->down();
}

// -------------------------------------------

void Menu::left()
{
  _currentScreen = (_currentScreen + 6 - 1) % 6;
}

// -------------------------------------------

void Menu::right()
{
  _currentScreen = (_currentScreen + 1) % 6;
}

// -------------------------------------------

void Menu::show(int temp, int hum, LiquidCrystal &lcd)
{
  int valTemp = _screens[1]->value();
  int varTemp = _screens[2]->value();
  int valHum = _screens[3]->value();
  int varHum = _screens[4]->value();
  _screens[_currentScreen]->show(temp, hum, lcd, valTemp, varTemp, valHum, varHum);
}

// -------------------------------------------
void Menu::getTempValues(int &valTemp, int &varTemp)
{

  valTemp = _screens[1]->value();
  varTemp = _screens[2]->value();
}

// -------------------------------------------
void Menu::getHumValues(int &valHum, int &varHum)
{

  valHum = _screens[3]->value();
  varHum = _screens[4]->value();
}
