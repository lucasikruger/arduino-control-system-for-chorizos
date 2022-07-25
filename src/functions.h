#ifndef FUNC_DEF

#define FUNC_DEF

#include "Menu.h"
#include "Arduino.h"

// Define all the functions we'll use

void keyboardActionWith(Menu &menu);
void setRelays(int temp, int valTemp, int varTemp, int hum, int valHum, int varHum);

#endif
