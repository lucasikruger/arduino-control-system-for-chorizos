# CHORIZOMETRO CONTROLLER V1.

This personal project is to create a humidity and temperature controller for Argentinian chorizo preparation.# Where to run the project

The project was thought to be used in an Arduino UNO.
The electronic components used were:

- Shield with Keypad + Pantalla LCD 16x2
- DHT 22
- 4 Relays module

# MAIN FUNCTIONs

It will control the temperature and the humidity via two values.
The value and the variation.
The variation avoids that the relay turns on/off all the time.
For example: Temp: 20 Var: 5 Actual Temp: 30
The relay for the cold unit is activated up to Actual Temp: 20. It starts again when Actual Temp > Temp+Var. 
We will use cold/heat to control temperature and air/steam to control humidity.

![alt text](https://github.com/lucasikruger/arduino-control-system-for-chorizos/blob/main/chorizometro.jpeg?raw=true)
