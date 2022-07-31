#include "Seter.h" // We implement the Seter class

/* =====================================================

  This code implement all the functions of the Seter class.

======================================================*/

Seter::Seter(int EEPROMvalue, int minValue, int maxValue, int stepValue, char *texts)
{
  _EEPROMvalue = EEPROMvalue;
  _minValue = minValue;
  _maxValue = maxValue;
  _stepValue = stepValue;
  _texts = texts;
  _value = EEPROM.read(_EEPROMvalue);
  this->addToValueInBounds(0);
};
// ---------------------------------------------------

void Seter::up()
{
  this->addToValueInBounds(_stepValue);
}

// ---------------------------------------------------

void Seter::down()
{
  this->addToValueInBounds(_stepValue * (-1));
}

// ---------------------------------------------------

void Seter::addToValueInBounds(int stepValue)
{

  int temp_value = 0;

  // Add the stepValue to the value between the min and max values
  temp_value = _min(_maxValue, (_value + stepValue));
  temp_value = _max(_minValue, temp_value);

  // If the value is different than the previous one, save it in the EEPROM
  if (temp_value != _value)
    EEPROM.write(_EEPROMvalue, temp_value);
  _value = temp_value;
}

// ---------------------------------------------------

int Seter::_min(int aValue, int anotherValue)
{
  int result = 0;
  if (aValue <= anotherValue)
    result = aValue;
  else
    result = anotherValue;

  return result;
}

// ---------------------------------------------------

int Seter::_max(int aValue, int anotherValue)
{
  int result = 0;
  if (aValue >= (anotherValue))
    result = aValue;

  else
    result = anotherValue;

  return result;
}

// ---------------------------------------------------

int Seter::value()
{
  return _value;
}

// ---------------------------------------------------

void Seter::show(int temp, int hum, LiquidCrystal &lcd, int valTemp, int varTemp, int valHum, int varHum)
{
  // print screen
  lcd.setCursor(0, 0);
  lcd.print(_texts);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(7, 1);
  lcd.print(_value);
}
