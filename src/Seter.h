#ifndef SETER_DEF

#define SETER_DEF
#include <EEPROM.h>
#include "Screens.h" // This class is herited from Screens

/* =====================================================

  This code defines the specification of the Seter class.
  It's intent is to be an screen where you can set a value
  between a min and a max.
  It can also define an step to change the value.
  It has the show funtion to show the value on the LCD.

======================================================*/

class Seter : public Screens
{
public:
  Seter(int EEPROMvalue, int minValue, int maxValue, int stepValue, char* texts); // Constructor

  void up(); // Function to increase the value

  void down(); // Function to decrease the value

  int value(); // Function to return the value

  void show(int temp, int hum, LiquidCrystal &lcd,int valTemp, int varTemp, int valHum, int varHum); // Function to show the screen on the LCD

private:
  // vars:
  int _EEPROMvalue, _maxValue, _minValue, _stepValue, _value; // vars to store the values of the Seter
  char* _texts;                                             // Array of strings to show on the LCD
  // functions:
  void addToValueInBounds(int stepValue); // Function to add to the value in bounds
  int _max(int aValue, int anotherValue);
  int _min(int aValue, int anotherValue);
};

#endif
