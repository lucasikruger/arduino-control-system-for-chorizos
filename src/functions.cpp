#include "functions.h"

// -------------------------------------------
void keyboardActionWith(Menu &menu)
{
  int x;
  x = analogRead(0);

  if (x < 60)
  { // right
    menu.right();
  }
  else if (x < 200)
  { // up
    menu.up();
  }
  else if (x < 400)
  { // down
    menu.down();
  }
  else if (x < 600)
  { // left
    menu.left();
  }
}

// -------------------------------------------

void setRelays(int temp, int valTemp, int varTemp, int hum, int valHum, int varHum)
{
  int relay[4] = {2, 3, 11, 12};
  // Temp relays
  if (temp < (valTemp - varTemp)) // if temp is lower
  {
    digitalWrite(relay[0], LOW);
    digitalWrite(relay[1], HIGH);
  }
  if (temp > (valTemp + varTemp)) // higher
  {
    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[1], LOW);
  }
  if (temp >= (valTemp - varTemp) && temp <= (valTemp + varTemp)) // in range
  {
    digitalWrite(relay[0], HIGH);
    digitalWrite(relay[1], HIGH);
  }

  // Hum relays
  if (hum < (valHum - varHum)) // if hum is lower
  {
    digitalWrite(relay[2], LOW);
    digitalWrite(relay[3], HIGH);
  }
  if (hum > (valHum + varHum)) // higher
  {
    digitalWrite(relay[2], HIGH);
    digitalWrite(relay[3], LOW);
  }
  if (hum >= (valHum - varHum) && hum <= (valHum + varHum)) // in range
  {
    digitalWrite(relay[2], HIGH);
    digitalWrite(relay[3], HIGH);
  }
}
