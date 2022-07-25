/*
            |------------------------------------------------|
            |             CHORIZOMETRO CONTROLLER            |
            |libraries to install: LiquidCrystal, DHT, EEPROM|
            |             BY: Lucas Kruger                   |
            |------------------------------------------------|

INTENT: This script is intended to be used as a controller for a chorizo creation.
The idea is to have a simple interface to control the space temperature abd humidity.

*/

// ------------- Includes -------------------
#include "src/includes.h"

// ------------- Defines --------------------

#define DHTPIN 13
#define DHTTYPE DHT22

// ------------- Declarations ---------------
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); // LCD pins

DHT dht(DHTPIN, DHTTYPE); // DHT pins

// We define the menu screens here

// main screen
Status statusScreen("T:    C |       ",
                    "H:    % |       ");

// set screens
Seter tempSeter(1, 1, 50, 1, "  <-- TEMP: --> ");
Seter varTempSeter(2, 1, 20, 1, "<-- VAR TEMP:-->");
Seter humSeter(3, 10, 99, 1, "  <-- HUM: -->  ");
Seter varHumSeter(4, 1, 30, 1, "<-- VAR HUM:-->:");

// last print screen
PrintScreen printScreen("    TE AMO PA!  ",
                        "Chorizometro V1.");

// array of screen poeinters
Screens *screens[6] = {(Screens *)&statusScreen, (Screens *)&tempSeter, (Screens *)&varTempSeter, (Screens *)&humSeter, (Screens *)&varHumSeter, (Screens *)&printScreen};

// we create the menu
Menu menu(screens);

int relay[4] = {2, 3, 11, 12};                             // relay pins
int readData, valTemp, varTemp, valHum, varHum, temp, hum; // some variables

// ====================== SETUP ========================
void setup()
{

  Serial.begin(9600);

  lcd.begin(16, 2); // lcd initialization

  dht.begin(); // dht initialization

  // RELAY 1 PIN 3
  pinMode(relay[0], OUTPUT);
  // RELAY 2 PIN 4
  pinMode(relay[1], OUTPUT);
  // RELAY 3 PIN 5
  pinMode(relay[2], OUTPUT);
  // RELAY 4 PIN 6
  pinMode(relay[3], OUTPUT);
}

// ====================== LOOP =========================
void loop()
{
  // get data from dht sensor
  hum = (int)dht.readHumidity();
  temp = (int)dht.readTemperature();

  // get data from buttons and take action on menu
  keyboardActionWith(menu);

  // show the menu screen on lcd
  menu.show((int)temp, (int)hum, lcd);

  // get data saved in menu's screens
  menu.getTempValues(valTemp, varTemp);
  menu.getHumValues(valHum, varHum);

  // use the values to set the relays
  setRelays(temp, valTemp, varTemp, hum, valHum, varHum);
  delay(200);
}
